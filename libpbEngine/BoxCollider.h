#pragma once
#include "Component.h"
#include "Object.h"
#include "Scene.h"
#include "glm.hpp"
#include <vector>

#include <glew.h>
#include <glfw3.h>

#include "TransformComponent.h"
#include "MeshComponent.h"

class BoxCollider : public Component
{
private:
	glm::vec3 vCenter;
	glm::vec3 vSize;
	
	GLuint glProgram;
	GLuint MatrixID;
	GLuint vertexbuffer;
	std::vector<glm::vec3> vGeometryVertex;
	GLuint indexbuffer;
	int vIndexBuffer[4];
public:
	BoxCollider();
	~BoxCollider();

	virtual void create();
	virtual void start();
	virtual void display();

	void setCenter(glm::vec3 center);
	void setSize(glm::vec3 size);
	void updateVertex();

};

