#define _USE_MATH_DEFINES

#include <iostream>
#include <cassert>
#include <math.h>
#include "gtest/gtest.h"
#include "3DCurvesHierarchy.h"

double point_test(std::shared_ptr<Curve> curve)
{
	auto point = curve->get_point(M_PI / 6);
	return std::get<1>(point.get_coordinates()); // sin(30deg)=0.5
}

double derivative_test(std::shared_ptr<Curve> curve)
{
	auto point = curve->get_derivative(M_PI / 3);
	return std::get<1>(point.get_coordinates()); // cos(60deg)=0.5
}

TEST(test_curves, circle_test)
{
	auto circle = std::make_shared<Circle>(-1);
	EXPECT_DOUBLE_EQ(0.5, point_test(circle));
	EXPECT_DOUBLE_EQ(0.5, derivative_test(circle));
	EXPECT_DOUBLE_EQ(1, circle->get_rad()); // positive rad
}

TEST(test_curves, ellipse_test)
{
	auto ellipse = std::make_shared<Ellipse>(-1);
	EXPECT_DOUBLE_EQ(0.5, point_test(ellipse));
	EXPECT_DOUBLE_EQ(0.5, derivative_test(ellipse));
	EXPECT_DOUBLE_EQ(1, ellipse->get_rad());
	EXPECT_DOUBLE_EQ(1, ellipse->get_y_rad());
}

TEST(test_curves, helix_test)
{
	auto helix = std::make_shared<Helix>(-1);
	EXPECT_DOUBLE_EQ(0.5, point_test(helix));
	EXPECT_DOUBLE_EQ(0.5, derivative_test(helix));
	EXPECT_DOUBLE_EQ(1, helix->get_rad());
}
int main()
{
	testing::InitGoogleTest();

	return RUN_ALL_TESTS();
}