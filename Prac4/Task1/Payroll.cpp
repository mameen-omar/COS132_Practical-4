#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

string dash = "----------------------------------------------------------\n";

void Complete(int [ ] , int );

int main()
{
	const int MAX_EMPLOYEES = 10000;
	
	int hours[MAX_EMPLOYEES], 
	      employeeHours;
	
	cout << "Enter 999 to stop input\n";

	for (int count = 0; count < MAX_EMPLOYEES; count++)
	{
		cout << "Enter the hours worked by employee #" << count+1 << ": ";
		cin >> employeeHours;
		
		if (employeeHours == 999)
		{
			Complete(hours, count);
			return 0;
		}
		
		if ((employeeHours > 50) || (employeeHours < 0))
		{
			cout << dash  
				<< "You have entered " << employeeHours << ". It is invalid. Program terminated." << endl
				<< dash;

			return 0;
		}

		else if ((employeeHours == 0) || (employeeHours > 40))
		{
			char choice;
			
			cout << "You have entered " << employeeHours << ", which is an abnormal input. Please confirm input (Y or N): ";
			cin >> choice;
			
			if (choice != 'Y')
			{
			cout << dash
				<< "You have entered " << employeeHours << " and indicated that it is invalid. Program terminated.\n"
				<< dash;

			exit(0);
			}

			else 
				hours[count] = employeeHours;
		
		}
		else
			hours[count] = employeeHours;
	}
}


void Complete(int hoursWorked[ ], int Length)
{
	double average,
		   total = 0;
	
	cout << dash
		<< "The hours you entered are: ";
	
	for (int m = 0; m < Length; m++)
	{
		cout << hoursWorked[m] << " ";
		total += hoursWorked[m];
	}

	average = total/Length;
	
	cout << endl
		<< "The employee(s) worked an average of " << fixed << setprecision(1) << average << " hours this week." << endl
		<< dash;
}