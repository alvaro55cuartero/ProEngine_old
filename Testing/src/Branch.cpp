#include "Branch.h"
#include "string"
#include "iostream"

Branch::Branch(const char* name) : object(name, "obj"){
	Branch::name = name;
}


void Branch::addBranch(const char* name) {
	if (this->getChild(name) == NULL) {
		Branch branch(name);
		branch.setParent(this);
		branches.push_back(branch);
	} else {
		std::cout << "No puede usar el nombre: " << name << "\nYa esta en uso." << std::endl;
	}
}

void Branch::remBranch(const char* name) {
	Branch* branch = (this->getChild(name));
	for (int i = 0; i < branches.size(); i++) {
		if (strcmp(branches[i].getName().c_str(), name)==0) {
			branches.erase(branches.begin() + i);
		}
	}
}

void Branch::setParent(Branch* parent) {
	Branch::parent = parent;
}

Branch* Branch::getParent() {
	return parent;
}

Branch* Branch::getChild(const char* child) {
	for (Branch& b : branches) {
		if (strcmp(b.getName().c_str() , child) == 0) {
			return &b;
		}
	}
	return NULL;
}

std::string Branch::getName() {
	return name;
}

void Branch::view(int x, int y, bool last) {
	char aux[40];
	for (int i = 0; i < x; i++) {
		if (last) {
			aux[i] = ' ';
		}
		else {
			aux[i] = 179;
		}
	}
	if (x != 0) {
		aux[0] = ' ';
		if (y != 0) {
			aux[x] = 195;
			aux[x + 1] = '\0';
		}
		else {
			aux[x] = 192;
			aux[x + 1] = '\0';
		}
	}
	else {
		aux[x] = '\0';
	}

	std::cout << aux << name << std::endl;
	x++;
	for (int i = branches.size() - 1; i > -1; i--) {
		((Branch) branches[i]).view(x, i, y == 0);
	}
}