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
class SoundSystem;
class PhysicsSystme;
class GraphicsSystem;
class BehaviorSystem;

// Generic scene class
class Scene {

	// Only SceneManager can manage this class
	friend class SceneManager;

public:

	const char* get_name() const;

private:

	static void BindSystems();
	static void UnbindSystems();

	Scene(const char* name);
	~Scene();

	void load();
	void initialize();
	void update(float dt);
	void close();
	void unload();

	void clear_container();

	Scene* lastScene_ = nullptr; // pointer to the last scene (before this scene)
	std::string	name_, // scene name
		directory_; // directory of this scene

	// container
	ObjectContainer* objContainer_ = nullptr;

	// Systems 
	static SoundSystem* soundSystem_;
	static PhysicsSystme* physicsSystem_;
	static GraphicsSystem* graphicSystem_;
	static BehaviorSystem* behaviorSystem_;

	// Prevent to clone this class
	Scene() = delete;
	Scene(Scene&&) = delete;
	Scene(const Scene&) = delete;
	Scene& operator= (Scene&&) = delete;
	Scene& operator= (const Scene&) = delete;
};

jeEnd
