#pragma once

#include <string>
#include <iostream>


/*
	eq of circle is :
	x = r * cos(t)
	y = r * sin(t)

	deriv of parametric eq of circle

	x = - r * sin(t)
	y =   r * cos(t)
*/

template<typename T>
class Circle : public Shape<T> {
protected:
	T radius_1;
	std::string name;
public:
	Circle() {
		radius_1 = 0;
	}

	Circle(const Circle& other) {
		radius_1 = other.radius_1;
		name = "Circle";
	}

	Circle(T radius_1) {
		this->radius_1 = radius_1;
		name = "Circle";
	}

	void print_val_in_point(double t) {
		std::cout << radius_1 * cos(t) << " " << radius_1 * sin(t) << std::endl;
	}

	void print_der_in_point(double t) {
		std::cout << -radius_1 * sin(t) << " " << radius_1 * cos(t) << std::endl;
	}

	void print_inf() {
		std::cout << name << " " << radius_1 << std::endl;
	}


	std::string get_name() {
		return name;
	}

	T get_radius_1() {
		return radius_1;
	}
};
