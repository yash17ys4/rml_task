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

	int getClusterId() { return clusterId; }

	Points getCentroid() { return centroid; }

	bool updateCentroid() {
		if(points.empty()) {
			return false;
		}
		Points average(points[0]);
		for(auto i = 1; i < points.size(); i++) {
			average = average.add(points[i]);
		}
		average = average.multiplyByScalar(1.0/points.size());
		if(average.isEqualTo(this->centroid)) {
			return false;
		}
		else {
			this->centroid = average;
			return true;
		}
	}

	Cluster(int clusterId, Points& centroid) {
		this->clusterId = clusterId;
		this->centroid = centroid;
		this->addPoint(centroid);
	}

	void addPoint(Points p)
	{
		p.setCluster(this->clusterId);
		points.push_back(p);
	}

	bool removePoint(int pointId) {
		int clusterSize = points.size();
		for(auto i = 0; i < clusterSize; i++) {
			if(points[i].getPointId() == pointId) {
				points.erase(points.begin() + i);
				return true;
			}
		}
		return false;
	}

	void clearClusterPoints() { points.clear(); }

	Points getPoint(int pos) { return points[pos]; }
};

#endif