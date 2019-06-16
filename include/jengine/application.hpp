/******************************************************************************/
/*!
\file   application.hpp
\author Jeong Juyong
\par    email: jaykop.jy\@gmail.com
\date   2019/06/02(yy/mm/dd)

\description
Contains the definition of application class
*/
/******************************************************************************/

#pragma once
#include <Graphics/RenderWindow.hpp>
#include <string>
#include <macros.hpp>

jeBegin

// Main application class
class Application
{
public:

	// application data structure
	struct AppData {

		std::string	title;	// window title
		std::string icon;	// app icon directory
		bool isFullscreen = false;
		int	width = 800;
		int	height = 600;
	};

	static void run();
	static void quit();

	static AppData get_appdata();
	static void set_screensize(int w, int h);
	static void set_title(const std::string& title);
	static void set_fullscreen(bool isFullScreen);

private:

	static bool initialize();
	static void update();
	static void close();

	static void rendering_thread();

	static AppData data_;		
	static sf::Event event_;
	static sf::RenderWindow window_;
	static bool run_;

	// Prevent to clone this class
	Application() = delete;
	~Application() = delete;
	Application(Application&&) = delete;
	Application(const Application&) = delete;
	Application& operator= (Application&&) = delete;
	Application& operator= (const Application&) = delete;
};

jeEnd