#include "Rabbit.h"



Rabbit::Rabbit() : Object()
{
}


Rabbit::Rabbit(Scene* currentScene) : Object("Rabbit", currentScene)
{
	tTransform = (TransformComponent*) addComponent<TransformComponent>();
	mMesh = (MeshComponent*)addComponent<MeshComponent>();
	cCamera = (CameraComponent*)addComponent<CameraComponent>();
	bCollider = (BoxCollider*)addComponent<BoxCollider>();
	rRigidBody = (RigidBody*)addComponent<RigidBody>();
	rRigidBody->setUseGravity(false);

	bCollider->setSize(glm::vec3(1.f, 1.f, 1.f));

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
	Object::update(DeltaTime);

	if(Input::isPressing(GLFW_KEY_UP))
		tTransform->vPosition.x -= 1.f*DeltaTime;

	if (Input::isPressing(GLFW_KEY_DOWN))
		tTransform->vPosition.x += 1.f*DeltaTime;
}
