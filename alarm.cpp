#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace std;

// For setting the date, hour, and minute
int day,
    hour,
    minute;


void alarmMinGUI();
void alarmConfMin();
void alarmDateGUI();
void alarmConfDate();
void initAlarm();


// GUI for Minutes Countdown
void alarmMinGUI()
{
	cout << "\nInput the minute: ";
	cin >> minute;
	return;	
}



// Configure the alarm through minute countdown
void alarmConfMin(int volume)
{
	ofstream alarm("rtcwake.sh");
	
	alarm << "#!/bin/bash" << endl << endl
		<< "pactl set-sink-volume 0 " << volume << "%" << endl
		<< "pactl set-sink-mute 0 0" << endl
		<< "rtcwake -m mem -s " << minute * 60		// Minutes to seconds conversion
		<< " && " << "vlc-wrapper alarm.mp3 --loop > logs" << endl;


	alarm.close();	
	return;
}


void alarmDateGUI()
{
	cout << "Set the date and time \n\nDay: ";
	cin >> day;
	cout << "Hour (24h): ";
	cin >> hour;
	cout << "Minute: ";
	cin >> minute;

	return;
}

void alarmConfDate(int volume)
{
	ofstream alarm("rtcwake.sh");

	alarm << "#!/bin/bash" << endl
	       // Unmute
	       << "pactl set-sink-mute 0 0" << endl 
	       // Set volume
	       << "pactl set-sink-volume 0 " << volume << "%" << endl
	       // Main rtcwake command 	       
	       << "rtcwake -m mem --local --date '2018-12-" << day << " " << hour << ":" << minute << "' && "
	       << "vlc-wrapper alarm.mp3 --loop >> logs.txt";

	alarm.close();
}

void initAlarm()
{
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
