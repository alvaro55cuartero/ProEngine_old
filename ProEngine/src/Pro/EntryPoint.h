#pragma once

#ifdef PRO_PLATFORM_WINDOWS

extern Pro::Application* Pro::CreateApplication();

void main(int argc, char** argv) {
	printf("ProEngine");
	auto app = Pro::CreateApplication();
	app->Run();
	delete app;
}


#endif