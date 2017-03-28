#pragma once
#include <iostream>

#include "Component.h"
#include "Object.h"
#include "MeshComponent.h"

class Scene
{
private:
	std::string sceneName;

	std::vector<Object*> vObjects;
	std::vector<MeshComponent*> vMeshComponents;

	void updateLogic();
	void updateOutput();

public:
	Scene();
	~Scene();

	void update();
	void clean();

	void addObject(Object *newObject);
	void addMeshComponent(MeshComponent* newMesh);
};

