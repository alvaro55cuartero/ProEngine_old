#include <vector>
#include <string>
#include <iostream>
#include "Tree.h"

Tree::Tree(const char* name) : root(name) {
	current = &root;
};

void Tree::addBranch(const char* name) {
	(*current).addBranch(name);
}

void Tree::remBranch(const char* name) {
	(*current).remBranch(name);
}

void Tree::view(int x, int y, bool last) {
	(*current).view(x, y, last);
}

void Tree::moveIn(const char* child) {
	current = (*current).getChild(child);
}

void Tree::moveOut() {
	current = (*current).getParent();
}