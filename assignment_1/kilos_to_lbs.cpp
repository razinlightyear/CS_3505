/**
** CS 3505 - Assignment 1 - Andrew Emrazian
**
** This program converts a number in kilos to the number in
** pounds. The number is input from the command line as an argument.
** The number is then output as standard output stream. 
**/
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
	// Assume that there is one valid argument.
	// Always print 2 decimal places past the decimal.
	float lbs = atof(argv[1])*2.20462262;
	cout << setprecision(2) << fixed << lbs << endl;
	return 0;
}