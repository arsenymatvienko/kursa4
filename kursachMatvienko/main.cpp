#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <sstream>
#include <thread>
#include <chrono>
#include "firstpractice.cpp"
#include "2_lab_Matvienko_A_3372.cpp"
#include "3lab_MatvienkoAV_3372.cpp"
#include "4_lab_Matvienko_AV_3372.cpp"
using namespace std;
4

int main() {
    int choice;
    cout << "Navigation:" << "\n"
    << "Laba 1" << "\n"
    << "Laba 2" << "\n"
    << "Laba 3" << "\n"
    << "Laba 4" << "\n";


while(true) {
        cin.clear();
        cin.sync();
        short int workPoint;
        
        cout << "Select point: ";
        cin >> workPoint;

        switch (workPoint)
        {   
            case 1: {
                main1();
                break;
            }
			case 2: {
                main2();
                break;
            }
			case 3: {
                main3();
                break;
            }
			case 4: {
                main4();
                break;
            }
            default: {
                cout << "\n" << "You did not enter a number in the range from 1 to 4";
                break;
            }
        }

        cin.clear(); // Clearing the input stream from possible errors
        cin.sync();

        char stopFlag;
        cout << "\n" << "Continue the main program? (Y/N) ";
        cin >> stopFlag;
        
        if (stopFlag != 'Y' && stopFlag != 'y') {
            break;
        }
    }

    return 0;
}
