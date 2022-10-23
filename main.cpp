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

	auto cl = kmeans.getClusters();
	cout<<cl.size()<<"\n";
	for(int i = 0; i < cl.size(); i++) {
		auto c = cl[i].getCentroid().getCoordinates();
		for(int j = 0; j < c.size(); j++) {
			cout<<c[j]<<", ";
		}
		cout<<"\n";
	}

	for(int i = 0; i < iter; i++) {
		kmeans.findNearestAndAssign();
		auto isUpdated = kmeans.updateCentroid();
		if(isUpdated == false) {
			break;
		}
	}

	file.close();
	return 0;
}