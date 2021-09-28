#pragma once

#ifndef SRDDTA
#define SRDDTA

struct SharedData {
	bool  UI_Status = false;
	bool  UI_PauseStatus = false;
	bool UI_reqUpdate = false;
	double  UI_altitude = 0;
	double  UI_latitude = 0;
	double  UI_longitude = 0;
	double  UI_kohlsmann = 0;
};


#endif // !SRDDTA