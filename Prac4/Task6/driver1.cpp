#include <iostream>
#include "ArrayOperations.h"
using namespace std;

int main()
{
	double Numbers[ROW][COL];
	double value = 0;

	for(int count = 0; count < ROW; count++)
	{
		for(int index = 0; index < COL; index++)
		{
			Numbers[count][index] = value;
			value++;
		}
	}

	cout << "The array is: " << endl;

	for(int count = 0; count < ROW; count++)
	{
		for(int index = 0; index < COL; index++)
		{
			cout << Numbers[count][index] << "  ";			
		}

		cout << endl;
	}

	cout << "The total of the entire array is: "
		<< getTotal(Numbers);
	cout << endl;

	cout << "The total of row 1 is: ";
	cout << getTotal(0, Numbers);
	cout << endl;



	cout << "The total of COL 1 is: ";
	cout << getTotal(Numbers, 0);
	cout << endl;

	cout << "The avergae of whole array is : ";
	cout << getAverage(Numbers);
	cout << endl;

	cout << "The avergae of row 1 is : ";
	cout << getAverage(0, Numbers);
	cout << endl;

	cout << "The avergae of col 1 is : ";
	cout << getAverage(Numbers, 0);
	cout << endl;

	cout << "The highest in array is : ";
	cout << getHighest(Numbers);
	cout << endl;

	cout << "The highest in row 1 is : ";
	cout << getHighest(0, Numbers);
	cout << endl;

	cout << "The highest in col 1 is : ";
	cout << getHighest(Numbers, 0);
	cout << endl;



	cout << "The lowest in array is : ";
	cout << getLowest(Numbers);
	cout << endl;

	cout << "The lowest in row 2 is : ";
	cout << getLowest(1, Numbers);
	cout << endl;

	cout << "The lowest in col 2 is : ";
	cout << getLowest(Numbers, 1);
	cout << endl;



	return 0;


}