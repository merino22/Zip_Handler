#include <iostream>
#include "readZIP.h"
#include <string>

using namespace std;

int main()
{
	readZIP obj;
	string filename;

	cout << "Enter ZIP name: ";
	cin >> filename;

	obj.openFile(filename);
	obj.readFile();
	
}
