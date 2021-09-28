#include "MyForm.h"
#include "MSFS_Interface.h"

#include <Windows.h>
#include <process.h>
#include <stdio.h>
#include <iostream>



unsigned int __stdcall mythreadA(void* data) {
	MSFS_Interface(data);
	return 0;
}

unsigned int __stdcall mythreadB(void* data) {
	MyUI(data);
	return 0;
}



//int __cdecl main(int argc, char* argv[]) {
int main() {

	HANDLE myhandleA, myhandleB;

	SharedData data;

	myhandleA = (HANDLE)_beginthreadex(0, 0, &mythreadA, &data, 0, 0);
	myhandleB = (HANDLE)_beginthreadex(0, 0, &mythreadB, &data, 0, 0);

	WaitForSingleObject(myhandleB, INFINITE);

	CloseHandle(myhandleA);	
	CloseHandle(myhandleB);

	return 0;
}