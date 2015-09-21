/*
* Andrew Emrazian CS3505 - Spiral implementation
*
*/
#define _USE_MATH_DEFINES
#include "Spiral.h"
#include <cmath>


	// The spiral should grow larger
	// The Spiral center (x,y), but the text placement needs an x,y for where the text goes (matching the example code), and it is that x,y which the getter should get.
	Spiral::Spiral(double _start_x, double _start_y, double _start_angle, double _star_radius)
	{
		start_x = _start_x;
		start_y	= _start_y;
		start_angle = _start_angle;
		start_radius	= _star_radius;	
	}

	// internally advances the spiral to its next position. 
	// The next position should be suitable for the next character of the text to be placed. 
	// prefix ++
	Spiral& Spiral::operator++()
	{
		// Advances the next character
		return *this;
	}

	// postfix ++
	Spiral Spiral::operator++(int)
	{
		// Advances the next character
		// int is a dummy param. Postfix is usually implemented by using prefix.
		Spiral temp = *this;
		++*this;
		return temp;
		   
	}
	
	double Spiral::get_x()
	{
		return current_x + M_PI;
	}
	
	double Spiral::get_y()
	{
		return current_y + M_PI;
	}
	
	// return degrees. not needed?
	double Spiral::get_spiral_angle()
	{
		return start_angle;
	}
	
	// return degrees
	double Spiral::get_text_angle()
	{
		return start_radius;
	}
	
	double Spiral::get_letter_angle_x()
	{
		return letter_angle_x;
	}
	
	double Spiral::get_letter_angle_y()
	{
		return letter_angle_y;
	}