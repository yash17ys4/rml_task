#include <iostream>
#include <fstream>
#include <vector>
#include "Points.h"
#include "Cluster.h"
#include "KMeans.h"

using namespace std;

namespace {
	bool isValid(char s) {
		if ((48 <= int(s) && int(s)  <= 57) || s == '.' || s == '+' || s == '-' || s == 'e')
			return true;
		else
			return false;
	}

	vector <double> stringToVector(const string& str) {
		vector<double> values;
        string temporaryNumber = "";

		for(auto c : str) {
			if(isValid(c)) {
				temporaryNumber += c;
			}
			else if(temporaryNumber.length() > 0) {
				values.push_back(stod(temporaryNumber));
				temporaryNumber = "";
			}
		}
		if(temporaryNumber.length() > 0) {
			values.push_back(stod(temporaryNumber));
			temporaryNumber = "";
		}
		return values;
	}
}

int main() {
	string filename;
	cout<<"Enter the filename:\n";
	cin>>filename;

	int ptId = 0;
	vector<Points> dataPoints;
	string fileLine;
	fstream file(filename);
	while(getline(file, fileLine)) {
		ptId++;
		auto coords = stringToVector(fileLine);
		dataPoints.emplace_back(ptId, coords);
	}

	int k, iter;
	cout<<"Enter k:";
	cin>>k;
	cout<<"Enter the number of iterations:";
	cin>>iter;

	KMeans kmeans(k, dataPoints[0].getDimesions(), iter, dataPoints.size());
	kmeans.setDataPoints(dataPoints);
	kmeans.Init();

	for(int i = 0; i < iter; i++) {
		kmeans.findNearestAndAssign();
		auto isUpdated = kmeans.updateCentroid();
		if(isUpdated == false) {
			break;
		}
		kmeans.clearTheClusters();
	}

	for(auto pts : kmeans.getDataPoints()) {
		cout<<pts.getCluster()<<", ";
	}

	for(auto cntrds: kmeans.getClusters()) {
		auto coords = cntrds.getCentroid().getCoordinates();
		for(auto cds: coords) {
			cout<<cds<<", ";
		}
		cout<<"\n";
	}
	
	file.close();
	return 0;
}