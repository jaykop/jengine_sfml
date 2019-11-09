/******************************************************************************/
/*!
\file   gl_manager.hpp
\author Jeong Juyong
\par    email: jaykop.jy\@gmail.com
\date   2019/06/15(yy/mm/dd)

\description
Contains the definition of GLManager class
*/
/******************************************************************************/
#pragma once

#include <glew.h>
#define GLEW_STATIC
#include <OpenGL.hpp>
#include <Window.hpp>
#include <macros.hpp>

jeBegin

class GLManager
{
	friend class Application;
	friend class SceneManager;

public:

private:

	static void initialize();
	static void update(const sf::Event& event);
	static void close();

	static void initialize_shaders();
	static void initialize_framebuffer(); 

	GLManager() = delete;
	~GLManager() = delete;
	GLManager(GLManager&&) = delete;
	GLManager(const GLManager&) = delete;
	GLManager& operator= (GLManager&&) = delete;
	GLManager& operator= (const GLManager&) = delete;
};

jeEnd