#pragma once

#include "Repository.h"
#include <stack>
using namespace std;

class Service {
private:
	Repository repo;
public:
	Service();
	Service(Repository&);
	void addEntity(float, float);
	bool removeEntity(float, float);
	bool searchEntity(float, float);
	bool updateEntity(float, float, float, float);
	Entitate greatestEntity();
	stack <Entitate> firstQuadrantElements();
	stack <Entitate> longestSequenceWithEqualValues();
	stack <Entitate> getAll();
	int size();
	~Service();
};