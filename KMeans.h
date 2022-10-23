#pragma once
#include <vector>
#include "Cluster.h"
#include "Points.h"
#ifndef KMEANS_H__
#define KMEANS_H__

class KMeans {
	int K;
	int dimensions;
	int iterations;
	int numOfPoints;
	std::vector<Cluster> clusters;
	std::vector<Points> dataPoints;
	
public:
	KMeans (int k, int dim, int iters, int numPts) :
	K(k), dimensions(dim), iterations(iters), numOfPoints(numPts) {}

	void setDataPoints(const vector<Points>& dataPts) {
		this->dataPoints = dataPts;
	}

	vector<Points> getDataPoints() { return dataPoints; }

	void Init() {
		clusters.reserve(K);
		for(int i = 0; i < K; i++) {
			int randIndx = rand()%numOfPoints;
			clusters.emplace_back(Cluster(i+1, dataPoints[randIndx]));
		}
	}

	void findNearestAndAssign() {
		for(int i = 0; i < dataPoints.size(); i++) {
			double minDist = 1e10;
			int minIndx = 0;
			for(int j = 0; j < K; j++) {
				Points centroid(clusters[i].getCentroid());
				// auto dist = centroid.getDistance(dataPoints[i]);
				auto dist = 1.0;
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

	bool updateCentroid() {
		bool updated = false;
		for(int i = 0; i < clusters.size(); i++) {
			auto isUpdated = clusters[i].updateCentroid();
			updated = updated || isUpdated;
		}
		return updated;
	}

	void clearTheClusters() {
		for(auto& clstr : clusters) {
			clstr.clearClusterPoints();
		}
	}

	vector<Cluster> getClusters() { return clusters; }
};

#endif
