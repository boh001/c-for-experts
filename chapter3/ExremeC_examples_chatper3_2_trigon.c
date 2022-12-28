#include <math.h>

#include "ExremeC_examples_chatper3_2_geometry.h"

double to_radian(double reg) {
	return (PI * reg) / 180;
}
double to_degree(double rad) {
	return (PI * rad) / 180;
}
double cos_deg(double reg) {
	return cos(to_radian(reg));
}
double acos_deg(double reg) {
	return acos(reg);
}
double sin_deg(double deg) {
	return sin(to_radian(deg));
}
double asin_deg(double deg) {
	return asin(to_radian(deg));
}

