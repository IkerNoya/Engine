#ifndef LOG_H
#define LOG_H
#include <memory>
#include "../Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Division
{
	class DIVISION_API  Log
	{
		static std::shared_ptr<spdlog::logger>_CoreLogger;
		static std::shared_ptr<spdlog::logger>_ClientLogger;
	public:
		static void Init(); 
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return _CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return _ClientLogger; }

	};
}
//Engine logs
#define DIV_CORE_ERROR(...)		::Division::Log::	GetCoreLogger()->error(__VA_ARGS__)
#define DIV_CORE_WARN(...)		::Division::Log::	GetCoreLogger()->warn(__VA_ARGS__)
#define DIV_CORE_INFO(...)			::Division::Log::	GetCoreLogger()->info(__VA_ARGS__)
#define DIV_CORE_TRACE(...)		::Division::Log::	GetCoreLogger()->trace(__VA_ARGS__)

//Client logs
#define DIV_ERROR(...)					::Division::Log::	GetClientLogger()->error(__VA_ARGS__)
#define DIV_WARN(...)					::Division::Log::	GetClientLogger()->warn(__VA_ARGS__)
#define DIV_INFO(...)					::Division::Log::	GetClientLogger()->info(__VA_ARGS__)
#define DIV_TRACE(...)					::Division::Log::	GetClientLogger()->trace(__VA_ARGS__)

#endif // !LOG_H



