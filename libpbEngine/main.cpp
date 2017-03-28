#include <iostream>
#include "Game.h"
#include "Scene.h"
#include "Object.h"
#include "TransformComponent.h"


int main(void) {

	Game gHelloWorld("HelloWorld");

	if (!gHelloWorld.init()) {
		std::cerr << "Can't initialize game engine." << std::endl;
		return 1;
	}

	Scene* myScene = new Scene();
	Object *myObject = new Object(myScene);
	myObject->addComponent<TransformComponent>();
	myObject->addComponent<MeshComponent>();


	myScene->addObject(myObject);
	
	gHelloWorld.changeScene(myScene);
	gHelloWorld.start();
	

	while (gHelloWorld.isPlaying()) {
		gHelloWorld.update();
	}

	return 0;
}