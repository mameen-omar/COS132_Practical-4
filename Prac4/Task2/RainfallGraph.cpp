#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

void Graph();

int main()
{
	const int SIZE = 364;
	const int MIN = 1;
	const int MAX = 52;
	int start; // Starting weeks 
	int start_temp; // Temp for week range
	int weeks; //Weeks to display
	int weeks_valid; // number of weeks that are valid.
	int weeks_temp;
	string filename;

	filename = "raindata.txt";
	ifstream InputFile;
	InputFile.open(filename.c_str());

	int rainfall[SIZE];

	for (int index = 0; index < SIZE; index++)
	{

		InputFile >> rainfall[index];
	}

	InputFile.close(); // Close off the input file since it has been read into the array already.


	cout << "Enter the starting week's index [1 - 52]:";
	cin >> start_temp;

	while(start_temp < MIN || start_temp > MAX)
	{
		cout << "You entered " << start_temp << " where only values [1 - 52] are valid.";
		exit(0);
	}

	start = start_temp;
	weeks_valid = (MAX - start) + 1 ;

	cout << "Enter the number of weeks [1 - " << weeks_valid << "]: ";
	cin >> weeks_temp;

	if(weeks_temp < 1 || weeks_temp > weeks_valid)
	{
		cout << "You entered " << weeks_temp << " where only values [1 - " << weeks_valid << "] are valid.";
		exit (0);
	}

	weeks = weeks_temp;

	Graph();

	return 0;
}

void Graph()
{
	string dash = "--------------------------------------------------------------------------------------";
	string heading = "Relative Weekly Rainfall (%)";
	int number = 0;

	cout << dash << endl;
	cout << setw(62) << right << heading << endl;
	cout << " ";

	for (int count = 0; count <= 100; count += 5)
	{
		cout << setw(4) << right << count;
	}

	cout << endl;	
	cout << "    ";

	for (int count = 0; count < 20; count++)
	{
		cout << "+---";
	}

	cout << "+\n";

	cout << endl; 
	
}