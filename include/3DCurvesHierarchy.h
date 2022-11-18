/*! \mainpage 3D curves hierarchy.
 *
 * Assignment for probationers.
 * A project that implements support for the hierarchy of 3D curves.
 * Currently three types of curves can be support:
 * "Circle", "Ellipse", "Helix".
 * 
 *  Each curve able to return a 3D point and a first derivative (3Dvector)
 *  per parameter t along the curve.
 */ 

#pragma once

#define _USE_MATH_DEFINES

#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <math.h>
#include <time.h>

/*! \class Point 3D_curves_hierarchy.h "include/3D_curves_hierarchy.h"
 *  \brief This class delivers a point object.
 *
 * Point object has x, y, z coordinates of type double
 */
class Point
{
public:

	Point(double _x, double _y, double _z = 0) :
		x(_x), y(_y), z(_z) {};

	/** Getter member function.
    *  Returns x, y, z coordinates as tuple.
    */	
	std::tuple<double, double, double> get_coordinates()
	{
		return { x,y,z };
	}

	/** Setter member function.
    *  Sets x, y, z coordinates by tuple elements.
    */	
	void set_coordinates(double _x, double _y, double _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

private:
	double x;
	double y;
	double z;
};

// 1. Curve definition
// Interface
/*! \class Curve 3D_curves_hierarchy.h "include/3D_curves_hierarchy.h"
 *  \brief This class delivers virtual curve object (interface).
 */
class Curve
{
public:
	virtual ~Curve() = default;
	virtual Point get_point(double t) = 0;
	virtual Point get_derivative(double t) = 0;
	virtual double get_rad() = 0;
	virtual double get_y_rad() = 0;
private:
	double rad = 0;
};


/*! \class Circle 3D_curves_hierarchy.h "include/3D_curves_hierarchy.h"
 *  \brief This class delivers a circle object.
 */
class Circle : virtual public Curve
{
public:

	Circle(double _rad = 1) :
		rad(std::abs(_rad)) {};

	virtual ~Circle() {}

	/** return a 3D point per parameter t along the circle.
 	*/
	virtual Point get_point(double t)
	{
		double x = rad * cos(t);
		double y = rad * sin(t);
		Point point(x, y);
		return point;
	}

	/** return a first derivative (3Dvector)
 	* per parameter t along the circle.
 	*/
	virtual Point get_derivative(double t)
	{
		double x = -rad * sin(t);
		double y = rad * cos(t);
		Point point(x, y);
		return point;
	}

	virtual double get_rad()
	{
		return rad;
	}

	virtual double get_y_rad()
	{
		return rad;
	}

private:
	double rad;
};


/*! \class Ellipse 3D_curves_hierarchy.h "include/3D_curves_hierarchy.h"
 *  \brief This class delivers a ellipse object.
 */
class Ellipse : virtual public Curve
{
public:

	Ellipse(double _x_rad = 1, double _y_rad = 1) :
		x_rad(std::abs(_x_rad)),
		y_rad(std::abs(_y_rad)) {};

	virtual ~Ellipse() {}

	/** return a 3D point per parameter t along the ellipse.
 	*/
	virtual Point get_point(double t)
	{
		double x = x_rad * cos(t);
		double y = y_rad * sin(t);
		Point point(x, y);
		return point;
	}

	/** return a first derivative (3Dvector)
 	*  per parameter t along the ellipse.
 	*/
	virtual Point get_derivative(double t)
	{
		double x = -x_rad * sin(t);
		double y = y_rad * cos(t);
		Point point(x, y);
		return point;
	}

	virtual double get_rad() {
		return x_rad;
	}

	virtual double get_y_rad()
	{
		return y_rad;
	}

private:
	double x_rad;
	double y_rad;
};

/*! \class Helix 3D_curves_hierarchy.h "include/3D_curves_hierarchy.h"
 *  \brief This class delivers a helix object.
 */
class Helix : virtual public Curve
{
public:

	Helix(double _rad = 1, double _step = 1) :
		rad(std::abs(_rad)), step(_step) {};

	virtual ~Helix() {}

	/** return a 3D point per parameter t along the helix.
 	*/
	virtual Point get_point(double t)
	{
		double x = rad * cos(t);
		double y = rad * sin(t);
		double z = step;
		Point point(x, y, z);
		return point;
	}

	/** return a first derivative (3Dvector)
 	*  per parameter t along the helix.
 	*/
	virtual Point get_derivative(double t)
	{
		double x = -rad * sin(t);
		double y = rad * cos(t);
		Point point(x, y);
		return point;
	}

	virtual double get_rad()
	{
		return rad;
	}

	virtual double get_y_rad()
	{
		return rad;
	}

private:
	double rad;
	double step;
};






