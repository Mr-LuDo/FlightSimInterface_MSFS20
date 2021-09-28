#pragma once

#ifndef _MSFS
#define _MSFS

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>

#include "SimConnect.h"
#include <iostream>
#include "SharedData.h"

// ----------------------------------
using std::cin;
using std::cout;
using std::endl;
using std::string;
// ----------------------------------

static int reqQuit = 0;
static bool reqWait = false;
static bool reqExitSim = false;
static SharedData* data_;
// ----------------------------------


int MSFS_Interface(void* data);
void DataRequest();
void CALLBACK MyDispatchProcRD(SIMCONNECT_RECV* pData, DWORD cbData, void* pContext);

static HANDLE  hSimConnect = NULL;

struct Struct1
{
    char    title[256];
    double  kohlsmann;
    double  altitude;
    double  latitude;
    double  longitude;
};

enum EVENT_ID {
    EVENT_SIM_START,
    EVENT_SIM_STOPED,
    EVENT_SIM_PAUSED,
    EVENT_SIM_UN_PAUSED,
    EVENT_SIM_STATE,
    EVENT_SIM_PAUSE_STATE,
    EVENT_SIM_FRAME,
    EVENT_SIM_PAUSE_FRAME,
    EVENT_SIM_1SEC,
};


// priority
enum DATA_DEFINE_ID {
    DEFINITION_1,
    //    SIMCONNECT_GROUP_PRIORITY_STANDARD,
};

enum DATA_REQUEST_ID {
    REQUEST_1,
};

enum GROUP_REQUEST {
    GROUP_1,
};


#endif // !_MSFS
