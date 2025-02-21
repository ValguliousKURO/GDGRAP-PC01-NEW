#include "Model3D.h"
#include <iostream>
Model3D::Model3D()
{
	/*mTheta = 0;
	position = glm::vec3(0.0f, 0.0f, 0.0f);
	rotationAxis = glm::vec3(0.0f, 0.0f, 0.0f);
	scale = glm::vec3(1.0f, 1.0f, 1.0f);*/
}

void Model3D::drawModel(GLuint VAO, vector<GLuint>& mesh_indices)
{
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, mesh_indices.size(), GL_UNSIGNED_INT, 0);
}

void Model3D::setPosition(glm::mat4& transformation, glm::vec3& transPos)
{
	glm::mat4 identity_matrix = glm::mat4(1.0f);
	position = transPos;
	transformation = glm::translate(
		identity_matrix,
		position
	);
	posMatrix = transformation;
}

void Model3D::setRotation(glm::mat4& transformation, float theta, char axis)
{		
	mTheta = theta;
	if (axis == 'x' || axis == 'X')
	{
		transformation = glm::rotate(
			transformation,
			glm::radians(theta),
			glm::normalize(glm::vec3(1.0f, 0.0f, 0.0f))
		);
	}
	else if (axis == 'y' || axis == 'Y')
	{
		transformation = glm::rotate(
			transformation,
			glm::radians(theta),
			glm::normalize(glm::vec3(0.0f, 1.0f, 0.0f))
		);
	}
	else if (axis == 'z' || axis == 'Z')
	{
		transformation = glm::rotate(
			transformation,
			glm::radians(theta),
			glm::normalize(glm::vec3(0.0f, 0.0f, 1.0f))
		);
	}
	else
	{
		cout << "Invalid axis" << endl;
	}
}

void Model3D::setScale(glm::mat4& transformation, glm::vec3& scalePos)
{
	scale = scalePos;
	transformation = glm::scale(
		transformation,
		scalePos
	);
}

glm::mat4 Model3D::getPos()
{
	return this->posMatrix;
}