// 3D_curves_hierarchy.cpp : Defines the entry point for the application.
//

#include "3D_curves_hierarchy.h"

#define PI 3.14159265

// 1. Curve definition
class Point
{
public:

	Point(double _x, double _y, double _z = 0) :
		x(_x), y(_y), z(_z) {};

	std::tuple<double, double, double> get_coordinates()
	{
		return { x,y,z };
	}

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

// Interface
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

class Circle : virtual public Curve
{
public:

	Circle(double _rad = 1) :
		rad(std::abs(_rad)){};

	virtual ~Circle() {}

	virtual Point get_point(double t)
	{
		double x = rad*cos(t);
		double y = rad*sin(t);
		Point point(x, y);
		return point;
	}

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

class Ellipse : virtual public Curve
{
public:

	Ellipse(double _x_rad = 1, double _y_rad = 1) :
			x_rad(std::abs(_x_rad)),
			y_rad(std::abs(_y_rad)) {};

	virtual ~Ellipse() {}

	virtual Point get_point(double t)
	{
		double x = x_rad * cos(t);
		double y = y_rad * sin(t);
		Point point(x, y);
		return point;
	}

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

class Helix : virtual public Curve
{
public:

	Helix(double _rad = 1, double _step = 1) :
		rad(std::abs(_rad)), step(_step){};

	virtual ~Helix() {}

	virtual Point get_point(double t)
	{
		double x = rad * cos(t);
		double y = rad * sin(t);
		double z = step;
		Point point(x, y, z);
		return point;
	}

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

int main()
{
	// 2. Container of curves created in random manner
	std::vector< std::shared_ptr<Curve>> curve_pointers;

	std::srand(time(0));
	for (int i = 0; i < 10; ++i)
	{
		int n = std::rand() % 12;

		// Create circle
		if (n >= 0 && n < 4)
		{
			int rad = std::rand() % 5 + 1;
			curve_pointers.emplace_back(std::make_shared<Circle>(rad));
		}
		// Create ellipse
		else if (n >= 4 && n < 8) 
		{
			int x_rad = std::rand() % 6 + 1;
			int y_rad = std::rand() % 7 + 1;
			curve_pointers.emplace_back(std::make_shared<Ellipse>(x_rad, y_rad));
		}
		// Create helix
		else if (n >= 8 && n < 12) 
		{
			int rad = std::rand() % 9 + 1;
			int step = std::rand() % 10 + 1;
			curve_pointers.emplace_back(std::make_shared<Helix>(rad, step));
		}
	}

	// 3. Points & derivatives of curves at t=PI/4
	for (auto& ptr : curve_pointers)
	{
		std::cout << "Point coordinates at t=PI/4: ("
			<< std::get<0>(ptr->get_point(PI / 4).
				get_coordinates()) << " ; "
			<< std::get<1>(ptr->get_point(PI / 4).
				get_coordinates()) << " ; "
			<< std::get<2>(ptr->get_point(PI / 4).
				get_coordinates()) << ")\t\n";

		std::cout << "First derivative at t=PI/4: ("
			<< std::get<0>(ptr->get_derivative(PI / 4).
				get_coordinates()) << " ; "
			<< std::get<1>(ptr->get_derivative(PI / 4).
				get_coordinates()) << " ; "
			<< std::get<2>(ptr->get_derivative(PI / 4).
				get_coordinates()) << ")\t\n\n";
	}

	// 4. Only circles
	std::vector< std::shared_ptr<Curve>> circle_pointers;

	for (auto& ptr : curve_pointers)
	{
		auto downcastedPtr = std::dynamic_pointer_cast<Circle>(ptr);
		if (downcastedPtr)
		{
			auto circl_ptr(ptr);
			circle_pointers.emplace_back(circl_ptr);
		}
	}

	// 5. Sort circles
	std::sort(circle_pointers.begin(), circle_pointers.end(),
		[](const std::shared_ptr<Curve> c1, const std::shared_ptr<Curve> c2) -> bool {
		return c1->get_rad() < c2->get_rad(); });

	// 6. Total sum of radii
	std::cout << "Circles radius:\n";

	double sum = 0;

	for (auto& ptr : circle_pointers)
	{
		sum += ptr->get_rad();
		std::cout << ptr ->get_rad() << ' ';
	}
	std::cout << std::endl;

	std::cout << "Total sum of radii: " << sum << std::endl;
}
