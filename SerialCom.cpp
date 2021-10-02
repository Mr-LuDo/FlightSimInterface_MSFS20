#include "SerialCom.h"
#include <iostream>

#include "SimpleSerial.h"
#include "backEnd.h"

using std::cout;
using std::endl;

int SerialComunication(void* data) {

    SharedData* data_ = (SharedData*)data;

    char com_port[] = "\\\\.\\COM3";
    DWORD COM_BAUD_RATE = CBR_9600;
    SimpleSerial Serial(com_port, COM_BAUD_RATE);

    if (Serial.connected_) {
        cout << "connected" << endl;
    }

    DWORD bytes_read;
    char temp;
    char inc_msg[10] = "0";
    int pos = 0;
    //string complete_inc_msg;
    //bool began = false;
    bool msgEnded = false;
    DWORD dwEvtMask;
    int knobSize = 0;
    char tempChar[20] = "knob size =  \r\n";

    bool fSuccess = SetCommMask(Serial.io_handler_, EV_RXCHAR);

    while (true) {

        fSuccess = WaitCommEvent(Serial.io_handler_, &dwEvtMask, NULL);

        if (dwEvtMask == EV_RXCHAR) {

            while (!msgEnded) {
                if (ReadFile(Serial.io_handler_, &temp, 1, &bytes_read, NULL)) {
                    //cout << "received = " << temp << endl;
                    if (temp != '{' && temp != '}' && temp >= '0' && temp <= '9') {
                        inc_msg[pos] = temp;
                        ++pos;
                    }

                    if (temp == '}')
                        msgEnded = true;

                }
                else {
                    cout << "Warning: Failed to receive data." << endl;
                }

            }

        }
        else {
            cout << "event dwEvtMask != EV_RXCHAR" << endl;
            //continue;
        }

        if (msgEnded) {
            knobSize = std::stoi(inc_msg);

            //if(knobSize >= 0 && knobSize <= 9)
                data_->Serial_Knob_1 = knobSize;

            //tempChar[12] = '0' + knobSize;
            //data_->messageList.push_back(createCharArray(tempChar, 17));
            
            char to_send[] = "OK$";
            bool is_sent = Serial.WriteSerialPort(to_send);
            if (is_sent) {
                char temp[] = "Serial OK$ sent \r\n";
                data_->messageList.push_back(createCharArray(temp, 20));
            }
        }

        msgEnded = false;
        pos = 0;
        dwEvtMask = 0;

    }


    bool closed_ = Serial.CloseSerialPort();
    if (closed_) {
        cout << "Serial connection closed_" << endl;
    }

    return 0;
}



