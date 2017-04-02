#pragma once

#include <iostream>

#include "CameraComponent.h"
#include "Component.h"
#include "Object.h"
#include "MeshComponent.h"

class MeshComponent;

class Scene
{
private:
	std::string sceneName;

	std::vector<Object*> vObjects;
	std::vector<MeshComponent*> vMeshComponents;
	std::vector<Component*> vDisplayComponents;
	std::vector<Component*> vComponents;

	void updateLogic(float DeltaTime);
	void updateOutput();

public:
	Scene();
	~Scene();

	static CameraComponent* cCurrentCamera;

	void update(float deltaTime);
	void clean();

	void addObject(Object *newObject);
	void addMeshComponent(MeshComponent* newMesh);
	void addDisplayComponent(Component* newComponent);
	void addComponent(Component* newComponent);
};
