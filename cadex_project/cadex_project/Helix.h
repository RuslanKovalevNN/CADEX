#pragma once

#include "Shape.h"
#include <string>

/*
	parametric eq of Helix is
	x = r*cos(t)
	y = r*sin(t)
	z = t

	deriv of parametric eq of Helix is
	x'(t) = -r*sin(t)
	y'(t) =  r*cos(t)
	z'(t) =  1
*/

template<typename T>
class Helix : public Shape<T> {
	std::string name;
	T radius_1;
public:

	void print_val_in_point(double t) {
		std::cout << radius_1 * cos(t) << " " << radius_1 * sin(t) << " " << t << std::endl;
	}

	void print_der_in_point(double t) {
		std::cout << -radius_1 * sin(t) << " " << radius_1 * cos(t) << " 1 " << std::endl;
	}

	void print_inf() {
		std::cout << "Helix " << " " << radius_1 << std::endl;
	}

	Helix() {
		this->radius_1 = 0;
		this->name = "Helix";
	}

	Helix(T radius_1) {
		this->radius_1 = radius_1;
		name = "Helix";
	}

	Helix(const Helix& other) {
		this->radius_1 = other.radius_1;
		this->name = other.name;
	}

	std::string get_name() {
		return name;
	}

	T get_radius_1() {
		return radius_1;
	}
};
