#include <Pro.h>

class SandBox : public Pro::Application {
public :
	SandBox() {

	} 

	~SandBox() {

	}
};


Pro::Application* Pro::CreateApplication() {
	return new SandBox();
}

