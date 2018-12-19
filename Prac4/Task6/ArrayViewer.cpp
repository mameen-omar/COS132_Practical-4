#include "ArrayOperations.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	ifstream Inputfile;
	double data[ROW][COL];
	string filename;
	int values = 0;
	int values_needed = (COL * ROW);
	string dash = "---------------------------------------------------";
	string dash_small = "------------------------------";

	cout << "Please enter file name: ";
	cin >> filename;

	Inputfile.open(filename.c_str());

	if(!Inputfile)
	{
		cout << "Error, you entered " << filename << " as the name of the Input file. The file "
			 << filename << " does not exist. The program will now exit. Please re-run the program "
			 << " and try again." << endl;
		Inputfile.close();
		exit(0);
	}

	for(int count = 0; count < ROW; count++)
	{
		for(int index = 0; index < COL; index++)
		{
			if(Inputfile >> data[count][index])
			{
				values++;	
			}

			else if(values != values_needed)
			{
				cout << "This program needs " << values_needed << " real values to fill an array with "
				<< ROW << " rows and " << COL << " columns." << endl;

				cout << "Only " << values << " real values could be read from the file called "
				<< filename << ".\n";

				Inputfile.close();
				exit(0);
			}	
		}
	}
		

	cout << setw(COL * WIDTH + 2) << "|" << right << setw(WIDTH) << "Total" << setw(WIDTH) << "Max"
	<< setw(WIDTH) << "Min" << endl;

	cout << string(WIDTH * COL, '-') << "-|" << dash_small << endl;

	for (int rowNum = 0; rowNum < ROW; rowNum++)
	{
		for(int colNum = 0; colNum < COL; colNum++)
		{
			cout << setw(WIDTH) << setprecision(2) << fixed << data[rowNum][colNum];
		}

		cout << " |";
		cout << setw(WIDTH) << setprecision(2) << fixed << getTotal(rowNum, data)
		<< setw(WIDTH) << getHighest(rowNum, data) << setw(WIDTH) << getLowest(rowNum, data)
		<< endl;
	}

	cout << string(WIDTH * COL, '-') << "-|" << dash_small << endl;

	for(int columns = 0; columns < COL; columns++)
	{
		cout << setw(WIDTH) << getTotal(data, columns);
	}

	cout << " |" << setw(WIDTH) << setprecision(2) << fixed << getTotal(data) << setw(WIDTH) << getHighest(data)
	<< setw(WIDTH) << getLowest(data) << endl;


	return 0;
}