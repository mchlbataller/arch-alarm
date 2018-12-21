#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace std;

int day;
int hour, minutes;

void alarmGUI()
{
	cout << "Input the day you want the alarm to trigger: ";
	cin >> day;
	/* 
	 * 	Following has been removed due to the blocked dependency
		cout << "\nInput the hour: ";
		cin >> hour;
	*/
	cout << "\nInput the minute: ";
	cin >> minutes;
	return;	
}




void alarmActivator()
{
	ofstream alarm("rtcwake.sh");
	
	alarm << "#!/bin/bash" << endl << endl
		<< "pactl set-sink-volume 0 175%" << endl
			
			// NOTE: Removed due to bugs
			// << "rtcwake -m mem --local --date '2018-12-" << day << " " << hour << ":" << minutes
		<< "rtcwake -m mem -s " << minutes
		<< " && " << "vlc-wrapper /home/michael/Music/alarm.mp3 --loop" << endl;

		/* 
		 *	NOTE: REMOVED DUE TO CAPABILITY PROBLEMS
		 * 	
		 * 	if (today == 1)		//set params if today
		 *		system("date --date 'today' +%Y-%m-%d >> rtcwake.txt");
		 *	else 
		 *		system("date --date 'tomorrow' +%Y-%m-%d >> rtcwake.sh");
		 *
		 *
		 *	cout << today;
		 */


	//Close the file
		alarm.close();	
	//Set the permissions
		system("chmod +x rtcwake.sh");
	//then run;
		cout << "Initiating alarm..." << endl << endl;
		system("sleep 2");
		system("./rtcwake.sh");

	//Ending spaces.
	cout << endl << endl << endl << endl;
		
	return;
}
