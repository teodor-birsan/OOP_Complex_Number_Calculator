#pragma once

#include "Entitate.h"
#include <stack>
using namespace std;

class Repository {
private:
	stack <Entitate> elements;
public:
	Repository();
	void add(Entitate&);
	bool remove(Entitate&);
	bool findEntity(Entitate&);
	bool update(Entitate&, Entitate&);
	int stackSize();
	stack <Entitate> removeALL();
	stack <Entitate> getAll();
	~Repository();
};