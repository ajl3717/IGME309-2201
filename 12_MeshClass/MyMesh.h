/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2017/05
----------------------------------------------*/
#ifndef __MYMESH_H_
#define __MYMESH_H_

#include "BasicX\BasicX.h"
using namespace BasicX;

//#include "Simplex\Simplex.h"
//using namespace Simplex;

class MyMesh
{
	bool m_bBinded = false;
	uint m_uVertexCount = 0;
	GLuint m_VAO = 0;
	GLuint m_VBO = 0;

	std::vector<vector3> m_lVertex;
	std::vector<vector3> m_lVertexPos;
	std::vector<vector3> m_lVertexCol;

	ShaderManager* m_pShaderMngr = nullptr;
public:
	/*
	USAGE: Initialize the object's fields
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void Init(void);
	/*
	USAGE: Releases the object from memory
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void Release(void);
	/*
	USAGE: Constructor
	ARGUMENTS: ---
	OUTPUT: class object
	*/
	MyMesh();
	/*
	USAGE: Destructor
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	~MyMesh();
	/*
	USAGE: Copy Constructor -> MyMesh does not allow to copy
	from other MyMesh objects, create an empty MyMesh
	and use the Instantiate method instead
	ARGUMENTS: class object (to copy)
	OUTPUT: class object
	*/
	MyMesh(MyMesh& other);
	/*
	USAGE: Copy Assignment Operator -> MyMesh does not allow to copy
	from other SimpleMesh objects, use the Instantiate method instead.
	ARGUMENTS: class object (to copy)
	OUTPUT: class object
	*/
	MyMesh& operator=(MyMesh& other);
	/*
	USAGE: Swaps the contents of the object with another object's content
	ARGUMENTS: class object  (to swap with)
	OUTPUT: ---
	*/
	void Swap(MyMesh& other);

	void CompleteMesh(vector3 a_v3Color = vector3(1.0f, 0.0f, 0.0f));

	void AddVertexPosition(vector3 a_v3Input);

	void AddVertexColor(vector3 a_v3Input);

	void CompileOpenGL3X(void);

	void Render(matrix4 a_mProjection, matrix4 a_mView, matrix4 a_mModel);

	void AddTri(vector3 a_vBottomLeft, vector3 a_vBottomRight, vector3 a_vTopLeft);

	void AddQuad(vector3 a_vBottomLeft, vector3 a_vBottomRight, vector3 a_vTopLeft, vector3 a_vTopRight);

	void GenerateCube(float a_fSize, vector3 a_v3Color);
};
/*
USAGE:
ARGUMENTS: ---
OUTPUT: ---
*/
#endif //__MYMESH_H_