#pragma once

#include "Object.h"
#include "Scene.h"

#include "TransformComponent.h"
#include "MeshComponent.h"
#include "CameraComponent.h"
#include "Input.h"

class Rabbit : public Object
{
private:
	TransformComponent* tTransform;
	MeshComponent* mMesh;
	CameraComponent* cCamera;

public:
	Rabbit();
	Rabbit(Scene* currentScene);
	~Rabbit();

	virtual void start();
	virtual void update(float DeltaTime);
};

