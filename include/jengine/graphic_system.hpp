/******************************************************************************/
/*!
\file   graphic_system.hpp
\author Jeong Juyong
\par    email: jaykop.jy\@gmail.com
\date   2019/06/15(yy/mm/dd)

\description
Contains the definition of GraphicSystem class
*/
/******************************************************************************/

#pragma once
#include <macros.hpp>

jeBegin

class GraphicSystem {

	friend class Scene;

public:



private:

	static void initialize();
	static void update();
	static void close();

	GraphicSystem() = delete;
	~GraphicSystem() = delete;
	GraphicSystem(GraphicSystem&&) = delete;
	GraphicSystem(const GraphicSystem&) = delete;
	GraphicSystem& operator=(GraphicSystem&&) = delete;
	GraphicSystem& operator=(const GraphicSystem&) = delete;

};

jeEnd