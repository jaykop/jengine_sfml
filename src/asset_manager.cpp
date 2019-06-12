/******************************************************************************/
/*!
\file   asset_manager.cpp
\author Jeong Juyong
\par    email: jaykop.jy\@gmail.com
\date   2019/06/03(yy/mm/dd)

\description
Contains the methods of asset_manager class
*/
/******************************************************************************/

#include <thread>
#include <json_parser.hpp>
#include <asset_manager.hpp>
#include <debug_tool.hpp>
#include <scene_manager.hpp>

jeBegin

std::string	AssetManager::initDirectory_, AssetManager::assetDirectory_, 
AssetManager::stateDirectory_, AssetManager::archeDirectory_;

bool AssetManager::set_bulit_in_components()
{
	return false;
}

void AssetManager::load_assets()
{
	// Read scene info
	JsonParser::read_file(stateDirectory_.c_str());
	const rapidjson::Value& scenes = JsonParser::get_document()["Scene"];

	//// Read asset info
	//JsonParser::read_file(assetDirectory_.c_str());
	//const rapidjson::Value& textures = JsonParser::get_document()["Texture"];

	//// Read font info
	//const rapidjson::Value& fonts = JsonParser::get_document()["Font"];

	// Get sizes of them
	unsigned sceneSize = scenes.Size();
		//textureSize = textures.Size(),
		//fontSize = fonts.Size();

	// Load scenes using thread
	for (rapidjson::SizeType i = 0; i < sceneSize; ++i) {
		std::thread stateLoader(&SceneManager::push_scene, scenes[i]["Directory"].GetString(), scenes[i]["Key"].GetString());
		stateLoader.join();
		jeDebugPrint("Loaded %s\n", scenes[i]["Key"].GetString());
	}

	// Set first state
	const rapidjson::Value& fristStates = JsonParser::get_document()["FirstScene"];
	std::string firstStateName = SceneManager::firstScene_.empty() ? fristStates.GetString() : SceneManager::firstScene_;
	SceneManager::set_first_scene(firstStateName.c_str());
	jeDebugPrint("The first scene is %s.\n", firstStateName.c_str());

	//// Load images using thread
	//for (rapidjson::SizeType i = 0; i < textureSize; ++i) {
	//	std::thread imageLoader(&LoadImage, textures[i]["Directory"].GetString(), textures[i]["Key"].GetString());
	//	imageLoader.join();
	//	jeDebugPrint("*AssetManager - Loaded image: %s.\n", textures[i]["Directory"].GetString());
	//}

	//// Register images to gpu
	//for (auto it : images_)
	//	RegisterImage(it.second, it.first.c_str());

	// Load font
	//for (rapidjson::SizeType i = 0; i < fontSize; ++i) {

	//	// Load default ascii characters (0 - 128)
	//	LoadFont(fonts[i]["Directory"].GetString(), fonts[i]["Key"].GetString(), fonts[i]["Size"].GetUint(),
	//		0, 128);

	//	// Load additional unicode set
	//	for (unsigned j = 0; j < fonts[i]["Additional"].Size(); ++j) {
	//		LoadFont(fonts[i]["Directory"].GetString(), fonts[i]["Key"].GetString(), fonts[i]["Size"].GetUint(),
	//			static_cast<unsigned long>(fonts[i]["Additional"][j][0].GetUint64()),
	//			static_cast<unsigned long>(fonts[i]["Additional"][j][1].GetUint64()));
	//	}
	//}

}

void AssetManager::unload_assets()
{
}

void AssetManager::set_initdata_directory(const char* dir) { initDirectory_.assign(dir); }

void AssetManager::set_asset_directory(const char* dir) { assetDirectory_.assign(dir); }

void AssetManager::set_scene_directory(const char* dir) { stateDirectory_.assign(dir); }

void AssetManager::set_archetype_directory(const char* dir) { archeDirectory_.assign(dir); }

jeEnd