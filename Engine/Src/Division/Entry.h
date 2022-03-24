#ifndef ENTRY_H
//se puede cambiar dependiendo de plataforma
extern Division::Application* Division::CreateApplication();
int main()
{
	
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

