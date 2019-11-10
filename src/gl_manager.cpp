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
#include <shader.hpp>
#include <json_parser.hpp>

jeBegin

GLManager::Shaders GLManager::shader_;
GLint GLManager::buffers_, GLManager::samples_, GLManager::attributes_;

void GLManager::initialize()
{
	// force GLEW to use a modern OpenGL method
	glewExperimental = GL_TRUE;

	// before using shader, initialize glew.
	DEBUG_ASSERT(glewInit() == GLEW_OK, "Failed to initialize GLEW");

	// show GL version info
	const GLubyte* pRenderer_ = glGetString(GL_RENDERER);
	const GLubyte* pVendor_ = glGetString(GL_VENDOR);
	const GLubyte* pVersion_ = glGetString(GL_VERSION);
	const GLubyte* pGlslVersion_ = glGetString(GL_SHADING_LANGUAGE_VERSION);

	glGetIntegerv(GL_SAMPLE_BUFFERS, &buffers_);
	glGetIntegerv(GL_SAMPLES, &samples_);

	jeDebugPrint("*GLManager - GL Vendor: %s / GL Renderer: %s\n", pVendor_, pRenderer_);
	jeDebugPrint("*GLManager - GL Version: %s\n", pVersion_);
	jeDebugPrint("*GLManager - GLSL Version: %s\n", pGlslVersion_);
	jeDebugPrint("*GLManager - GL Samples: %d / GL Sample Buffers: %d\n", samples_, buffers_);

	// show how many attributes are available
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &attributes_);
	jeDebugPrint("*GLManager - Maximum number of vertex attributes supported: %d\n", attributes_);

	initialize_shaders();

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
	for (unsigned i = 0; i < JE_SHADER_END; ++i) 
		delete shader_[i];

	shader_.clear();
}

void GLManager::initialize_shaders()
{
	// do shader stuff
	for (unsigned i = 0; i < JE_SHADER_END; ++i) {

		shader_.push_back(new Shader);
		shader_[i]->create_shader(Shader::vsDirectory_[i], Shader::JE_VERTEX);

		// TODO
		// Work on geometry shader
		//shader_[i]->CreateShader(Shader::m_geometryShader[i], Shader::JE_GEOMETRY);

		shader_[i]->create_shader(Shader::fsDirectory_[i], Shader::JE_PIXEL);

		shader_[i]->combine_shaders();
	}

	jeDebugPrint("*GLManager - Compiled and linked shaders.\n");
}
//
//sf::ContextSettings GLManager::get_context_settings()
//{
//
//
//	return settings;
//}

jeEnd