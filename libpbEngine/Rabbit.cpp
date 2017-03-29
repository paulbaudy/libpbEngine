#include "Rabbit.h"



Rabbit::Rabbit()
{
}


Rabbit::Rabbit(Scene* currentScene) : Object("Rabbit", currentScene)
{
	tTransform = (TransformComponent*) addComponent<TransformComponent>();
	mMesh = (MeshComponent*)addComponent<MeshComponent>();
	cCamera = (CameraComponent*)addComponent<CameraComponent>();

	mMesh->setMesh("objects/rabbit.obj");
}

Rabbit::~Rabbit()
{
}

void Rabbit::start()
{

}

void Rabbit::update()
{

}
