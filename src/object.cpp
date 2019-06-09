/******************************************************************************/
/*!
\file   object.cpp
\author Jeong Juyong
\par    email: jaykop.jy\@gmail.com
\date   2019/06/08(yy/mm/dd)

\description
Contains the methods of Object class
*/
/******************************************************************************/

#include <object.hpp>
#include <component.hpp>
#include <debug_console.hpp>
#include <object_factory.hpp>
#include <object_container.hpp>
#include <component_manager.hpp>

jeBegin

Object::Object(const char* name)
	:name_(name), active_(true), parent_(nullptr)
{
	id_ = ObjectFactory::assign_id();
}

Object::~Object()
{
	clear_component();
	clear_children();
}

void Object::register_components()
{
	for (auto component : components_)
		component.second->add_to_system();
}

void Object::add_component(const char* componentName)
{
	static std::string typeName;
	typeName = ComponentManager::key_to_type(componentName);
	auto found = components_.find(typeName);

	DEBUG_ASSERT(found == components_.end(), "Trying to add an existing component!");

	Component* newComponent = ComponentManager::create_component(typeName.c_str());
	components_.insert(Components::value_type(typeName, newComponent));
}

Component* Object::get_component(const char* componentName)
{
	static std::string typeName;
	typeName = ComponentManager::key_to_type(componentName);
	auto found = components_.find(typeName);

	DEBUG_ASSERT(found != components_.end(), "No such name of component!");

	return found->second;
}

bool Object::has_component(const char* componentName)
{
	static std::string typeName;
	typeName = ComponentManager::key_to_type(componentName);
	auto found = components_.find(typeName);

	return found != components_.end();
}

void Object::remove_component(const char* componentName)
{
	static std::string typeName;
	typeName = ComponentManager::key_to_type(componentName);
	auto found = components_.find(typeName);

	DEBUG_ASSERT(found != components_.end(), "No such name of component!");

	delete found->second;
	found->second = nullptr;
}

void Object::add_child(Object* child)
{
	auto found = children_.find(child->get_name());
	DEBUG_ASSERT(found == children_.end(), "Trying to add an existing object!");
	children_.insert(Children::value_type(child->get_name(), child));
	child->set_parent(this);
}

void Object::remove_child(const char* name)
{
	auto found = children_.find(name);
	DEBUG_ASSERT(found != children_.end(), "No such child object!");
	return found->second;
}

bool Object::has_child(const char* name)
{
	auto found = children_.find(name);
	return found != children_.end();
}

Object* Object::get_child(const char* name)
{
	auto found = children_.find(name);
	DEBUG_ASSERT(found != children_.end(), "No such child object!");
	return found->second;
}

void Object::clear_children()
{
	for (auto child : children_)
		ObjectContainer::get_container()->RemoveObject(child.second);

	children_.clear();
}

void Object::clear_component()
{
	// Clear all components in the list
	for (auto component : components_) {

		if (component.second) {
			delete component.second;
			component.second = nullptr;
		}
	}

	components_.clear();
}

jeEnd