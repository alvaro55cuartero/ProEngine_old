#include "propch.h"
#include "Application.h"

#include "Pro/events/ApplicationEvent.h"
#include "Pro/Log.h"

#include <GLFW/glfw3.h>

namespace Pro {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

	}

	Application::~Application() {

	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		PRO_CORE_TRACE("{0}", e);
	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		PRO_TRACE(e);

		while (m_Running) {
			
			
			glClearColor(1,0,1,1);
			glClear(GL_COLOR_BUFFER_BIT);
			glBegin(GL_TRIANGLES);
			glVertex2f(0.5,0.5);
			glVertex2f(-0.5,0.5);
			glVertex2f(0,0);
			glEnd();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}

}
