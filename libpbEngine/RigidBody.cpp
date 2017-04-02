#include "RigidBody.h"



RigidBody::RigidBody() : Component()
{
	bCanTick = true;
	bCanDisplay = false;
	iComponentID = 5;

	/* Default values */
	fMass = 1.f;
	bGravity = true;
}


RigidBody::~RigidBody()
{
}

void RigidBody::create()
{

}

void RigidBody::start()
{

}

void RigidBody::update(float deltaTime)
{
	vCurrentAcceleration = glm::vec3(0.f);

	if (bGravity) {
		vCurrentAcceleration.y -= 9.8;
	}

	vCurrentVelocity += vCurrentAcceleration*deltaTime;
	TransformComponent* tTransform = dynamic_cast<TransformComponent*>(oOwner->getComponent(0));
	tTransform->vPosition += vCurrentVelocity*deltaTime;
}

void RigidBody::setUseGravity(bool useGravity)
{
	bGravity = useGravity;
}
