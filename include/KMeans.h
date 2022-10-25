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

	void Init();

	void findNearestAndAssign();

	bool updateCentroid();

	void clearTheClusters();

	vector<Cluster> getClusters() { return clusters; }
};

#endif
