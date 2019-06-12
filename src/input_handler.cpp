/******************************************************************************/
/*!
\file   input_handler.cpp
\author Jeong Juyong
\par    email: jaykop.jy\@gmail.com
\date   2019/06/11(yy/mm/dd)

\description
Contains the methods of InputHandler class
*/
/******************************************************************************/

#include <input_handler.hpp>
#include <debug_tool.hpp>

jeBegin

std::vector<KEY> InputHandler::keyQue;
KeyMap InputHandler::keyMap, InputHandler::triggerMap;
bool InputHandler::mouseDown = false, InputHandler::keyDown = false;

bool InputHandler::any_input_down()
{
	return mouseDown || keyDown;
}

bool InputHandler::any_key_down()
{
	return keyDown;
}

bool InputHandler::any_mouse_down()
{
	return mouseDown;
}

bool InputHandler::key_pressed(KEY key)
{
	return keyMap[key];
}

bool InputHandler::key_triggered(KEY key)
{
	return triggerMap[key];
}

KEY InputHandler::key_translator(sf::Event& event)
{
	// keyboards
	switch (event.key.code) {

		// alphabets
	case sf::Keyboard::A:
		return KEY::A;
	case sf::Keyboard::B:
		return KEY::B;
	case sf::Keyboard::C:
		return KEY::C;
	case sf::Keyboard::D:
		return KEY::D;
	case sf::Keyboard::E:
		return KEY::E;
	case sf::Keyboard::F:
		return KEY::F;
	case sf::Keyboard::G:
		return KEY::G;
	case sf::Keyboard::H:
		return KEY::H;
	case sf::Keyboard::I:
		return KEY::I;
	case sf::Keyboard::J:
		return KEY::J;
	case sf::Keyboard::K :
		return KEY::K;
	case sf::Keyboard::L:
		return KEY::L;
	case sf::Keyboard::M:
		return KEY::M;
	case sf::Keyboard::N:
		return KEY::N;
	case sf::Keyboard::O:
		return KEY::O;
	case sf::Keyboard::P:
		return KEY::P;
	case sf::Keyboard::Q:
		return KEY::Q;
	case sf::Keyboard::R:
		return KEY::R;
	case sf::Keyboard::S:
		return KEY::S;
	case sf::Keyboard::T:
		return KEY::T;
	case sf::Keyboard::U:
		return KEY::U;
	case sf::Keyboard::V:
		return KEY::V;
	case sf::Keyboard::W:
		return KEY::W;
	case sf::Keyboard::X:
		return KEY::X;
	case sf::Keyboard::Y:
		return KEY::Y;
	case sf::Keyboard::Z:
		return KEY::Z;

		// numbers
	case sf::Keyboard::Num0:
		return KEY::NUM_0;
	case sf::Keyboard::Num1:
		return KEY::NUM_1;
	case sf::Keyboard::Num2:
		return KEY::NUM_2;
	case sf::Keyboard::Num3:
		return KEY::NUM_3;
	case sf::Keyboard::Num4:
		return KEY::NUM_4;
	case sf::Keyboard::Num5:
		return KEY::NUM_5;
	case sf::Keyboard::Num6:
		return KEY::NUM_6;
	case sf::Keyboard::Num7:
		return KEY::NUM_7;
	case sf::Keyboard::Num8:
		return KEY::NUM_8;
	case sf::Keyboard::Num9:
		return KEY::NUM_9;

		// function keys
	case sf::Keyboard::Escape:
		return KEY::ESC;
	case sf::Keyboard::LControl:
		return KEY::LCONTROL;
	case sf::Keyboard::LShift:
		return KEY::LSHIFT;
	case sf::Keyboard::LAlt:
		return KEY::LALT;
	case sf::Keyboard::RControl:
		return KEY::RCONTROL;
	case sf::Keyboard::RShift:
		return KEY::RSHIFT;
	case sf::Keyboard::RAlt:
		return KEY::RALT;
	case sf::Keyboard::Space:
		return KEY::SPACE;
	case sf::Keyboard::Enter:
		return KEY::ENTER;
	case sf::Keyboard::Backspace:
		return KEY::BACK;
	case sf::Keyboard::Tab:
		return KEY::TAB;

		// arrows
	case sf::Keyboard::Left:
		return KEY::LEFT;
	case sf::Keyboard::Right:
		return KEY::RIGHT;
	case sf::Keyboard::Up:
		return KEY::UP;
	case sf::Keyboard::Down:
		return KEY::DOWN;
	}

	// mouse
	switch (event.mouseButton.button) {
	
	case sf::Mouse::Button::Left:
		return KEY::MOUSE_LEFT;
	case sf::Mouse::Button::Right:
		return KEY::MOUSE_RIGHT;
	case sf::Mouse::Button::Middle:
		return KEY::MOUSE_MIDDLE;
	}

	// mouse wheel
	/*witch (event.mouseWheel.delta) {

	default:
		return KEY::NONE;
		break;
	}*/

	// None of key pressed
	return KEY::NONE;
}

void InputHandler::initialize()
{
	// initialize values in the map
	for (int key = KEY::NONE; key <= KEY::END; key++) {
		
		// generate an instance
		KeyMap::value_type pair { KEY(key), false };
		
		// insert to the maps
		keyMap.insert(pair);
		triggerMap.insert(pair);
	}
}

void InputHandler::update(sf::Event& event)
{
	//if (event.type == sf::Event::KeyReleased)
		//;

	// add to the que
	keyQue.push_back(key_translator(event));

	for (auto key : keyQue)
		keyMap[key] = true;
}

// this function is called just before the PollFvent function
void InputHandler::refresh()
{
	// set default values
	for (auto key : keyQue)
		keyMap[key] = false;

	keyQue.clear();
}

void InputHandler::close()
{
	keyMap.clear();
	keyQue.clear();
}

jeEnd
