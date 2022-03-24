#ifndef APP_H
#define APP_H
#include "../Core.h"

namespace Division
{
	class DIVISION_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	Application* CreateApplication();
}


#endif // !APP_H



