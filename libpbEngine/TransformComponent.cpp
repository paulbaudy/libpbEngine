#include "TransformComponent.h"

#include <iostream>

TransformComponent::TransformComponent() : Component()
{
	vPosition = glm::vec3(0, 0, 0);
	vRotation = glm::vec3(0, 0, 0);
	vScale = glm::vec3(0, 0, 0);
	bCanTick = false;
	iComponentID = 0;
}

TransformComponent::~TransformComponent()
{
}
