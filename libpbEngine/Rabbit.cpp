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

void Rabbit::update(float DeltaTime)
{
	if(Input::isPressing(GLFW_KEY_UP))
		tTransform->vPosition.x -= 1.f*DeltaTime;

	if (Input::isPressing(GLFW_KEY_DOWN))
		tTransform->vPosition.x += 1.f*DeltaTime;
}
