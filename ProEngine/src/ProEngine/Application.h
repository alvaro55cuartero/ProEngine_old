#pragma once
#include "ProEngine/Core/Base.h"
#include "ProEngine/Core/LayerStack.h"
#include "ProEngine/events/Event.h"
#include "ProEngine/events/ApplicationEvent.h"
#include "ProEngine/Core/Window.h"

namespace Pro {

	class PRO_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();

}
