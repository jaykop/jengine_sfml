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

jeBegin

SoundSystem* Scene::soundSystem_ = nullptr;
PhysicsSystme* Scene::physicsSystem_ = nullptr;
GraphicsSystem* Scene::graphicSystem_ = nullptr;
BehaviorSystem* Scene::behaviorSystem_ = nullptr;

void Scene::BindSystems()
{
}

void Scene::UnbindSystems()
{
}

Scene::Scene(const char* name)
{

}

Scene::~Scene()
{
}

void Scene::load()
{
}

void Scene::initialize()
{
}

void Scene::update(float dt)
{
}

void Scene::close()
{
}

void Scene::unload()
{
}

void Scene::clear_container()
{
}

const char* Scene::get_name() const
{
	return name_.c_str();
}

jeEnd