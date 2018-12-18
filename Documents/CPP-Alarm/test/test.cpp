// This file is used for testing fstream input with strings.
//
// Authored by mikaeruu.
//

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{

	ofstream testFile("rtc.sh");
	testFile << system("date --date 'today' +%Y-%m-%d > rtc.txt");
	return 0;
}
