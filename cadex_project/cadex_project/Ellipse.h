#include <iostream>

/*
	parametric eq of ellipse is
	x = radius_1 * cos(t)
	y = radius_2 * sin(t);

	deriv of parametric eq of ellipse is
	x = - radius_1 * sin(t)
	y =   radius_2 * cos(t)

*/

template<typename T>
class Ellipse : public Shape<T> {
protected:
	T radius_1;
	T radius_2;
	std::string name;
public:

	Ellipse() {
		radius_1 = 0;
		radius_2 = 0;
		name = "Ellipse";
	}

	Ellipse(T _radius_1 = 0, T _radius_2 = 0) {
		radius_1 = _radius_1;
		radius_2 = _radius_2;
		name = "Ellipse";
	}

	Ellipse(const Ellipse& other) {
		radius_1 = other.radius_1;
		radius_2 = other.radius_2;
		name = other.name;
	}

	void print_val_in_point(double t) {
		std::cout << radius_1 * cos(t) << " " << radius_2 * sin(t) << std::endl;
	}

	void print_der_in_point(double t) {
		std::cout << -radius_1 * cos(t) << " " << radius_2 * sin(t) << std::endl;
	}

	void print_inf() {
		std::cout << name << " " << radius_1 << " " << radius_2 << std::endl;
	}

	void operator = (Ellipse other) {
		radius_1 = other.radius_1;
		radius_2 = other.radius_2;
	}

	T get_radius_1() {
		return radius_1;
	}

	T get_radius_2() {
		return radius_2;
	}

	std::string get_name() {
		return name;
	}
};