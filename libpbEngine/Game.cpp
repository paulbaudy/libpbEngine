#include "Game.h"

void Game::handleInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Input::aPressedKeys[key] = action;
}

void Game::updateInput()
{
	glfwPollEvents();
}

bool Game::initOpenGl()
{
	//Initialize GLFW  
	if (!glfwInit())
	{
		std::cerr << "Fail to initialize glfw" << std::endl;
		return false;
	}

	//OpenGl Hints
	glfwWindowHint(GLFW_SAMPLES, 4); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

	window = glfwCreateWindow(1024, 768, sGameName.c_str(), NULL, NULL);
	if (window == NULL) {
		std::cerr << "Fail to create window" << std::endl;
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);
	glewExperimental = true; 

	if (glewInit() != GLEW_OK) {
		std::cerr << "Fail to initialize glew" << std::endl;
		return false;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	glfwSetKeyCallback(window, Game::handleInput);
	glLineWidth(5.0f);
	// Enable depth test
	glEnable(GL_DEPTH_TEST);


	return true;
}

Game::Game()
{
	sGameName = "Untitled game";
	sCurrentScene = nullptr;
	bPlaying = false;
}


Game::Game(std::string GameName)
{
	sGameName = GameName;
	sCurrentScene = nullptr;
	bPlaying = false;
}

Game::~Game()
{
}

bool Game::init()
{
	return initOpenGl();
}

void Game::start()
{
	if (!sCurrentScene) {
		std::cerr << "Can't start playing. No scene declared." << std::endl;
		return; 
	}
	
	bPlaying = true;
	oldClock = clock();
	newClock = clock();
}

bool Game::isPlaying() const
{
	return bPlaying;
}

void Game::update()
{
	oldClock = newClock;
	newClock = clock();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	updateInput();
	sCurrentScene->update( ((float) (newClock - oldClock)) / CLOCKS_PER_SEC);

	glfwSwapBuffers(window);
}

void Game::changeScene(Scene *newScene)
{
	if (!newScene) {
		std::cerr << "Invalid new scene" << std::endl;
		return;
	}
	if (sCurrentScene) sCurrentScene->clean();

	sCurrentScene = newScene;
}
