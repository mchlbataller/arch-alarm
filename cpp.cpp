#include <iostream>
#include "foreWarning.cpp"
#include "alarm.cpp"
#include "snooze.cpp"
#include <cstdlib>
#include <cstdio>
using namespace std;
/*
 *	
 *	I. foreWarning
 *		
 *	II. alarmGUI
 * *
 *	III. alarmActivator
 *		
 *	IV. snoozeGUI
 *
 *	V. snoozeActivator
 */

int main()
{

	// Function for warning user to run sudo.
	// Located at foreWarning.cpp
	foreWarning();	

	// Alarm functions start here.
	// These functions are located on alarm.cpp.
	
	
	// Activate the alarm through writing to the file.
	alarmGUI();
	alarmActivator();		
	
	for(;;)
		snoozeGUI();

	return 0;
}

