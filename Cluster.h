#pragma once
#include <vector>
#include "Points.h"
#ifndef CLUSTER_H__
#define CLUSTER_H__

class Cluster {
	int clusterId;
	Points centroid;
	vector<Points> points;
public:

	Cluster(int clusterId, Points& centroid)
		: clusterId(clusterId), centroid(centroid) {
		this->addPoint(centroid);
	}

	int getClusterId() { return clusterId; }

	Points getCentroid() { return centroid; }

	bool updateCentroid();

	void addPoint(Points p);

	bool removePoint(int pointId);

	void clearClusterPoints() { points.clear(); }

	Points getPoint(int pos) { return points[pos]; }
};

#endif