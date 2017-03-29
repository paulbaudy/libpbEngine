#pragma once

#include "Component.h"
#include "glm.hpp"
#include "gtx/transform.hpp"

class TransformComponent : public Component
{
public:
	glm::vec3 vPosition;
	glm::vec3 vRotation;
	glm::vec3 vScale;

	TransformComponent();
	~TransformComponent();

	glm::mat4 getModelMatrix();
};

