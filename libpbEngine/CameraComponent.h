#pragma once
#include "glm.hpp"

class CameraComponent
{
private:
	glm::vec4 getProjection();

public:
	CameraComponent();
	~CameraComponent();

	void create();
	void start();
	void update();

	
};

