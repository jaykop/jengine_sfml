/******************************************************************************/
/*!
\file   scene_manager.cpp
\author Jeong Juyong
\par    email: jaykop.jy\@gmail.com
\date   2019/06/02(yy/mm/dd)

\description
Contains the methods of SceneManager class
*/
/******************************************************************************/

#include <timer.hpp>
#include <scene.hpp>
#include <scene_manager.hpp>
#include <input_handler.hpp>

jeBegin

// constant value
const float SECOND = 1.f, MAX_FRAME_TIME = 0.25f;

// Initialize the static variables
Timer SceneManager::timer_;
int SceneManager::frames_ = 0;
float SceneManager::frameTime_ = 0.f;
sf::Window* SceneManager::window_ = nullptr;
Scene* SceneManager::currentScene_ = nullptr;
SceneManager::SceneStatus SceneManager::status_ = SceneManager::SceneStatus::JE_STATE_NONE;

bool SceneManager::initialize(sf::Window* window)
{
	if (window) {
		
		window_ = window;
		
		// Initialize input system
		
		// 

		// bind current state's system
		Scene::bind_system();
		
		return true;
	}

	return false;
}

void SceneManager::update(sf::Event* event)
{
	static float timeStack, elapsedTime, currentTime;
	timeStack = elapsedTime = currentTime = 0.f;

	timer_.start();
	change_scene();

	while (window_->pollEvent(*event)
		|| status_ == JE_STATE_NONE) // state updating loop
	{
		InputHandler::update(*event);
		
		elapsedTime = timer_.get_elapsed_time(); // get elapsed time
		frameTime_ = elapsedTime - currentTime; // get frame time

		// Manually block the rfame skipping
		if (frameTime_ > MAX_FRAME_TIME)
			frameTime_ = MAX_FRAME_TIME;

		timeStack += frameTime_; // stack timer
		frames_++; // stack frames

		// Update the scene and systems
		if (timeStack >= SECOND) {

			currentTime = elapsedTime; // refresh the current time
			currentScene_->update(frameTime_); // update the current scene
			InputHandler::mouse_refresh(*event); // refresh mouse wheel status

			frames_ = 0;
			timeStack = 0.f;

			// Update the window
			window_->display();

		}
	}
}

void SceneManager::close()
{
	clear_scenes();
	Scene::unbind_system();
}

jeEnd