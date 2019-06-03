#include "application.hpp"

int main()
{

	JE::Application::AppData data;
	data.height = 600;
	data.width = 800;
	data.title = "unicket";
	data.isFullscreen = true;
	// data.icon = ;
	
	JE::Application::open_console();
	JE::Application::run(data);
	JE::Application::close_console();

	return 0;
}