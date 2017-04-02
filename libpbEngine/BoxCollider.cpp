#include "BoxCollider.h"

BoxCollider::BoxCollider() : Component()
{
	bCanTick = false;
	bCanDisplay = true;
	iComponentID = 4;

	for (int i = 0; i < 8; i++)
		vGeometryVertex.push_back(glm::vec3(0, 0, 0));

	/* 
	Defining cube index
	Currently not working. 
	vIndexBuffer[0] = 0;
	vIndexBuffer[1] = 1;
	vIndexBuffer[2] = 0;
	vIndexBuffer[3] = 2;

	glGenBuffers(1, &indexbuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexbuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(int), &vIndexBuffer[0], GL_STATIC_DRAW);*/
	
	glProgram = LoadShaders("shaders/vertex.vertexshader", "shaders/fragment.fragmentshader");
	MatrixID = glGetUniformLocation(glProgram, "MVP");
}


BoxCollider::~BoxCollider()
{
}

void BoxCollider::create()
{

}

void BoxCollider::start()
{

}

void BoxCollider::display()
{
	// glUseProgram(glProgram);

	TransformComponent* myTransform = (TransformComponent*)oOwner->getComponent(0);
	glm::mat4 currentMVP = Scene::cCurrentCamera->getProjection()*myTransform->getModelMatrix();

	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &currentMVP[0][0]);

	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);

	glDrawArrays(GL_LINES, 0, (GLsizei)vGeometryVertex.size());
	glDisableVertexAttribArray(0);
}

void BoxCollider::setCenter(glm::vec3 center)
{
	vCenter = center;
	updateVertex();
}

void BoxCollider::setSize(glm::vec3 size)
{
	vSize = size;
	updateVertex();
}

void BoxCollider::updateVertex()
{
	vGeometryVertex[0] = glm::vec3(vCenter.x + vSize.x / 2.f, vCenter.y + vSize.y / 2.f, vCenter.z + vSize.z / 2.f);
	vGeometryVertex[1] = glm::vec3(vCenter.x + vSize.x / 2.f, vCenter.y + vSize.y / 2.f, vCenter.z - vSize.z / 2.f);
	vGeometryVertex[2] = glm::vec3(vCenter.x + vSize.x / 2.f, vCenter.y - vSize.y / 2.f, vCenter.z + vSize.z / 2.f);
	vGeometryVertex[3] = glm::vec3(vCenter.x + vSize.x / 2.f, vCenter.y - vSize.y / 2.f, vCenter.z - vSize.z / 2.f);
	vGeometryVertex[4] = glm::vec3(vCenter.x - vSize.x / 2.f, vCenter.y + vSize.y / 2.f, vCenter.z + vSize.z / 2.f);
	vGeometryVertex[5] = glm::vec3(vCenter.x - vSize.x / 2.f, vCenter.y + vSize.y / 2.f, vCenter.z - vSize.z / 2.f);
	vGeometryVertex[6] = glm::vec3(vCenter.x - vSize.x / 2.f, vCenter.y - vSize.y / 2.f, vCenter.z + vSize.z / 2.f);
	vGeometryVertex[7] = glm::vec3(vCenter.x - vSize.x / 2.f, vCenter.y - vSize.y / 2.f, vCenter.z - vSize.z / 2.f);

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vGeometryVertex.size() * sizeof(glm::vec3), &vGeometryVertex[0], GL_STATIC_DRAW);
}
