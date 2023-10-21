#pragma once

#include "Shape.h"

#include <vector>
#include <random>
#include <cstdlib>
#include <iostream>
#include <algorithm>

// Task 3
// Generate curves with random radii
template<typename T>
std::vector<std::shared_ptr<Shape<T>>> generate_curves(int count, double lower_bound, double upper_bound) {

	if (lower_bound < 0) {
		lower_bound = 0.0;
	}

	std::vector<std::shared_ptr<Shape<T>>> curves;

	for (int i = 0; i < count; i++) {
		int type = rand() % 3 + 1;
		if (type == 1) {
			// It's circle
			double rad1 = lower_bound + (double)(rand()) / ((double)(RAND_MAX / (upper_bound - lower_bound)));
			curves.push_back(std::make_shared<Circle<double>>(Circle<double>(rad1)));
		}
		else if (type == 2) {
			// It's ellipse
			double rad1 = lower_bound + (double)(rand()) / ((double)(RAND_MAX / (upper_bound - lower_bound)));
			double rad2 = lower_bound + (double)(rand()) / ((double)(RAND_MAX / (upper_bound - lower_bound)));
			curves.push_back(std::make_shared<Ellipse<double>>(Ellipse<double>(rad1, rad2)));
		}
		else if (type == 3) {
			// It's helix
			double rad1 = lower_bound + (double)(rand()) / ((double)(RAND_MAX / (upper_bound - lower_bound)));
			curves.push_back(std::make_shared<Helix<double>>(Helix<double>(rad1)));
		}
	}

	return curves;
}

// Task 3
// Print value in point t and deriv. of all curves in the container 
template<typename T>
void print_info(std::vector<std::shared_ptr<Shape<T>>>& curves, double t) {

	for (auto curve : curves) {
		std::cout << curve->print_val_in_point(t) << " " << curve->print_der_in_point(t) << std::endl;
	}
}

// Task 4-5
// Create container that contain only circles
// And sort it in ascending order
template<typename T>
std::vector<std::shared_ptr<Shape<T>>> only_circles(std::vector<std::shared_ptr<Shape<T>>>& curves) {

	std::vector<std::shared_ptr<Shape<T>>> circles;

	for (auto curv : curves) {
		if (curv->get_name() == "Circle") {
			circles.push_back(curv);
		}
	}

	// each circle in cont. circles has same address that it had in curves 

	std::sort(circles.begin(), circles.end(), [](auto& circle1, auto& circle2) {
		return circle1->get_radius_1() < circle2->get_radius_1();
		});

	return circles;
}


// Task 6
// Computation on sum of radiuces of circles
template<typename T>
T sum_of_radius_seq(std::vector<std::shared_ptr<Shape<T>>>& curves) {
	T sum = 0;
	for (auto curve : curves) {
		sum += curve->get_radius_1();
	}
	return sum;
}

// Task 8
// Parallel computation of sum of radiuces of circles
template<typename T>
T sum_of_radius_par(std::vector<std::shared_ptr<Shape<T>>>& curves) {
	T sum = 0;
#pragma omp parallel for shared(curves) reduction(+:sum)
	for (int i = 0; i < curves.size(); i++) {
		sum += curves[i]->get_radius_1();
	}
	return sum;
}

