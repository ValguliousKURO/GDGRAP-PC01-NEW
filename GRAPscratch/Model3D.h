#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
using namespace std;


class Model3D
{
public:
	Model3D();

	void loadModel(const char* filename);
	void drawModel(GLuint VAO, vector<GLuint>& mesh_indices );
	void setPosition(glm::mat4& transformation, glm::vec3& transPos);
	void setRotationX(glm::mat4& transformation,float theta);
	void setRotationY(glm::mat4& transformation, float theta);
	void setRotationZ(glm::mat4& transformation, float theta);
	void setRotation(glm::mat4& transformation,float theta, char axis);
	void setScale(glm::mat4& transformation, glm::vec3& scalePos);

private:
	float mTheta;
	glm::vec3 position;
	glm::vec3 rotationAxis;
	glm::vec3 scale;
	glm::mat4 getPos();
	glm::vec3 getRot();
	glm::vec3 getScale();
	glm::mat4 posMatrix;

	glm::mat4 GetTransformationMatrix() const;
};


