#include "application.hpp"

int main()
{
	JE::Application::set_data_directory("resource/initData.json");
	JE::Application::open_console();
	JE::Application::run();
	JE::Application::close_console();

	return 0;
}