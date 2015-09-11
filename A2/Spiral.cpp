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

	Spiral& operator++(){
		// Advances the next character
	}
/*
	Spiral operator++(double next){
		// Advances the next character
	}
*/
	
	double get_x(){
		return x;
	}
	
	double get_y(){
		return y;
	}
	
	// return degrees 
	double get_spiral_angle(){
		return startAngle;
	}
	
	// return degrees
	double get_text_angle(){
		return startRadius;
	}
};
