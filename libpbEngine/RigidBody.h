#pragma once
#include "Component.h"
#include "glm.hpp"
#include "TransformComponent.h"
#include "Object.h"


class RigidBody : public Component
{
private:
	glm::vec3 vCurrentAcceleration;
	glm::vec3 vCurrentVelocity;
	float fMass;
	bool bGravity;

public:
	RigidBody();
	~RigidBody();

	virtual void create();
	virtual void start();
	virtual void update(float deltaTime);

	void setUseGravity(bool useGravity);
};

