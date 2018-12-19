#include "ArrayOperations.h"
using namespace std;

/* Returns the sum of all the values in the array passed as parameter*/
double getTotal(const double array[ROW][COL])
{
	double total = 0;

	for (int count = 0; count < ROW; count++)
	{
		for (int index = 0; index < COL; index++)
		{
			total = total + array[count][index];
		}
	}

	return total;
}

/* The first argument is the subscript of a row in the array passed as the second parameter
The function returns the sum of the values in the specified row.*/
double getTotal(int rowSub, const double array[ROW][COL])
{
	double total = 0;

	for(double count = rowSub; count <= rowSub; count++)
	{
		for (int index = 0; index < COL; index++)
		{
			total = total + array[rowSub][index];
		}
	}

	return total;
}


/* The second argument is the subscript of a column in the array passed as the first parameter
The function returns the sum of the values in the specified column.*/
double getTotal(const double array[ROW][COL], int colSub)
{
	double total = 0;

	for(int count = colSub; count == colSub; count++)
	{
		for(int index = 0; index < ROW; index++)
		{
			total = total + array[index][count];
		}
	}

	return total;
}


/* Returns the average of all the values in the array passed as parameter*/
double getAverage(const double array[ROW][COL])
{
	double average = 0,
		   total = 0;	
	int values = 0;

	for(int count = 0; count < ROW; count++)
	{
		for(int index = 0; index < COL; index++)
		{
			total = total + array[count][index];
			values++;
		}
	}

	average = (total/values);

	return average;
}

/* The first argument is the subscript of a row in the array passed as the second parameter */
/*  Returns the average of speified row*/
double getAverage(int rowSub, const double array[ROW][COL])
{
	double average = 0,
		   total = 0;	
	int values = 0;

	for(int count = rowSub; count <= rowSub; count++)
	{
		for(int index = 0; index < COL; index++)
		{
			total = total + array[count][index];
			values++;
		}
	}

	average = (total/values);

	return average;
}

/* The second argument is the subscript of a column in the array passed as the first parameter
The function returns the average of the values in the specified column.*/
double getAverage(const double array[ROW][COL], int colSub)
{
	double average = 0,
		   total = 0;	
	int values = 0;

	for(int count = colSub; count <= colSub; count++)
	{
		for(int index = 0; index < ROW; index++)
		{
			total = total + array[index][count];
			values++;
		}
	}

	average = (total/values);

	return average;
}

/* Returns the highest of all the values in the array passed as parameter*/
double getHighest(const double array[ROW][COL])
{
	double highest = array[0][0];

	for(int count = 0; count < ROW; count++)
	{
		for(int index = 0; index < COL; index++)
		{
			if(array[count][index] > highest)
			{
				highest = array[count][index];
			}//end of if
		}//end of COL for
	}// End of Row for

	return highest;
}

/* The first argument is the subscript of a row in the array passed as the second parameter */
/*  Returns the highest of speified row*/
double getHighest(int rowSub, const double array[ROW][COL])
{
	double highest = array[rowSub][0];

	for(int count = 0; count < COL; count++)
	{			
		if(array[rowSub][count] > highest)
		{
			highest = array[rowSub][count];
		}
	}
		
	return highest;
}

/* The second argument is the subscript of a column in the array passed as the first parameter
Returns the highest the specified column.*/
double getHighest(const double array[ROW][COL], int colSub)
{
	double highest = array[0][colSub];

	for(int count = 0; count < ROW; count++)
	{			
		if(array[count][colSub] > highest)
		{
			highest = array[count][colSub];
		}
	}
		
	return highest;
}

/* Returns the lowest of all the values in the array passed as parameter*/
double getLowest(const double array[ROW][COL])
{
	double lowest = array[0][0];

	for(int count = 0; count < ROW; count++)
	{
		for(int index = 0; index < COL; index++)
		{
			if(array[count][index] < lowest)
			{
				lowest = array[count][index];
			}//end of if
		}//end of COL for
	}// End of Row for

	return lowest;
}

/* The first argument is the subscript of a row in the array passed as the second parameter */
/*  Returns the lowest of speified row*/
double getLowest(int rowSub, const double array[ROW][COL])
{
	double lowest = array[rowSub][0];

	for(int count = 0; count < COL; count++)
	{			
		if(array[rowSub][count] < lowest)
		{
			lowest = array[rowSub][count];
		}
	}
		
	return lowest;
}

/* The second argument is the subscript of a column in the array passed as the first parameter
Returns the lowest the specified column.*/
double getLowest(const double array[ROW][COL], int colSub)
{
	double lowest = array[0][colSub];

	for(int count = 0; count < ROW; count++)
	{			
		if(array[count][colSub] < lowest)
		{
			lowest = array[count][colSub];
		}
	}
		
	return lowest;
}
