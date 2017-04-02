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
	/* for (Component* currentComponent : vComponents) {
		if (currentComponent->getCanTick())
			currentComponent->update(TODO);

	}*/
	for (Object *currentObject : vObjects) {
		currentObject->update(DeltaTime);
	}
}

void Scene::updateOutput()
{
	/* for (MeshComponent* currentMesh : vMeshComponents) {
		currentMesh->display();
	}*/
	for (Component* currentComponent : vDisplayComponents) {
		currentComponent->display();
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

void Scene::addDisplayComponent(Component* newComponent)
{
	vDisplayComponents.push_back(newComponent);
}

void Scene::addComponent(Component* newComponent)
{
	vComponents.push_back(newComponent);
}

