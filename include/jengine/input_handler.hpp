/******************************************************************************/
/*!
\file   input_handler.hpp
\author Jeong Juyong
\par    email: jaykop.jy\@gmail.com
\date   2019/06/11(yy/mm/dd)

\description
Contains the definition of InputHandler class
*/
/******************************************************************************/
#pragma once
#include <vector>
#include <key_map.hpp>
#include <unordered_map>

jeBegin

class InputHandler {

	friend class Application;
	friend class SceneManager;

public:

	static bool any_key_down(); // check both mouse or key
	static bool any_mouse_down();
	static bool any_input_down();

	static bool key_pressed(KEY key);
	static bool key_triggered(KEY key);

	// mouse position
	
private:

	static KEY key_translator(sf::Event& event);
	static void initialize();
	static void update(sf::Event& event);
	static void refresh();
	static void close();

	static bool mouse_down, key_down;
	static std::vector<KEY>	key_que;
	static std::unordered_map<KEY, bool> key_map;

	InputHandler() = delete;
	~InputHandler() = delete;
	InputHandler(InputHandler&&) = delete;
	InputHandler& operator=(InputHandler&&) = delete;
	InputHandler(const InputHandler&) = delete;
	InputHandler& operator=(const InputHandler&) = delete;

};

jeEnd