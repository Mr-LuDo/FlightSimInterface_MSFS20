#pragma once

#ifndef SRDDTA_H
#define SRDDTA_H

#include "list"
#include <iostream>
#include <String.h>

struct SharedData {

	bool  UI_Status = false;
	bool  UI_PauseStatus = false;
	bool UI_reqUpdate = false;
	double  UI_altitude = 0;
	double  UI_latitude = 0;
	double  UI_longitude = 0;
	double  UI_kohlsmann = 0;

	std::list<char*> messageList = { "List Initiated.\r\n" };
	bool updatedCounter = false;
	int counter = 0;

	int Serial_Knob_1 = 0;
	int Serial_Knob_2 = 0;
	int Serial_Knob_3 = 0;
	int Serial_Knob_4 = 0;
	int Serial_Knob_5 = 0;

	bool Serial_Button_1 = false;
	bool Serial_Button_2 = false;
	bool Serial_Button_3 = false;
	bool Serial_Button_4 = false;
	bool Serial_Button_5 = false;

	bool UI_Light_out_1 = false;
	bool UI_Light_out_2 = false;
	bool UI_Light_out_3 = false;
	bool UI_Light_out_4 = false;
	bool UI_Light_out_5 = false;

};


#endif // !SRDDTA_H