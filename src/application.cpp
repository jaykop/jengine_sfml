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

jeBegin

// Initialize the static variables
Application::AppData Application::data_;
sf::Event Application::event_;
sf::Window Application::window_;

void Application::run(const AppData& data)
{
	// Assign the datas
	data_ = data;

	// If initialization succeeded, run the app
	if (initialize()) {
		
		update();
		close();
	}
}

bool Application::initialize()
{
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
	// Update the window while it is open
	while (window_.isOpen())
	{
		while (window_.pollEvent(event_))
		{
			if (event_.type == sf::Event::Closed)
				window_.close();
		}

		window_.display();
	}
}

void Application::close()
{
	// window_.close();
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

jeEnd