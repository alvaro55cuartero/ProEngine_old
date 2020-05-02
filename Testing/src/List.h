#pragma once
#include <vector>
#include <iostream>
#include "objects/Object.h"

class List {
private:
	std::vector<Object> objects;

public:
	List();
	void addObj(const char* obj);
	void remObj();
	void editObj();
	void view();
	Object* getObj(const char* obj);


private:

};