#include "Cluster.h"

bool Cluster::updateCentroid() {
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

void Cluster::addPoint(Points p)
{
	p.setCluster(this->clusterId);
	points.push_back(p);
}

bool Cluster::removePoint(int pointId) {
	int clusterSize = points.size();
	for(auto i = 0; i < clusterSize; i++) {
		if(points[i].getPointId() == pointId) {
			points.erase(points.begin() + i);
			return true;
		}
	}
	return false;
}