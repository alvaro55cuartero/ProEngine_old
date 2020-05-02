#include "Int.h"

Int::Int() : Object("Int") {
	Int::value = 0;
}

Int::Int(const char* name) : Object(name, "int"){
	Int::value = 0;
}

Int::Int(const char* name, int value) : Object(name, "int"){
	Int::value = value;
}

void Int::setValue(int value) {
	Int::value = value;
}

int Int::getValue() {
	return Int::value;
}