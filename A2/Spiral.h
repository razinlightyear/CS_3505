/*
*
*
*/

class Spiral {

private:
	double x, y, startAngle, startRadius;
	// M_PI
public:
	// The spiral should grow larger
	Spiral(double _x, double _y, double _startAngle, double _startRadius);

	Spiral& operator++();
	
	double get_x();
	
	double get_y();
	
	// return degrees 
	double get_spiral_angle();
	
	// return degrees
	double get_text_angle();
};
