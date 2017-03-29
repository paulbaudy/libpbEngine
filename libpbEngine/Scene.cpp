#include "Scene.h"

CameraComponent* Scene::cCurrentCamera = nullptr;

Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::update(float deltaTime)
{
	updateLogic(deltaTime);
	updateOutput();
}

void Scene::clean()
{

}

void Scene::updateLogic(float DeltaTime)
{
	for (Object *currentObject : vObjects) {
		currentObject->update(DeltaTime);
	}
}

void Scene::updateOutput()
{
	for (MeshComponent* currentMesh : vMeshComponents) {
		currentMesh->display();
	}
}



void Scene::addObject(Object *newObject)
{
	if (!newObject) {
		std::cerr << "Invalid new object" << std::endl;
		return;
	}

	vObjects.push_back(newObject);
}

void Scene::addMeshComponent(MeshComponent* newMesh)
{
	vMeshComponents.push_back(newMesh);
}

