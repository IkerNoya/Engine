#ifndef CORE_H
#define CORE_H
#ifdef DIV_BUILD_DLL
#define DIVISION_API __declspec(dllexport)
#else
#define DIVISION_API __declspec(dllimport)
#endif // HZ_BUILD_DLL

#ifdef DIV_DEBUG
	#define DIV_ENABLE_ASSERTS
#endif

#ifdef DIV_ENABLE_ASSERTS
	#define DIV_ASSERT(x, ...) { if (!(x)) { DIV_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak; } }
	#define DIV_CORE_ASSERT(x, ...) { if (!(x)) { DIV_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak; } }
#else
	#define DIV_ASSERT(x, ...)
	#define DIV_CORE_ASSERT(x, ...)
#endif

//se setea un bitfield moviendo a 1 en x cantidad de lugares
#define BIT(x) (1 << x)
#define DIV_BIND_EVENT(x)    std::bind(&x, this, std::placeholders::_1)


#endif // !CORE_H

