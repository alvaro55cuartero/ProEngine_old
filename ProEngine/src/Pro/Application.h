#pragma once
#include "Pro/Core.h"
#include "Pro/events/Event.h"

namespace Pro {

	class PRO_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}
