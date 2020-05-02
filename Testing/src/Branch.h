#pragma once
#include <vector>
#include <string>
#include "Objects/Object.h"

class Branch {
private:
	std::vector<Branch> branches;
	Branch* parent;
	Object object;
	std::string name;

public:
	Branch(const char* name);
	void addBranch(const char* name);
	void remBranch(const char* name);
	Branch* getChild(const char* child);
	std::string getName();
	void setParent(Branch* parent);
	Branch* getParent();
	void view(int x, int y, bool last);

private:

};