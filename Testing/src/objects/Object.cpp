#include "Object.h"

Object::Object(const char* type) {
	Object::type = type;
	Object::name = nullptr;
	Object::obj = nullptr;
}

Object::Object(const char* name, const char* type){
	Object::name = name;
	Object::type = type;
	Object::obj = nullptr;
}

void Object::setObj(Object obj) {
	Object::obj = &obj;
}

const char* Object::getName() {
	return Object::name;
}

const char* Object::getType() {
	return Object::type;
}