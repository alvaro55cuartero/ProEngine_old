#pragma once
#include "Objects/Object.h"
#include "Branch.h"

class Tree{

private:
	Branch root;
	Branch* current;

public:
	Tree(const char* name);
	void view(int x, int y, bool last);
	void moveOut();
	void moveIn(const char* name);
	void addBranch(const char* name);
	void remBranch(const char* name);
	
};



