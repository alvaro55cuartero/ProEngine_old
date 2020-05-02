#include "List.h"
#include "objects/Int.h"
#include "Objects/Object.h"

List::List() {
	objects.push_back(Int());
}

void List::addObj(const char* name) {
	Object* o = this->getObj(name);
	char temp[100];
	strcpy_s(temp, 100, name);
	if (!o) {
		Object obj(temp);
		objects.push_back(obj);
	}
}

Object* List::getObj(const char* name) {
	for (int i = 0; i < objects.size(); i++) {
		if (strcmp(objects[i].getType(), name) == 0) {
			return &(objects[i]);
		}
	}
	return nullptr;
}

void List::view() {
	for (Object o: objects) {
		std::cout << o.getType() << std::endl;
	}
}