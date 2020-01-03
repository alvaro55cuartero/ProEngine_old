#include "Application.h"

#include "Pro/events/ApplicationEvent.h"
#include "Pro/Log.h"

namespace Pro {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		PRO_TRACE(e);
		while (true);
	}

}
