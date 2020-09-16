/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2017/06
----------------------------------------------*/
#ifndef __MYMESH_H_
#define __MYMESH_H_

#include "Simplex\Simplex.h"

namespace Simplex
{

//System Class
class MyMesh
{
public:
	std::vector<vector3> m_lVertex; //list of elements

	GLuint m_uShaderProgramID = 0; //Shader program
	GLuint m_uVAO = 0; //Vertex Array Object
	GLuint m_uVBO = 0; //Vertex Buffer Object

	matrix4 m_m4Model = matrix4(1.0f); //Identity matrix
	vector3 m_v3Color = vector3(-1.0f); //Color of shape

	void Render(matrix4 a_m4Model = matrix4());
	/*
	Usage: This compiles the shape to opengl
	Arguments: ---
	Output: ---
	*/
	void Compile(void);
	/*
	Usage: Constructor
	Arguments: ---
	Output: class object instance
	*/
	MyMesh(void);
	/*
	Usage: Copy Constructor
	Arguments: class object to copy
	Output: class object instance
	*/
	MyMesh(MyMesh const& other);
	/*
	Usage: Copy Assignment Operator
	Arguments: class object to copy
	Output: ---
	*/
	MyMesh& operator=(MyMesh const& other);
	/*
	Usage: Destructor
	Arguments: ---
	Output: ---
	*/
	~MyMesh(void);

	/*
	Usage: Changes object contents for other object's
	Arguments: other -> object to swap content from
	Output: ---
	*/
	void Swap(MyMesh& other);

	

private:
	/*
	Usage: Deallocates member fields
	Arguments: ---
	Output: ---
	*/
	void Release(void);
	/*
	Usage: Allocates member fields
	Arguments: ---
	Output: ---
	*/
	void Init(void);
};//class

} //namespace Simplex

#endif //__MYMESH_H_

/*
USAGE:
ARGUMENTS: ---
OUTPUT: ---
*/