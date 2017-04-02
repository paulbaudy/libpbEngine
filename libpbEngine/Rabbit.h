#pragma once

#include "Object.h"
#include "Scene.h"

#include "TransformComponent.h"
#include "MeshComponent.h"
#include "CameraComponent.h"
#include "Input.h"
#include "BoxCollider.h"
#include "RigidBody.h"

class Rabbit : public Object
{
private:
	TransformComponent* tTransform;
	MeshComponent* mMesh;
	CameraComponent* cCamera;
	BoxCollider* bCollider;
	RigidBody* rRigidBody;

public:
	Rabbit();
	Rabbit(Scene* currentScene);
	~Rabbit();

	virtual void start();
	virtual void update(float DeltaTime);
};

