#pragma once

class Object {

private:
	const char* name;
	const char* type;
	Object* obj;

public:
	Object(const char* Type);
	Object(const char* name, const char* type);
	void setObj(Object obj);
	const char* getName();
	const char* getType();
};


