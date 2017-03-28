#pragma once

#include "Component.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <string>

#include <vector>
#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>

GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);

class MeshComponent : public Component
{
private:
	GLuint vertexbuffer;

	GLuint glProgram;

	std::vector<glm::vec3> vGeometryVertex;
public:
	MeshComponent();
	~MeshComponent();

	virtual void create();
	virtual void start();
	virtual void display();
};

