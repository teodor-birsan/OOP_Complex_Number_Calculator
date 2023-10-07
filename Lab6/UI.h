#pragma once

#include "Service.h"

class UI {
private:
	Service service;
	void addEnitty();
	void removeEntity();
	void updateEntity();
	void searchEntity();
	void getAll();
	void greatestEntity();
	void longestSequence();
	void firstQuadrant();
public:
	UI();
	UI(Service&);
	void runConsole();
	~UI();
};
