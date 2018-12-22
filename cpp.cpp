#include <iostream>
#include "foreWarning.cpp"
#include "alarm.cpp"
#include "snooze.cpp"
#include <cstdlib>
#include <cstdio>
using namespace std;


int main()
{

	// Function for warning user to run sudo.
	// Located at foreWarning.cpp
	foreWarning();	

	// Set volume
	int volume;
	cout << "Volume (0-175  min: 50 max: 175): ";
	cin >> volume;



	// Alarm functions start here.
	// These functions are located on alarm.cpp.
	cout << "A. Set minutes for countdown \nB. Set specific date and time";
	char var;	cin >> var;

	switch(var)
	{
		case 'a': alarmMinGUI(); alarmConfMin(volume); break;	// If the user wants to set minutes	
		case 'A': alarmMinGUI(); alarmConfMin(volume); break;
		case 'b': alarmDateGUI(); alarmConfDate(volume); break;	// If the user wants date
		case 'B': alarmDateGUI(); alarmConfDate(volume); break;
		default: cout << "Wrong input"; break;
	}
	
	// Initialize alarm
	initAlarm();	

	// Snooze function.
	// Can be found on snooze.cpp file.
	for(char repeatVar;;)
	{
		snoozeGUI();
		initSnooze(volume);
	}


		

	return 0;
}

