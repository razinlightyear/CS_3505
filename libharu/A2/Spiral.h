/*
* Andrew Emrazian CS3505 - Spiral prototyping
*
*/
class Spiral {

private:
	double start_x, start_y, start_angle, start_radius, current_x, current_y, letter_angle_x, letter_angle_y;
	// M_PI
public:
	// The spiral should grow larger
	Spiral(double _start_x, double _start_y, double _start_angle, double _star_radius);

	Spiral& operator++();
	
	Spiral operator++(int);
	
	double get_x();
	
	double get_y();
	
	// return degrees 
	double get_spiral_angle();
	
	// return degrees
	double get_text_angle();
	
	double get_letter_angle_x();
	
	double get_letter_angle_y();
};
