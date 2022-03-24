#ifndef ENTRY_H
#define ENTRY_H
//se puede cambiar dependiendo de plataforma
extern Division::Application* Division::CreateApplication();
int main()
{
	Division::Log::Init();
	DIV_CORE_WARN("Initialized Log!");
	int a = 10;
	DIV_INFO("Hello! var example = {0}", a);

	auto app = Division::CreateApplication();
	if (app != nullptr) {
		app->Run();
		delete app;
		app = nullptr;
		return 0;
	}
	return -1;
}


#endif // !ENTRY_H