/*
#include <windows.h>
#include <tchar.h>
#include <assert.h>
#include <stdio.h>
#include <conio.h>






int SerialComunication(void* data) {
        SharedData* data_ = (SharedData*)data;

        HANDLE hCom;
        OVERLAPPED o;
        BOOL fSuccess;
        DWORD dwEvtMask;
        //DWORD lpEvtMask;

        DWORD  NumWritten;
        DWORD  dNoOFBytestoWrite;              // No of bytes to write into the port
        DWORD  dNoOfBytesWritten = 0;          // No of bytes written to the port
        DWORD NoBytesRead;                     // Bytes read by ReadFile()
        char  TempChar = ' ';                        // Temperory Character
        int i = 0;
        char SerialBuffer[30] = " ";               // Buffer Containing Rxed Data
        char ch[30] = "------------------  ";


        hCom = CreateFile(TEXT("\\\\.\\COM3"),
            GENERIC_READ | GENERIC_WRITE,
            0,    // exclusive access 
            NULL, // default security attributes 
            OPEN_EXISTING,
            FILE_FLAG_OVERLAPPED,
            NULL
        );

        if (hCom == INVALID_HANDLE_VALUE)
        {
            // Handle the error. 
            printf("CreateFile failed with error %d.\n", GetLastError());
            data_->messageList.push_back("CreateFile failed with error \r\n");
            return 1;
        }

        // Set the event mask. 

        fSuccess = SetCommMask(hCom, EV_CTS | EV_DSR | EV_RXCHAR);
        //Read_Status = SetCommMask(hCom, EV_RXCHAR);

        if (!fSuccess)
        {
            // Handle the error. 
            printf("SetCommMask failed with error %d.\n", GetLastError());
            data_->messageList.push_back("SetCommMask failed with error \r\n");
            return 1;
        }

        //// Create an event object for use by WaitCommEvent. 

        o.hEvent = CreateEvent(
            NULL,   // default security attributes 
            TRUE,   // manual-reset event 
            FALSE,  // not signaled 
            NULL    // no name
        );


        //// Initialize the rest of the OVERLAPPED structure to zero.
        o.Internal = 0;
        o.InternalHigh = 0;
        o.Offset = 0;
        o.OffsetHigh = 0;

        assert(o.hEvent);

        if (WaitCommEvent(hCom, &dwEvtMask, &o))
        {
            if (dwEvtMask & EV_DSR)     //DSR changed state
            {
                // To do.
                data_->messageList.push_back("I/O is pending... \r\n");
            }

            if (dwEvtMask & EV_CTS) // CTS changed state
            {
                // To do. 
            }

        }
        //if (WaitCommEvent(hCom, &dwEvtMask, &o)) {

        //    data_->messageList.push_back("received \r\n");


        //}

        else
        {
            DWORD dwRet = GetLastError();
            if (ERROR_IO_PENDING == dwRet) {
                printf("I/O is pending...\n");
                data_->messageList.push_back("I/O is pending... \r\n");

                // To do.
            }
            else {
                printf("Wait failed with error %d.\n", GetLastError());
                data_->messageList.push_back("Wait failed with error \r\n");
            }
        }

        ////DWORD dwBytesWritten = 0;
        //DWORD dwBytesRead = 0;
        //unsigned char oneChar;



        //--------------------------------------------------------------------------------------
        bool Read_Status = false;
        Read_Status = SetCommMask(hCom, EV_RXCHAR);


        //while (true) {
            Read_Status = WaitCommEvent(hCom, &dwEvtMask, NULL); //Wait for the character to be received

            if (Read_Status == FALSE) {
                data_->messageList.push_back("Error! in Setting WaitCommEvent()  \r\n");
            }
            else //If  WaitCommEvent()==True Read the RXed data using ReadFile();
            {
                data_->messageList.push_back("received \r\n");
                
                do {
                    if (!ReadFile(hCom, SerialBuffer, 1, &NoBytesRead, NULL)) {
                        //data_->messageList.push_back("wrong character \r\n");
                    }

                    data_->messageList.push_back("received SerialBuffer[i] \r\n");
                    i++;

                } while (NoBytesRead > 0);

                //for (int j = 0; j < i - 1; j++)		// j < i-1 to remove the dupliated last character
                ch[10] = SerialBuffer[0];
                ch[11] = SerialBuffer[1];
                //ch[25] = '\r\n';
             
                data_->messageList.push_back(ch);

            }
            
                ReadFile(hCom, &dwEvtMask, 10, 10, &o);
                ReadFile(hCom, &dwEvtMask, 1, &dwBytesRead, NULL); // what I tried to do, just outputs white space

                if (dwEvtMask & EV_RXCHAR) {
                    //data_->messageList.push_back("received \r\n");


                    char ch[30] = "received data =      \r\n";
                    ch[15] = dwBytesRead;

                    data_->messageList.push_back(ch);
                }
            
            //Sleep(1000);
            //data_->messageList.push_back("Sleep \r\n");
        //}

        data_->messageList.push_back("OUT Serial \r\n");
        CloseHandle(hCom);


        //for (int i = 0; i < 16; i++)
        //{
        //    oneChar = 0x00 + i;
        //    WriteFile(hSerial, (LPCVOID)&oneChar, 1, &dwBytesWritten, NULL);
        //    ReadFile(hSerial2, &oneChar, 1, &dwBytesRead, NULL); // what I tried to do, just outputs white space
        //}

        //CloseHandle(hSerial);
    }

/*

int SerialComunication(void* data) {
    
    SharedData* data_ = (SharedData*)data;

    //serialCom::data_ = (SharedData*)data;
    HANDLE myHandleCom = CreateFileA("\\\\.\\COM3",    //port name
                      GENERIC_READ | GENERIC_WRITE,     //Read/Write
                      0,                                // No Sharing
                      NULL,                             // No Security
                      OPEN_EXISTING,                    // Open existing port only
                      0,                                // Non Overlapped I/O
                      NULL);                            // Null for Comm Devices

    if (myHandleCom == INVALID_HANDLE_VALUE) {
        //printf("Error in opening serial port");
        data_->messageList.push_back("Error in opening serial port \r\n");
    }
    else {
        //printf("opening serial port successful");
        data_->messageList.push_back("opening serial port successful \r\n");
    }







    //LPDCB my_LPDCB;
    //GetCommState(myHandleCom, my_LPDCB);
    //
    //SetCommMask(myHandleCom, EV_RXCHAR);
    //

    //LPDWORD lpEvtMask;
    //POVERLAPPED lpOverlapped;
    //
    //WaitCommEvent(myHandleCom, lpEvtMask, lpOverlapped);

    //while (true) {
    //    //
    //    ReadFile(myHandleCom, my_LPDCB, );
    //    ReadFile(hSerial2, &oneChar, 1, &dwBytesRead, NULL);

    //    //ReadFile();
    //}

    //CloseHandle(myHandleCom); //Closing the Serial Port





    return 0;
}

/*
#include <windows.h>
#include <tchar.h>
#include <assert.h>
#include <stdio.h>

void _tmain(
            int argc,
            TCHAR *argv[]
           )
{
    HANDLE hCom;
    OVERLAPPED o;
    BOOL fSuccess;
    DWORD dwEvtMask;

    hCom = CreateFile( TEXT("\\\\.\\COM1"),
        GENERIC_READ | GENERIC_WRITE,
        0,    // exclusive access
        NULL, // default security attributes
        OPEN_EXISTING,
        FILE_FLAG_OVERLAPPED,
        NULL
        );

    if (hCom == INVALID_HANDLE_VALUE)
    {
        // Handle the error.
        printf("CreateFile failed with error %d.\n", GetLastError());
        return;
    }

    // Set the event mask.

    fSuccess = SetCommMask(hCom, EV_CTS | EV_DSR);

    if (!fSuccess)
    {
        // Handle the error.
        printf("SetCommMask failed with error %d.\n", GetLastError());
        return;
    }

    // Create an event object for use by WaitCommEvent.

    o.hEvent = CreateEvent(
        NULL,   // default security attributes
        TRUE,   // manual-reset event
        FALSE,  // not signaled
        NULL    // no name
         );


    // Initialize the rest of the OVERLAPPED structure to zero.
    o.Internal = 0;
    o.InternalHigh = 0;
    o.Offset = 0;
    o.OffsetHigh = 0;

    assert(o.hEvent);

    if (WaitCommEvent(hCom, &dwEvtMask, &o))
    {
        if (dwEvtMask & EV_DSR)
        {
             // To do.
        }

        if (dwEvtMask & EV_CTS)
        {
            // To do.
        }
    }
    else
    {
        DWORD dwRet = GetLastError();
        if( ERROR_IO_PENDING == dwRet)
        {
            printf("I/O is pending...\n");

            // To do.
        }
        else
            printf("Wait failed with error %d.\n", GetLastError());
    }
}


*/