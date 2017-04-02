#pragma once

#include "Component.h"
#include "TransformComponent.h"
#include "Object.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"


class CameraComponent : public Component
{
	

public:
	CameraComponent();
	~CameraComponent();

	void create();
	void start();
	void update(float deltaTime);

	glm::mat4 getProjection();
};

