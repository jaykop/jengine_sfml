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

#include <gl_manager.hpp>
#include <debug_tool.hpp>

jeBegin

void GLManager::initialize()
{
	// force GLEW to use a modern OpenGL method
	glewExperimental = GL_TRUE;

	//Before using shader, initialize glew.
	DEBUG_ASSERT(glewInit() == GLEW_OK, "Failed to initialize GLEW");

}

void GLManager::update(const sf::Event& event)
{
	if (event.type == sf::Event::Resized)
		glViewport(0, 0, event.size.width, event.size.height);
	else if (event.type == sf::Event::Closed) {
		// TODO
	}
}

void GLManager::close()
{
}

void GLManager::initialize_shaders()
{

}
//
//sf::ContextSettings GLManager::get_context_settings()
//{
//
//
//	return settings;
//}

jeEnd