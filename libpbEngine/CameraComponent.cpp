#include "CameraComponent.h"



glm::mat4 CameraComponent::getProjection()
{
	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection = glm::perspective(45.f, 4.f / 3.f, 0.1f, 100.0f);

	TransformComponent* tTransform = dynamic_cast<TransformComponent*>(oOwner->getComponent(0));

	// Camera matrix
	glm::mat4 View = glm::lookAt(
		glm::vec3(4, 3, 131), // Camera is at (4,3,3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);

	

	glm::mat4 Model = glm::mat4(1.0f);

	return Projection*View*Model;
}

CameraComponent::CameraComponent() : Component()
{
}


CameraComponent::~CameraComponent()
{
}

void CameraComponent::create()
{

}

void CameraComponent::start()
{

}

void CameraComponent::update()
{

}
