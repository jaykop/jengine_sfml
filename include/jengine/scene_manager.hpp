/******************************************************************************/
/*!
\file   application.cpp
\author Jeong Juyong
\par    email: jaykop.jy\@gmail.com
\date   2019/06/02(yy/mm/dd)

\description
Contains the definition of SceneManager class
*/
/******************************************************************************/

#pragma once

// Main scene manager class
#include <vector>
#include <string>
#include <Window.hpp>
#include <timer.hpp>

jeBegin

class Scene;
class ObjectContainer;
using Scenes = std::vector<Scene*>;

class SceneManager {

	enum SceneStatus {
		JE_STATE_NONE, 
		JE_STATE_RESTART, 
		JE_STATE_PAUSE, 
		JE_STATE_RESUME, 
		JE_STATE_CHANGE, 
		JE_STATE_RESUME_AND_CHANGE, 
		JE_STATE_QUIT
	};

public:

	static void quit();
	static void restart();
	static void resume();
	static void pause(const char* nextState);
	static bool is_paused();
	static void set_next_scene(const char* nextState);
	static void resume_and_next(const char* nextState);
	static void set_first_scene(const char* stateName);

	static SceneStatus	get_status(void);
	static Scene* get_current_scene(void);
	static Scene* get_scene(const char* stateName);
	static bool	has_state(const char* stateName);
	static float get_current_time();
	static float get_frame_rate();
	static unsigned	get_frame_per_second();

private:

	// Private member functions
	static bool intialize(SDL_Window* pWindow);
	static void update(SDL_Event* pEvent);
	static void close();

	static void push_scene(const char* path, const char* stateName);
	static void pop_scene(const char* stateName);

	static void change_scene();
	static void clear_scenes();

	// Private member variables
	static float frameTime_;
	static unsigned frames_;
	static Timer timer_;
	static Scenes states_;
	static SceneStatus status__;
	static Scene* current_, * next;
	static sf::Window * window_;
	static std::string	firstState_;

	// Prevent to clone this class
	SceneManager() = delete;
	~SceneManager() = delete;
	SceneManager(SceneManager&&) = delete;
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator= (SceneManager&&) = delete;
	SceneManager& operator= (const SceneManager&) = delete;

};

using STATE = SceneManager;

jeEnd