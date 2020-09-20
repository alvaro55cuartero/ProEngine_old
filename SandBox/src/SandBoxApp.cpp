#include <ProEngine.h>


class EX : public Pro::Layer {
public:
	EX() :Layer("a") {

	}
};

class SandBox : public Pro::Application {
public :
	SandBox() {
		PushLayer(new EX());
	} 

	~SandBox() {

	}
};


Pro::Application* Pro::CreateApplication() {
	return new SandBox();
}

