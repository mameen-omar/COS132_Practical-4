#include "reduce.h"
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <iomanip>
	
using namespace std;

int main()
{
	string heading = "Fraction Reduction";
	string dash = "-------------------------------";

	int numerator, denominator, numerator_L, denominator_L, GCD;
	double decimal , numerator_d, denominator_d;
	int numerator_output, denominator_output;

	//My prompts
	cout << heading << endl;
	cout << dash << endl;
	cout << "Enter the numerator: ";
	cin >> numerator_d; // Entering double
	cout << "Enter the denominator: ";
	cin >> denominator_d;// Entering Double

	//Input Validation for division by o
	if(denominator_d == 0 || denominator_d == 0.0)
	{
		cout << "You entered " << denominator_d << ", which is division by zero.";
		cout << " This is invalid and the program will now exit." << endl;
		exit(EXIT_SUCCESS); // Exit the program
	}

	//for int function to get GCD and input validation, this numerator and denomiantor will always be positive
	numerator = ((numerator_d < 0) ? (numerator_d * -1) : numerator_d); 
	denominator = ((denominator_d < 0) ? (denominator_d * -1) : denominator_d) ;

	
	GCD = gcd(numerator, denominator);

	cout << "The GCD of " << numerator << " and " << denominator << " is " << GCD << endl;

	reduceFraction(numerator, denominator);

	//These have already changed in the function and both are positive
	numerator_L = numerator;
	denominator_L = denominator;
	

	//if only denominator is negative
	if ( (denominator_d < 0) && (numerator_d > 0) )
	{
		numerator_L = (numerator_L * -1);
	}	

	//If both are negative, both need to be positive
	if (denominator_d < 0 && numerator_d < 0)
	{
		denominator_L = denominator_L;
		numerator_L = numerator_L ;
	}


	//If only inputted numerator is negative
	if (numerator_d < 0 && denominator_d > 0)
	{
		numerator_L = (numerator_L * -1);
	}

	decimal = ( (numerator_d / denominator_d) );

	//Actual Output
	cout << "The lowest form of ";
	displayFraction(numerator_d, denominator_d);
	cout << " is ";
    displayFraction(numerator_L, denominator_L);
	cout << " = " << decimal;

	return 0;
}