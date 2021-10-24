// TimeClock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//@Author: Daniel Hernandez
//@Version: 1.0
//@Date: 09 September 2021

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>

using namespace std;

//Function declarations

//Function to clear the screen
void ClearScreen();

//Converts the time from seconds to an hours/minutes/seconds format and prints it to the screen.
void ConvertTime(int&);

//Prints the time in both 24 hour and 12 hour formats
void PrintTime(int, int, int, string);

//Prints out the options menu
void PrintMenu();

//Adjusts the time according to the input from the user
int AdjustTime(int&);

int main()
{
    //time is a value in seconds starting with 0 seconds as 00:00:00 on a given day
    int time = 0;
    //runLoop keeps the loop running until the user selects option 4 from the menu
    int runLoop = 0;

    do
    {
        ConvertTime(time);

        //Look for any key press
        if (_kbhit())
        {
            //Display the menu
            PrintMenu();
            runLoop = AdjustTime(time);
        }
        else
        {
            ++time;
            Sleep(1000);
        }
        ClearScreen();
    } while (runLoop != 4);
}

//Clears the screen
void ClearScreen()
{
    //ASCII escape commands, \033[2J clears the screen (J) from top to bottom \033[1;1H moves the cursor to row 1 column 1
    //cout << "\033[2J\033[1;1H";
    system("CLS");
}

//Converts the time from seconds to an hours/minutes/seconds format and prints it to the screen.
void ConvertTime(int& timeVal) 
{
    //00:00:00 OR 12:00:00 AM = 0 seconds

    //Keep time within 24 hours, which is 87000 seconds
    if (timeVal > 86399)
    {
        timeVal = timeVal - 86400;
    }

    //Converts the time into hours minutes and seconds
    int hours = timeVal / 3600;
    int minutes = (timeVal - (hours * 3600)) / 60;
    int seconds = (timeVal - (hours * 3600) - (minutes * 60));

    if (timeVal > 43199)
    {
        PrintTime(hours, minutes, seconds, "PM");
    }
    else
    {
        PrintTime(hours, minutes, seconds, "AM");
    }
}

//Print the 24 and 12 hour clocks
void PrintTime(int hourVal, int minuteVal, int secondVal, string dayPart)
{
    cout << setfill('*') << setw(26) << ""  
         << setfill(' ') << setw(4)  << ""  
         << setfill('*') << setw(26) << "" << endl;

    cout << setfill(' ') 
         << "*" << setw(6) << "" << "12-Hour Clock" << setw(6) << right << "*"
         << setw(4) << ""
         << "*" << setw(6) << "" << "24-Hour Clock" << setw(6) << right << "*" << endl;
    
    //Special case for midnight and formatting for 12 hour time
    int formatHour;

    if ((hourVal % 12) == 0)
    {
        formatHour = 12;
    }
    else
    {
        formatHour = hourVal % 12;
    }

    //12 hour clock time
    cout << setfill(' ') 
         << "*" << setw(7) << "" 
         << setfill('0') 
         << setw(2) << formatHour << ":" 
         << setw(2) << minuteVal << ":" 
         << setw(2) << secondVal << " " + dayPart << setfill(' ') << setw(7) << right << "*"
         << setfill(' ') << setw(4) << "";

    //24 hour clock time
    cout << setfill(' ')
        << "*" << setw(8) << ""
        << setfill('0')
        << setw(2) << hourVal << ":"
        << setw(2) << minuteVal << ":"
        << setw(2) << secondVal << setfill(' ') << setw(9) << right << "*" << left << endl;

    cout << setfill('*') << setw(26) << "" 
         << setfill(' ') << setw(4)  << "" 
         << setfill('*') << setw(26) << "" << endl << endl;

    cout << "Press any key to open the menu...." << endl << endl;
}


//Print the time adjustment menu
void PrintMenu()
{
    cout << setfill('*') << setw(26) << "" << setfill(' ') << left << endl;
    cout << setw(25) << "* 1 - Add One Hour" << right << "*" << left << endl;
    cout << setw(25) << "* 2 - Add One Minute" << right << "*" << left << endl;
    cout << setw(25) << "* 3 - Add One Second" << right << "*" << left << endl;
    cout << setw(25) << "* 4 - Exit Program" << right << "*" << left << endl;
    cout << setfill('*') << setw(26) << "" << endl;
}

//Adjusts the time according to the input from the user
int AdjustTime(int& timeVal)
{
    int menuSelection;
    
    //Asks for the user selection
    cin >> menuSelection;

    switch (menuSelection)
    {
        case 1: // Add one hour
            timeVal += 3600;
            break;
        case 2: // Add one minute
            timeVal += 60;
            break;
        case 3: // Add one second
            timeVal += 1;
            break;
        case 4: // Exit the program
            return 4;
            break;
        default: // Print an error message and reload the function
            ClearScreen();
            ConvertTime(timeVal);
            PrintMenu();
            cout << "Please make a valid selection." << endl;
            AdjustTime(timeVal);
    }

    return 0;
}
