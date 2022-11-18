/**
 * @{ \name Five Gods constants.
 */
/**
 * \brief Five Gods constants.
 *
 * These five constants represent the five gods.
 */

#include "3DCurvesHierarchy.h"

void example() {

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
			<< std::get<0>(ptr->get_point(M_PI / 4).
				get_coordinates()) << " ; "
			<< std::get<1>(ptr->get_point(M_PI / 4).
				get_coordinates()) << " ; "
			<< std::get<2>(ptr->get_point(M_PI / 4).
				get_coordinates()) << ")\t\n";

		std::cout << "First derivative at t=PI/4: ("
			<< std::get<0>(ptr->get_derivative(M_PI / 4).
				get_coordinates()) << " ; "
			<< std::get<1>(ptr->get_derivative(M_PI / 4).
				get_coordinates()) << " ; "
			<< std::get<2>(ptr->get_derivative(M_PI / 4).
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
		std::cout << ptr->get_rad() << ' ';
	}
	std::cout << std::endl;

	std::cout << "Total sum of radii: " << sum << std::endl;
}

int main()
{
	example();
}

