#pragma once
#include "Object.h"

class Int : public Object {
private:
	int value;
public:
	Int();
	Int(const char* name);
	Int(const char* name, int value);
	void setValue(int value);
	int getValue();
};

