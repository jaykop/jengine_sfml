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

#include <OpenGL.hpp>
#include <macros.hpp>

jeBegin

class GLManager
{
public:

	static void initialize();
	static void update();
	static void close();

private:

	GLuint a;

	GLManager() = delete;
	~GLManager() = delete;
	GLManager(GLManager&&) = delete;
	GLManager(const GLManager&) = delete;
	GLManager& operator= (GLManager&&) = delete;
	GLManager& operator= (const GLManager&) = delete;
};

jeEnd