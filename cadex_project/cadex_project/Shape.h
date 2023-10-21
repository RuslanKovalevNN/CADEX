#pragma once

#include <iostream>
#include <iomanip>

template<typename T>
class Shape {
public:
	virtual void print_val_in_point(double t) = 0;
	virtual void print_der_in_point(double t) = 0;

	virtual std::string get_name() = 0;
	virtual T get_radius_1() = 0;
	virtual void print_inf() = 0;
	// virtual void operator = (Shape other) = 0;

};
