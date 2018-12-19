#include "reduce.h"
#include <iostream>
using namespace std;

void displayFraction(int a, int b)
{
	cout << a << "/" << b;
}

int gcd(int a, int b)
{
	if( (a <= 0) || (b <= 0))
	{
		return -1;
	}	

	int smallest = a;
	smallest = (smallest > b ? b : a);
	int gcd = 1;

	for(int count = 1; count <= smallest; count++)
	{
		if((a % count == 0) && (b % count == 0))
		{
			gcd = count;
		}
	}

	return gcd;
}

bool reduceFraction(int &num, int &denom)
{
	if(num <= 0 || denom <= 0)
	{
		return false;
	}	

	int smallest = num;
	smallest = (smallest > denom ? denom :num);
	int gcd = 1;

	for(int count = 1; count <= smallest; count++)
	{
		if( ( (num % count) == 0) && ( (denom % count) == 0) )
		{
			gcd = count;
		}
	}

	num = (num/gcd);
	denom = (denom/gcd);

	return true;
}
