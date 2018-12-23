#include <iostream>
#include "foreWarning.cpp"
#include "alarm.cpp"
#include "snooze.cpp"
#include <cstdlib>
#include <cstdio>
using namespace std;


int main()
{
	// Warn user to run program as root.
	foreWarning();	

	// Display date
	system("date");

	// Set volume
	int volume = 175;
	/* Removed the following due to inconvenience.
	 *
	 * cout << "Volume (0-175  min: 50 max: 175): ";
	 * cin >> volume;
	 *
	 */

	// Choice if using rtcwake -s or rtcwake --date
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
	for(char repeatVar;;)
	{
		snoozeGUI();
		initSnooze(volume);
	}

	return 0;
}

