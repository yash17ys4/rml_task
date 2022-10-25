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

	void Init();

	void findNearestAndAssign();

	bool updateCentroid();

	void clearTheClusters();
	
public:
	KMeans (int k, int dim, int iters, int numPts) :
	K(k), dimensions(dim), iterations(iters), numOfPoints(numPts) {}

	void setDataPoints(const vector<Points>& dataPts) {
		this->dataPoints = dataPts;
	}

	vector<Points> getDataPoints() { return dataPoints; }

	vector<Cluster> getClusters() { return clusters; }

	void runKMeansAlgo();
};

#endif
