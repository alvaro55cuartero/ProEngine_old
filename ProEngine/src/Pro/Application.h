#pragma once
#include "Pro/Core.h"
#include "Pro/events/Event.h"
#include "Pro/events/ApplicationEvent.h"
#include "Window.h"

namespace Pro {

	class PRO_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication();

}
