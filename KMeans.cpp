#include "KMeans.h"

void KMeans::Init() {
	clusters.reserve(K);
	for(int i = 0; i < K; i++) {
		int randIndx = rand()%numOfPoints;
		clusters.emplace_back(Cluster(i+1, dataPoints[randIndx]));
	}
}

void KMeans::findNearestAndAssign() {
	for(int i = 0; i < dataPoints.size(); i++) {
		double minDist = 1e10;
		int minIndx = 0;
		for(int j = 0; j < K; j++) {
			Points centroid(clusters[j].getCentroid());
			auto dist = centroid.getDistance(dataPoints[i]);
			// auto dist = 1.0;
			// auto dist = dataPoints[i].getDistance(centroid);
			if(dist < minDist) {
				minDist = dist;
				minIndx = j;
			}
		}
		dataPoints[i].setCluster(minIndx);
		clusters[minIndx].addPoint(dataPoints[i]);
	}
}

bool KMeans::updateCentroid() {
	bool updated = false;
	for(int i = 0; i < clusters.size(); i++) {
		auto isUpdated = clusters[i].updateCentroid();
		updated = updated || isUpdated;
	}
	return updated;
}

void KMeans::clearTheClusters() {
	for(auto& clstr : clusters) {
		clstr.clearClusterPoints();
	}
}