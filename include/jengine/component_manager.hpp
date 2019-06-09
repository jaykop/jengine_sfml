/******************************************************************************/
/*!
\file   component_manager.hpp
\author Jeong Juyong
\par    email: jaykop.jy\@gmail.com
\date   2019/06/08(yy/mm/dd)

\description
Contains the definition of ComponentManager class
*/
/******************************************************************************/

#pragma once
#include <map>
#include <string>
#include <macros.hpp>

jeBegin

class Object;
class Component;
class ComponentBuilder;

using Directory = std::map<std::string, std::string>;
using BuilderMap = std::map<std::string, ComponentBuilder*>;

class ComponentManager {

	friend class Object;

private:

	static Component* create_component(const char* componentName);

	static const char* key_to_type(const char* name);
	static const char* type_to_key(const char* type);

	static void clear_builders();

	template <class ComponentType>
	static void register_builder(const char* componentName, ComponentBuilder* builder);

	static BuilderMap builderMap_;
	static Directory types_, keys_;
	 
};

jeEnd

#include <component_manager.inl>