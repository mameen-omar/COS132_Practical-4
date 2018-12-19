#include "ChipsAndSalsa.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>										
#include <cmath>

using namespace std;

int errors = 0;
void Greeting();
void GetSold(string [], int []);
void Report (string [], int []);
void Total(int []);
string GetMaxName(const string [], const int []);
int GetMaxNumber(const string [], const int []);
string GetMinName(const string [], const int []);
int GetMinNumber(const string [], const int []);


int main()
{
	Greeting();

	GetSold(salsaName, numOfJars);
	cout << endl;
	

	Report(salsaName, numOfJars);
	
	Total(numOfJars);
	cout << endl;


	string MaximumName = GetMaxName(salsaName, numOfJars);
	int MaximumNumber = GetMaxNumber(salsaName, numOfJars);
	string MinimumName = GetMinName(salsaName, numOfJars);
	int MinimumNumber = GetMinNumber(salsaName, numOfJars);


	cout << "The maximum sold was " << MaximumName << " at " << MaximumNumber << " jars.\n";
	cout << "The minimum sold was " << MinimumName << " at " << MinimumNumber << " jars.\n";

	if (errors != 0)
	{
		cout << "Warning: A total of " << errors << " errors were encountered during input.\n";
	}
	
	else
	{
		cout << "No errors were encountered during input." << endl;
	}

return 0;
}

void Greeting()
{
	string stars = "********************";

	cout << stars << endl;
	cout << "* CHIPS AND SALSA  *" << endl;
	cout << stars << endl;
}

void GetSold (string NameOfSalsa[], int Number[])
{
	double sold = 0;
	int SoldInt = 0;
	for (int index = 0; index < NUM_OF_SALSA_TYPES ; index++)
	{
		cout << "Enter the number of jars of " << NameOfSalsa[index] << " sold: ";
		cin >> sold;

		if(sold <= 0)
		{	
			sold = 0;
			SoldInt = 0;
			errors++;
		}

		if(fmod(sold , 1) != 0)
		{
			SoldInt = sold;
			errors++;
		}

		SoldInt = static_cast<int>(sold);
		Number[index] = SoldInt;
	}
}

void Report (string Salsa[], int NumOfSold[])
{
	cout << "**************************" << endl;
	cout << "* CHIPS AND SALSA REPORT *" << endl;
	cout << "**************************" << endl;
	cout << "Name:" << setw(18) << right << "Amount:" << endl;

	for (int count = 0; count < NUM_OF_SALSA_TYPES; count++)
	{
		cout << setw(10) << left << Salsa[count] << setw(11) << right << NumOfSold[count] << endl;
	}
}

void Total(int NumSold[])
{
	int total = 0;

	for (int position = 0 ; position < NUM_OF_SALSA_TYPES; position++)
	{
		total += NumSold[position];
	}

	cout << "----------------------" << endl;
	cout << "Total:" << setw(15) << right << total << endl;
	cout << "----------------------" << endl;

}

string GetMaxName(const string Salsa_Name[], const int NumberSold[])
{
	int HighestValue = NumberSold[0];
	string HighestName = Salsa_Name[0];

	for(int count = 1; count < 6; count++)
	{
		if(NumberSold[count] > HighestValue)
		{
			HighestName = Salsa_Name[count];
			HighestValue = NumberSold[count];
		}
	}

	return HighestName;
}

int GetMaxNumber(const string Salsa_Name[], const int NumberSold[])
{
	int HighestValue = NumberSold[0];
	string HighestName = Salsa_Name[0];

	for(int count = 1; count < 6; count++)
	{
		if(NumberSold[count] > HighestValue)
		{
			HighestName = Salsa_Name[count];
			HighestValue = NumberSold[count];
		}
	}

	return HighestValue;
}


string GetMinName(const string Salsa_Name[], const int NumberSold[])
{
	int LowestValue = NumberSold[0];
	string LowestName = Salsa_Name[0];

	for(int count = 1; count < 6; count++)
	{
		if(NumberSold[count] <= LowestValue)
		{
			LowestName = Salsa_Name[count];
			LowestValue = NumberSold[count];
		}
	}

	return LowestName;
}

int GetMinNumber(const string Salsa_Name[], const int NumberSold[])
{
	int SmallestValue = NumberSold[0];
	string SmallestName = Salsa_Name[0];

	for(int count = 1; count < 6; count++)
	{
		if(NumberSold[count] <= SmallestValue)
		{
			SmallestName = Salsa_Name[count];
			SmallestValue = NumberSold[count];
		}
	}

	return SmallestValue;
}
