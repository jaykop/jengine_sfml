/******************************************************************************/
/*!
\file   application.cpp
\author Jeong Juyong
\par    email: jaykop.jy\@gmail.com
\date   2019/06/02(yy/mm/dd)

\description
Contains the methods of application class
*/
/******************************************************************************/

#include <application.hpp>
#include <debug_console.hpp>
#include <scene_manager.hpp>
#include <json_parser.hpp>

jeBegin

// Initialize the static variables
Application::AppData Application::data_;
sf::Event Application::event_;
sf::Window Application::window_;
std::string Application::dataDirectory_;

void Application::run()
{
	// If initialization succeeded, run the app
	if (initialize()) {
		
		update();
		close();
	}
}

bool Application::initialize()
{
	// Load app init data
	JsonParser::read_file(dataDirectory_.c_str());

	const rapidjson::Value& title = JsonParser::get_document()["Title"];
	const rapidjson::Value& fullscreen = JsonParser::get_document()["Fullscreen"];
	const rapidjson::Value& width = JsonParser::get_document()["Width"];
	const rapidjson::Value& height = JsonParser::get_document()["Height"];
	const rapidjson::Value& icon = JsonParser::get_document()["Icon"];

	if (title.IsString() && fullscreen.IsBool()
		&& width.IsInt() && height.IsInt()
		&& icon.IsString()) {

		data_.title.assign(title.GetString());
		data_.icon.assign(icon.GetString());
		data_.isFullscreen = fullscreen.GetBool();
		data_.width = width.GetInt();
		data_.height = height.GetInt();
	}

	// TODO: REDO THE FULLSCREEN PART
	// Create window
	/*if (data_.isFullscreen)
		window_.create(sf::VideoMode(data_.width, data_.height), data_.title, sf::Style::Fullscreen);
	else */
	window_.create(sf::VideoMode(data_.width, data_.height), data_.title.c_str());

	window_.setFramerateLimit(60);	// limit 60 frames
	window_.setVerticalSyncEnabled(true); // Activate vSync

	return true;
}

void Application::update()
{
	// If the intiailization does not have done properly,
	// stop updating the scene manager
	if (!SceneManager::initialize(&window_))
		return;

	// Update the window while it is open
	while (window_.isOpen())
		SceneManager::update(&event_); // update the scene
	
	// Close the scene manager
	SceneManager::close();
}

void Application::close()
{
	window_.close();
}

void Application::open_console()
{
	// Pop a console window
	DEBUG_LEAK_CHECKS(-1);
	DEBUG_CREATE_CONSOLE();
}

void Application::close_console()
{
	// Destroy the console window
	DEBUG_DESTROY_CONSOLE();
}

void Application::set_data_directory(const char* directory)
{
	dataDirectory_.assign(directory);
}

jeEnd