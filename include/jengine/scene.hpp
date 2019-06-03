/******************************************************************************/
/*!
\file   scene.hpp
\author Jeong Juyong
\par    email: jaykop.jy\@gmail.com
\date   2019/06/02(yy/mm/dd)

\description
Contains the definition of Scene class
*/
/******************************************************************************/

#pragma once
#include <string>
#include <macros.hpp>

jeBegin

class ObjectContainer;

// Generic scene class
class Scene {

	// Only SceneManager can manage this class
	friend class SceneManager;

public:

	const char* get_name() const;

private:

	Scene(const char* name);
	~Scene();

	void load();
	void initialize();
	void update(float dt);
	void close();
	void unload();

	void clear_container();

	Scene* lastScene_;
	std::string	name_, directory_;
	ObjectContainer* objContainer_;
};

jeEnd
