#include "dpch.h"

#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace Division
{
	std::shared_ptr<spdlog::logger>	Log::_CoreLogger;
	std::shared_ptr<spdlog::logger>	Log::_ClientLogger;

	void Log::Init() {
		//                                 time   name  msg
		spdlog::set_pattern("%^[%T] %n: %v%$");
		_CoreLogger = spdlog::stderr_color_mt("DIVISION");
		_CoreLogger->set_level(spdlog::level::trace);

		_ClientLogger = spdlog::stderr_color_mt("App");
		_ClientLogger->set_level(spdlog::level::trace);
	}
}	