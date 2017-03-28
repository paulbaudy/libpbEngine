#include "Scene.h"

CameraComponent* Scene::cCurrentCamera = nullptr;

Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::update()
{
	updateLogic();
	updateOutput();
}

void Scene::clean()
{

}

void Scene::updateLogic()
{
	for (Object *currentObject : vObjects) {
		currentObject->update();
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

