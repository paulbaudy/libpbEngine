#include "TransformComponent.h"

#include <iostream>

TransformComponent::TransformComponent() : Component()
{
	vPosition = glm::vec3(0, 0, 0);
	vRotation = glm::vec3(0, 0, 0);
	vScale = glm::vec3(1, 1, 1);
	bCanTick = false;
	iComponentID = 0;
}

TransformComponent::~TransformComponent()
{
}

glm::mat4 TransformComponent::getModelMatrix()
{
	glm::mat4 myTranslationMatrix = glm::translate(vPosition);
	glm::mat4 myScaleMatrix = glm::scale(vScale);
	
	return myTranslationMatrix * myScaleMatrix;
}
