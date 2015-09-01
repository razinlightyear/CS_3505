/**
** Program description
**
**
**/
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[])
{
	//cout << argc << endl;
	//cout << argv[0] << endl;
	// Only print 2 decimal places past the decimal.
	// Assume that there is one valid argument.
	float lbs = atof(argv[1])*2.20462262;
	cout << setprecision(2) << fixed << lbs << endl;
	return 0;
}