/******************************************************************************/
/*!
\file   application.cpp
\author Jeong Juyong
\par    email: jaykop.jy\@gmail.com
\date   2019/06/02(yy/mm/dd)

\description
Contains the methods of scene class
*/
/******************************************************************************/

#include <scene.hpp>
#include <object_manager.hpp>

// TODO
#include <iostream>
#include <application.hpp>
#include <input_handler.hpp>

jeBegin

SoundSystem* Scene::soundSystem_ = nullptr;
PhysicsSystme* Scene::physicsSystem_ = nullptr;
GraphicsSystem* Scene::graphicSystem_ = nullptr;
BehaviorSystem* Scene::behaviorSystem_ = nullptr;

void Scene::bind_system()
{
	//soundSystem_ = ;
	//physicsSystem_ = ;
	//graphicSystem_ = ;
	//behaviorSystem_ = ;
}

void Scene::unbind_system()
{
	//soundSystem_;
	//physicsSystem_;
	//graphicSystem_;
	//behaviorSystem_;
}

Scene::Scene(const char* name)
{
	// assign the scene name
	name_.assign(name);
}

Scene::~Scene()
{
}

void Scene::load()
{
}

void Scene::initialize()
{
	// bind the objects to the manager
	ObjectManager::objects_ = &objects_;
}

void Scene::update(float dt)
{
	//TODO
	//INPUT TEST CODE

	if (InputHandler::key_pressed(KEY::A))
		std::cout << "A\n";

	if (InputHandler::key_triggered(KEY::B))
		std::cout << "B\n";

	if (InputHandler::key_pressed(KEY::MOUSE_LEFT))
		std::cout << "MOUSE_LEFT\n";

	if (InputHandler::key_triggered(KEY::MOUSE_RIGHT))
		std::cout << "MOUSE_RIGHT\n";

	if (InputHandler::get_mouse_wheel_status() == InputHandler::MouseWheel::UP)
		std::cout << "Mouse Wheel Up\n";

	else if (InputHandler::get_mouse_wheel_status() == InputHandler::MouseWheel::DOWN)
		std::cout << "Mouse Wheel Down\n";

	if (InputHandler::key_pressed(KEY::ESC))
		Application::quit();
}

void Scene::close()
{
	// make sure current object map belongs to the current scene
	ObjectManager::objects_ = &objects_;

	// clear current object map
	ObjectManager::clear_objects();

	// initialize
	ObjectManager::objects_ = nullptr;
}

void Scene::unload()
{
}


const char* Scene::get_name() const
{
	return name_.c_str();
}

jeEnd