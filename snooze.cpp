#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;

bool snooze;


//To be recognized by the method...
void snoozeActivator();

void snoozeGUI()
{
	system("clear");
	char temp;	
	cout << "Do you want to snooze?" << endl
	       << "(Y/N): ";
	cin >> temp;

	if (temp == 'N' || temp == 'n')
	{
		// Exit by printing the motivation and
		// deleting the files.
		system("cat quotes");
		system("rm -rf rtcwake.sh && rm -rf snooze.sh");
		exit(0);
	}
	return;
}

void initSnooze(int volume)
{
	ofstream snooze("snooze.sh");
	snooze << "#!/bin/bash" << endl
	       << "pactl set-sink-volume 0 " << volume << "%" << endl 
	       << "rtcwake -m mem -s 60 && vlc-wrapper /home/michael/Music/alarm.mp3 --loop";

	snooze.close();

	//set perms
	system("chmod +x snooze.sh");
	cout << "Next alarm will occur in the next minute." << endl;

	system("sleep 2");
	system("./snooze.sh");

	return;
}
