#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Pro {

	class PRO_API Log {
	public:
		static void init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

#define PRO_CORE_TRACE(...)    ::Pro::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PRO_CORE_DEBUG(...)    ::Pro::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define PRO_CORE_INFO(...)     ::Pro::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PRO_CORE_WARN(...)     ::Pro::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PRO_CORE_ERROR(...)    ::Pro::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PRO_CORE_CRITICAL(...) ::Pro::Log::GetCoreLogger()->critical(__VA_ARGS__)


#define PRO_TRACE(...)         ::Pro::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PRO_DEBUG(...)         ::Pro::Log::GetClientLogger()->debug(__VA_ARGS__)
#define PRO_INFO(...)          ::Pro::Log::GetClientLogger()->info(__VA_ARGS__)
#define PRO_WARN(...)          ::Pro::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PRO_ERROR(...)         ::Pro::Log::GetClientLogger()->error(__VA_ARGS__)
#define PRO_CRITICAL(...)      ::Pro::Log::GetClientLogger()->critical(__VA_ARGS__)