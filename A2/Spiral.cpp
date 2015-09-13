/*
*
*
*/
#define _USE_MATH_DEFINES
#include <cmath>
//#include <math.h>

class Spiral {

private:
	double x, y, startAngle, startRadius;
	// M_PI
public:
	// The spiral should grow larger
	// The Spiral center (x,y), but the text placement needs an x,y for where the text goes (matching the example code), and it is that x,y which the getter should get.
	Spiral(double _x, double _y, double _startAngle, double _startRadius){
	
	}

	// prefix ++
	Spiral& operator++(){
		// Advances the next character
		return *this;
	}

	// postfix ++
	void operator++(int){
		// Advances the next character
		// int is a dummy param. Postfix is usually implemented by using prefix.
	}
	
	double get_x(){
		return x;
	}
	
	double get_y(){
		return y;
	}
	
	// return degrees. not needed?
	double get_spiral_angle(){
		return startAngle;
	}
	
	// return degrees
	double get_text_angle(){
		return startRadius;
	}
};
