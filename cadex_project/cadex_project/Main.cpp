#include "Shape.h"
#include "Helix.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Task_2-7.h"

#include <iostream>
#include <vector>

int main() {

	//generate 100 curves with radiuces in [0 : 50] 
	std::vector<std::shared_ptr<Shape<double>>> curves;
	curves = generate_curves<double>(100, 0.0, 50.0);

	std::cout << std::endl;
	for (int i = 0; i < curves.size(); i++) {
		curves[i]->print_inf();
	}

	// print value of curve and deriv. in PI/2
	const double PI = 3.1415;
	std::cout << "\nvalue and deriv of circles in PI/2\n";
	for (auto curve : curves) {
		curve->print_val_in_point(PI / 2);
		curve->print_der_in_point(PI / 2);
	}

	// create vector, which contain only circles
	// and sort it by radius in ascending order
	std::vector<std::shared_ptr<Shape<double>>> only_circ;
	only_circ = only_circles(curves);

	std::cout << "\ncircles inf.\n";
	for (auto circle : only_circ) {
		circle->print_inf();
	}

	// computate sum of circ. radii
	std::cout << "\nsum of radii\n";
	std::cout << sum_of_radius_seq(only_circ) << std::endl;
	std::cout << sum_of_radius_par(only_circ) << std::endl;
	return 0;
}