#include "MSFS_Interface.h"


//int __cdecl _tmain(int argc, _TCHAR* argv[]) {
 
 int MSFS_Interface(void* data) {

    data_ = (SharedData*)data;
    while (!reqExitSim) {

        DataRequest();
        Sleep(1000);

        while (reqWait) {
            std::cout << "Waiting";
            Sleep(1000);
        }
    }

    std::cout << endl << "GoodBye" << endl;
    return 0;
}


// ---------------------------------------------------------------------------------------------


void DataRequest() {

    //data_->UI_Status = true;

    HRESULT hr;
    if (SUCCEEDED(SimConnect_Open(&hSimConnect, "Request Data", NULL, 0, 0, 0))) {

        printf("\nConnected to Flight Simulator! \n");

        // Set up the data definition, but do not yet do anything with it
        hr = SimConnect_AddToDataDefinition(hSimConnect, SIMCONNECT_GROUP_PRIORITY_STANDARD, "Title", NULL, SIMCONNECT_DATATYPE_STRING256);
        hr = SimConnect_AddToDataDefinition(hSimConnect, SIMCONNECT_GROUP_PRIORITY_STANDARD, "Kohlsman setting hg", "inHg");
        hr = SimConnect_AddToDataDefinition(hSimConnect, SIMCONNECT_GROUP_PRIORITY_STANDARD, "Plane Altitude", "feet");
        hr = SimConnect_AddToDataDefinition(hSimConnect, SIMCONNECT_GROUP_PRIORITY_STANDARD, "Plane Latitude", "degrees");
        hr = SimConnect_AddToDataDefinition(hSimConnect, SIMCONNECT_GROUP_PRIORITY_STANDARD, "Plane Longitude", "degrees");

        hr = SimConnect_SubscribeToSystemEvent(hSimConnect, EVENT_SIM_1SEC, "1sec");
        hr = SimConnect_SubscribeToSystemEvent(hSimConnect, EVENT_SIM_STATE, "Sim");

        //hr = SimConnect_SubscribeToSystemEvent(hSimConnect, EVENT_SIM_PAUSE_STATE, "Pause");
        //hr = SimConnect_SubscribeToSystemEvent(hSimConnect, EVENT_SIM_FRAME, "Frame");


        printf("\nLaunch a flight. \n");
        while (0 == reqQuit) {
            SimConnect_CallDispatch(hSimConnect, MyDispatchProcRD, NULL);
            Sleep(1);
        //    if (UI_reqUpdate) {}
        }

        hr = SimConnect_Close(hSimConnect);
    }
    else {
        std::cout << "failed to connect to server \n";
    }

}


// -------------------------------------------------------------------------------------


