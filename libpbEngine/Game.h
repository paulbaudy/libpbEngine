#pragma once
#include <iostream>

//Include OpenGl libraries 
#include "glew.h"
#include "glfw3.h"

//Include the standard C++ headers   
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <string>

#include "glm.hpp"

#include "Scene.h"

class Game
{
private:
	/* Game name. Window title */
	std::string sGameName; 

	/* Game is currently running */
	bool bPlaying;

	Scene *sCurrentScene;

	GLFWwindow* window;


	void updateInput();

	/* Initialize Render API */
	bool initOpenGl();
	bool initVulkan();
	bool initDirectX();

public:
	Game();
	Game(std::string GameName);
	~Game();


	bool init();
	void start();
	bool isPlaying() const;

	void update();
	void changeScene(Scene *newScene);
};

