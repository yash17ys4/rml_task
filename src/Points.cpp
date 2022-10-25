#include "Points.h"

double Points::getDistance(Points&p2) {
	auto sum = 0.0;
	auto dimensions = p2.coordinates.size();
	for(int i = 0; i < dimensions; i++) {
		auto deltaCoord = (this->coordinates[i] - p2.coordinates[i]);
		sum += deltaCoord * deltaCoord;
	}
	return sqrt(sum);
}

Points Points::add(const Points& p2) {
	auto coords = this->coordinates;
	for(auto i = 0; i < coords.size(); i++) {
		coords[i] += p2.coordinates[i];
	}
	return Points(0, coords);
}

Points Points::multiplyByScalar(double scalar) {
	auto coords = this->coordinates;
	for(auto& c : coords) {
		c *= scalar;
	}
	return Points(0, coords);
}

bool Points::isEqualTo(const Points& p2) {
	for(auto i = 0; i < p2.coordinates.size(); i++) {
		if(this->coordinates[i] != p2.coordinates[i])
		return false;
	}
	return true;
}