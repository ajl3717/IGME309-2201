#include "MyMesh.h"
using namespace Simplex;
//  ExampleClass
void MyMesh::Init(void)
{

	m_uShaderProgramID = LoadShaders("Shaders//Basic.vs", "Shaders//BasicColor.fs");
	m_uVAO = 0; //Vertex Array Object
	m_uVBO = 0; //Vertex Buffer Object

	m_m4Model = matrix4(1.0f); //Identity matrix
	m_v3Color = vector3(-1.0f); //Color of shape
}
void MyMesh::Swap(MyMesh& other)
{

}
void MyMesh::Release(void)
{
	glDeleteShader(m_uShaderProgramID);
	glDeleteBuffers(1, &m_uVBO);
	glBindVertexArray(0); // Unbind VAO
	glDeleteVertexArrays(1, &m_uVAO);
}
//The big 3
MyMesh::MyMesh(){Init();}
MyMesh::MyMesh(MyMesh const& other)
{

}
MyMesh& MyMesh::operator=(MyMesh const& other)
{
	if(this != &other)
	{
		Release();
		Init();
		MyMesh temp(other);
		Swap(temp);
	}
	return *this;
}
MyMesh::~MyMesh(){Release();};
//Accessors

//--- Non Standard Singleton Methods

void MyMesh::Compile(void)
{
	glGenVertexArrays(1, &m_uVAO);//Generate vertex array object
	glGenBuffers(1, &m_uVBO);//Generate Vertex Buffered Object

	glBindVertexArray(m_uVAO);//Bind the VAO
	glBindBuffer(GL_ARRAY_BUFFER, m_uVBO);//Bind the VBO

	//Generate space for the VBO (vertex count times size of vec3)
	glBufferData(GL_ARRAY_BUFFER, m_lVertex.size() * sizeof(vector3), &m_lVertex[0], GL_STATIC_DRAW);

	//count the attributes
	int attributeCount = 2;

	// Position attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, attributeCount * sizeof(vector3), (GLvoid*)0);

	// Color attribute
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, attributeCount * sizeof(vector3), (GLvoid*)(1 * sizeof(vector3)));

	glBindVertexArray(0);//Bind the VAO
	glBindBuffer(GL_ARRAY_BUFFER, 0);//Bind the VBO
}
void MyMesh::Render(matrix4 a_m4Model)
{
	glUseProgram(m_uShaderProgramID);
	glBindVertexArray(m_uVAO);//Bind the VAO
	glBindBuffer(GL_ARRAY_BUFFER, m_uVBO);//Bind the VBO

	//View and projection matrix
	matrix4 m4View;//view matrix
	matrix4 m4Projection;//projection matrix

	//read uniforms and send values
	GLuint MVP = glGetUniformLocation(m_uShaderProgramID, "MVP");//Model View Projection
	glUniformMatrix4fv(MVP, 1, GL_FALSE, glm::value_ptr(m4Projection * m4View * a_m4Model));

	GLuint SolidColor = glGetUniformLocation(m_uShaderProgramID, "SolidColor"); //custom color of the shape
	glUniform3f(SolidColor, m_v3Color.r, m_v3Color.g, m_v3Color.b);

	//draw content
	glDrawArrays(GL_TRIANGLES, 0, m_lVertex.size());

	glBindVertexArray(0);//Bind the VAO
	glBindBuffer(GL_ARRAY_BUFFER, 0);//Bind the VBO
}