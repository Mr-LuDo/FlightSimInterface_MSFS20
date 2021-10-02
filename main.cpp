#include "MyForm.h"
#include "MSFS_Interface.h"
#include "SerialCom.h"
#include "backEnd.h"

#include <process.h>


unsigned int __stdcall mythreadA(void* data) {
	int StatusReturned = MSFS_Interface(data);
	return StatusReturned;
}

unsigned int __stdcall mythreadB(void* data) {
	int StatusReturned = MyUI(data);
	return StatusReturned;
}

unsigned int __stdcall mythreadC(void* data) {
	int StatusReturned = SerialComunication(data);
	return StatusReturned;
}

unsigned int __stdcall mythreadD(void* data) {
	int StatusReturned = backEnd(data);
	return StatusReturned;
}



int main() {

	SharedData data;
	HANDLE myhandleA, myhandleB, myhandleC, myhandleD;

	myhandleA = (HANDLE)_beginthreadex(0, 0, &mythreadA, &data, 0, 0);
	myhandleB = (HANDLE)_beginthreadex(0, 0, &mythreadB, &data, 0, 0);
	myhandleC = (HANDLE)_beginthreadex(0, 0, &mythreadC, &data, 0, 0);
	myhandleD = (HANDLE)_beginthreadex(0, 0, &mythreadD, &data, 0, 0);

	WaitForSingleObject(myhandleB, INFINITE);

	CloseHandle(myhandleA);	
	CloseHandle(myhandleB);
	CloseHandle(myhandleC);
	CloseHandle(myhandleD);

	return 0;
}