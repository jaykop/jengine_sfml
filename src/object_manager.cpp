/******************************************************************************/
/*!
\file   object_manager.cpp
\author Jeong Juyong
\par    email: jaykop.jy\@gmail.com
\date   2019/06/08(yy/mm/dd)

\description
Contains the methods of ObjectManager class
*/
/******************************************************************************/

#include <object.hpp>
#include <debug_console.hpp>
#include <object_manager.hpp>

jeBegin

int ObjectManager::idGenerator_ = 0;
ObjectMap* ObjectManager::objects_ = nullptr;

Object* ObjectManager::create_object(const char* name)
{
	auto found = objects_->find(name);
	DEBUG_ASSERT(found == objects_->end(), "The object with same name is already in the map!");
	Object* newObject = new Object(name);

	return newObject;
}

void ObjectManager::remove_object(const char* name)
{
	auto toRemove = objects_->find(name);
	DEBUG_ASSERT(toRemove != objects_->end(), "No such name of object!");

	// delete the instance
	delete toRemove->second;
	toRemove->second = nullptr;

	// remove from the container
	objects_->erase(toRemove);
}

void ObjectManager::remove_object(Object* object)
{
	remove_object(object->get_name());
}

Object* ObjectManager::get_object(const char* name)
{
	auto toReturn = objects_->find(name);
	DEBUG_ASSERT(toReturn != objects_->end(), "No such name of object!");
	return toReturn->second;
}

bool ObjectManager::has_object(const char* name)
{
	auto toReturn = objects_->find(name);
	return toReturn != objects_->end();
}

ObjectMap* ObjectManager::get_objects()
{
	return objects_;
}

void ObjectManager::clear_objects()
{
	for (auto obj : *objects_) {
		
		delete obj.second;
		obj.second = nullptr;
	}

	objects_->clear();
}

int ObjectManager::assign_id()
{
	return idGenerator_++;
}

jeEnd