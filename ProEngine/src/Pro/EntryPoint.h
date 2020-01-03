#pragma once

#ifdef PRO_PLATFORM_WINDOWS

extern Pro::Application* Pro::CreateApplication();

void main(int argc, char** argv) {
	Pro::Log::init();
	PRO_CORE_INFO("ProEngine Running");
	PRO_INFO("App Running");

	auto app = Pro::CreateApplication();
	app->Run();
	delete app;
}


#endif