void CALLBACK MyDispatchProcRD(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext)
{
    HRESULT hr;

    switch (pData->dwID)
    {
    case SIMCONNECT_RECV_ID_EVENT:
    {
        SIMCONNECT_RECV_EVENT* evt = (SIMCONNECT_RECV_EVENT*)pData;
        switch (evt->uEventID) {
    
        case EVENT_SIM_STATE:
        {
            if (evt->dwData == SIMCONNECT_STATE_ON) {
                //printf("\nReceived: SIM Start \n");
                // Now the sim is running, request information on the user aircraft
                //hr = SimConnect_RequestDataOnSimObjectType(hSimConnect, REQUEST_1, DEFINITION_1, 0, SIMCONNECT_SIMOBJECT_TYPE_USER);
                hr = SimConnect_RequestDataOnSimObject(hSimConnect, REQUEST_1, SIMCONNECT_GROUP_PRIORITY_STANDARD, SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_SECOND, SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);
                //std::cout << "hr status: " << hr << "\n";
                
            }
            else {
                printf("\nReceived: SIM Stop \n");
                hr = SimConnect_RequestDataOnSimObject(hSimConnect, REQUEST_1, SIMCONNECT_GROUP_PRIORITY_STANDARD, SIMCONNECT_OBJECT_ID_USER, SIMCONNECT_PERIOD_NEVER, SIMCONNECT_DATA_REQUEST_FLAG_CHANGED);
                //std::cout << "hr status: " << hr << "\n";
            }
            data_->UI_Status = evt->dwData;
            break;
        }

        case EVENT_SIM_PAUSE_STATE:
        {
            printf("\nReceived: EVENT_SIM_PAUSE_STATE -> ");
            if (evt->dwData == SIMCONNECT_STATE_ON)
                std::cout << "Paused";
            else
                std::cout << "UN-Paused";

            data_->UI_PauseStatus = evt->dwData;
            std::cout << "\n";
            break;
        }

        case EVENT_SIM_1SEC:
        {
            printf("\nReceived: EVENT_SIM_1SEC");
            //SimConnect_SetSystemEventState(hSimConnect, EVENT_SIM_FRAME, SIMCONNECT_STATE_ON);
            //SimConnect_SetSystemEventState(hSimConnect, EVENT_SIM_PAUSE_FRAME, SIMCONNECT_STATE_ON);

       //     std::cout << std::endl << "this is the string from the server: " << string_ << std::endl;
            //cout << "var = " <<  << endl;

            break;
        }


        default:
            break;
        }
        break;
    }

    case SIMCONNECT_RECV_ID_SIMOBJECT_DATA:
    {
        SIMCONNECT_RECV_SIMOBJECT_DATA* pObjData = (SIMCONNECT_RECV_SIMOBJECT_DATA*)pData;
        //std::cout << "\n" << "SIMCONNECT_RECV_ID_SIMOBJECT_DATA";
        switch (pObjData->dwRequestID)
        {
        case REQUEST_1:
        {
            DWORD ObjectID = pObjData->dwObjectID;
            Struct1* pS = (Struct1*)&pObjData->dwData;
            if (SUCCEEDED(StringCbLengthA(&pS->title[0], sizeof(pS->title), NULL))) // security check
            {
                printf("\nObjectID=%d  Title=\"%s\"\nLat=%f  Lon=%f  Alt=%f  Kohlsman=%.2f", ObjectID, pS->title, pS->latitude, pS->longitude, pS->altitude, pS->kohlsmann);
                std::cout << "\n";

                data_->UI_reqUpdate = true;
                data_->UI_latitude = pS->latitude;
                data_->UI_longitude = pS->longitude;
                data_->UI_altitude = pS->altitude;
                data_->UI_kohlsmann = pS->kohlsmann;

                //num_ = pS->altitude;
                //cout << "num_ = " << num_ << endl;
            }
            break;
        }

        default:
            break;
        }
        break;
    }

    case SIMCONNECT_RECV_ID_EVENT_FRAME:
    {
        if (pData->dwID == EVENT_SIM_FRAME) {
            SimConnect_SetSystemEventState(hSimConnect, EVENT_SIM_FRAME, SIMCONNECT_STATE_OFF);
            std::cout << "\n" << "frame rate = " << ((SIMCONNECT_RECV_EVENT_FRAME*)pData)->fFrameRate << "\n";
        }
        else {
            std::cout << "\n" << "EVENT_SIM_PAUSE_FRAME = " << ((SIMCONNECT_RECV_EVENT_FRAME*)pData)->dwData << "\n";
        }
        break;
    }

    case SIMCONNECT_RECV_ID_OPEN:
    {
        reqQuit = 0;
        //reqWait = false;
        printf("\nReceived: SIMCONNECT_RECV_ID_OPEN");
        break;
    }

    case SIMCONNECT_RECV_ID_QUIT:
    {
        reqQuit = 1;
        reqWait = false;
        reqExitSim = true;
        printf("\nReceived: SIMCONNECT_RECV_ID_QUIT");
        break;
    }

    case SIMCONNECT_RECV_ID_EXCEPTION:
    {
        printf("\nReceived: SIMCONNECT_RECV_ID_EXCEPTION = %d \n", pData->dwID);

        break;
    }

    default:
        printf("\ndefault Received:%d", pData->dwID);
        break;
    }
}

