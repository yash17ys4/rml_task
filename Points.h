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

	Points(int id, const vector<double>& coords) :
		pointId(id), coordinates(coords) 
	{}

	vector<double> getCoordinates() { return coordinates; }

	int getCluster() { return clusterId; }

	void setCluster(int val) { clusterId = val; }

	int getPointId() { return pointId; }

	int getDimesions() { return coordinates.size(); }

	double getDistance(Points& p2);

	Points add(const Points& p2);

	Points multiplyByScalar(double scalar);

	bool isEqualTo(const Points& p2);
};

#endif