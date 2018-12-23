#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

bool snooze;


void snoozeActivator();
void snoozeGUI();
void quotes(int num);

void snoozeGUI()
{
	srand(time(NULL));
	system("clear");
	char temp;	
	cout << "Do you want to snooze?" << endl
	       << "(Y/N): ";
	cin >> temp;

	if (temp == 'N' || temp == 'n')
	{
		// Exit by printing the motivation and
		// deleting the files.
		quotes(rand()%6);
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
	       << "rtcwake -m mem -s 60 && vlc-wrapper alarm.mp3 --loop";

	snooze.close();

	//set perms
	system("chmod +x snooze.sh");
	cout << "Next alarm will occur in the next minute." << endl;

	system("sleep 2");
	system("./snooze.sh");

	return;
}

void quotes(int num)
{
	cout << "\n\n\n\n\n\n";
	switch(num)
	{
		case 0:
			cout << "The biggest source of motivation are your own thoughts," << endl
				<< "so think big and motivate yourself to win."; break;
		case 1:
			cout << "YOU DID NOT WAKE UP TODAY TO BE MEDIOCRE."; break;
		case 2:
			cout << "The expert in anything was once a beginner."; break;
		case 3: cout << "Win the morning and you will win the day."; break;
		case 4: cout << "What you do today can improve all your tomorrows."; break;
		case 5: cout << "The committed start early. The hungry never stop."; break;
		case 6: cout << "Success is the sum of small efforts repeated day in and day out."; break;
		default: cout << "Good morning!"; break;
	};

	cout << "\n\n Good morning." << endl
		<< "\nMake sure to read your morning notes and add logs to your journal.\n\n";
	
	return;
}

