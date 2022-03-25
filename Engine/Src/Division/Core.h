#ifndef CORE_H
#define CORE_H
#ifdef DIV_BUILD_DLL
#define DIVISION_API __declspec(dllexport)
#else
#define DIVISION_API __declspec(dllimport)
#endif // HZ_BUILD_DLL

//se setea un bitfield moviendo a 1 en x cantidad de lugares
#define BIT(x) (1 << x)


#endif // !CORE_H

