#include "backEnd.h"


int backEnd(void* data) {

    SharedData* data_ = (SharedData*)data;

    while (true) {
        Sleep(100);

        if (data_->updatedCounter) {

            char ch[20] = "counter = ___ \r\n";

            ch[12] = '0' + data_->counter % 100 % 10;
            ch[11] = '0' + data_->counter % 100 / 10;
            ch[10] = '0' + data_->counter / 100;

            data_->messageList.push_back(createCharArray(ch, 20));
            data_->updatedCounter = false;
        }


    }

    return 0;
}


char* createCharArray(char ch[], int size) {
    char* temp = new char[size];
    for (int i = 0; i < size; ++i) {
        temp[i] = ch[i];
    }
    return temp;
}


