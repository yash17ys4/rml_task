#pragma once
#include <vector>
#include <cmath>
#ifndef POINTS_H__
#define POINTS_H__

using namespace std;

class Points {

	int pointId, clusterId;
	vector<double> coordinates;

public:
	Points() {}

	Points(int id, const vector<double>& coords) {
		this->pointId = id;
		this->coordinates = coords;
	}

	vector<double> getCoordinates() { return coordinates; }

	int getCluster() { return clusterId; }

	void setCluster(int val) { clusterId = val; }

	int getPointId() { return pointId; }

	int getDimesions() { return coordinates.size(); }

	double getDistance(Points&p2) {
		auto sum = 0.0;
		auto dimensions = p2.coordinates.size();
		for(int i = 0; i < dimensions; i++) {
			auto deltaCoord = (this->coordinates[i] - p2.coordinates[i]);
			sum += deltaCoord * deltaCoord;
		}
		return sqrt(sum);
	}

	Points add(const Points& p2) {
		auto coords = this->coordinates;
		for(auto i = 0; i < coords.size(); i++) {
			coords[i] += p2.coordinates[i];
		}
		return Points(0, coords);
	}

	Points multiplyByScalar(double scalar) {
		auto coords = this->coordinates;
		for(auto c : coords) {
			c *= scalar;
		}
		return Points(0, coords);
	}

	bool isEqualTo(const Points& p2) {
		for(auto i = 0; i < p2.coordinates.size(); i++) {
			if(this->coordinates[i] != p2.coordinates[i])
			return false;
		}
		return true;
	}
};

#endif