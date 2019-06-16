/******************************************************************************/
/*!
\file   gl_manager.cpp
\author Jeong Juyong
\par    email: jaykop.jy\@gmail.com
\date   2019/06/15(yy/mm/dd)

\description
Contains the methods of GLManager class
*/
/******************************************************************************/

#include <Window.hpp>
#include <gl_manager.hpp>

jeBegin

void GLManager::initialize()
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 3;
	settings.minorVersion = 3;

	sf::Window window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, settings);
}

void GLManager::update()
{
}

void GLManager::close()
{
}

jeEnd