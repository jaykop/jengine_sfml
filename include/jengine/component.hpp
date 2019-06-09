/******************************************************************************/
/*!
\file   component.hpp
\author Jeong Juyong
\par    email: jaykop.jy\@gmail.com
\date   2019/06/08(yy/mm/dd)

\description
Contains the definition of component class
*/
/******************************************************************************/

#pragma once
#include <macros.hpp>
#include <json_parser.hpp>

jeBegin

class Component {

	friend class Object;

public:

	Object* get_owner() const { return owner_; }
	virtual void Register() = 0;

protected:

	virtual void Load(const rapidjson::Value& data) = 0;

	Component(Object* owner) : owner_(owner) {}
	virtual ~Component() {}

private:

	Object* owner_ = nullptr;
	bool bulitIn_ = false;
	std::string typeName_;

	// No default constructor
	Component() = delete;

};

jeEnd