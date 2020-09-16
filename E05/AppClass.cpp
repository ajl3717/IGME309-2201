#include "AppClass.h"
void Application::InitVariables(void)
{
	//makes enough meshes for the invader and adds to vector
	for (int i = 0; i < 46; i++)
	{
		invaderCubes.push_back(new MyMesh());
		invaderCubes[i]->GenerateCube(1.0f, C_BLACK);
	}
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	//Create invader
	CreateInvader();
		
	// draw a skybox
	m_pMeshMngr->AddSkyboxToRenderList();
	
	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();

	//clear the render list
	m_pMeshMngr->ClearRenderList();
	
	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	//safely delete all the created meshes
	for (int i = 0; i < 46; i++)
	{
		SafeDelete(invaderCubes[i]);
	}
	//clear the vector of cubes
	invaderCubes.clear();

	//release GUI
	ShutdownGUI();
}

void Application::CreateInvader()
{
	//get camera view and projection matrix
	matrix4 m4View = m_pCameraMngr->GetViewMatrix();
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();

	//value to increment the translate by
	static float incrementer = 0.1f;
	//starting point is multiplied by the incremented matrix to produce the new location
	matrix4 m4Translate = glm::translate(vector3(incrementer, 0.0f, 0.0f)) * glm::translate(vector3(-10.0f, 0.0f, 0.0f));
	//increase the incrementer so it actually moves
	incrementer += 0.1f;

	//position all the cubes correctly
	//first column
	invaderCubes[0]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(-5.0f, -2.0f, 0.0f)));
	invaderCubes[1]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(-5.0f, -1.0f, 0.0f)));
	invaderCubes[2]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(-5.0f,  0.0f, 0.0f)));
	//second column
	invaderCubes[3]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(-4.0f,  1.0f, 0.0f)));
	invaderCubes[4]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(-4.0f,  0.0f, 0.0f)));
	//third column
	invaderCubes[5]->Render(m4Projection, m4View,  glm::translate(m4Translate, vector3(-3.0f,  4.0f, 0.0f)));
	invaderCubes[6]->Render(m4Projection, m4View,  glm::translate(m4Translate, vector3(-3.0f,  2.0f, 0.0f)));
	invaderCubes[7]->Render(m4Projection, m4View,  glm::translate(m4Translate, vector3(-3.0f,  1.0f, 0.0f)));
	invaderCubes[8]->Render(m4Projection, m4View,  glm::translate(m4Translate, vector3(-3.0f,  0.0f, 0.0f)));
	invaderCubes[9]->Render(m4Projection, m4View,  glm::translate(m4Translate, vector3(-3.0f, -1.0f, 0.0f)));
	invaderCubes[10]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(-3.0f, -2.0f, 0.0f)));
	//fourth column
	invaderCubes[11]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(-2.0f,  3.0f, 0.0f)));
	invaderCubes[12]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(-2.0f,  2.0f, 0.0f)));
	invaderCubes[13]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(-2.0f,  0.0f, 0.0f)));
	invaderCubes[14]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(-2.0f, -1.0f, 0.0f)));
	invaderCubes[15]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(-2.0f, -3.0f, 0.0f)));
	//fifth column
	invaderCubes[16]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(-1.0f,  2.0f, 0.0f)));
	invaderCubes[17]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(-1.0f,  1.0f, 0.0f)));
	invaderCubes[18]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(-1.0f,  0.0f, 0.0f)));
	invaderCubes[19]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(-1.0f, -1.0f, 0.0f)));
	invaderCubes[20]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(-1.0f, -3.0f, 0.0f)));
	//sixth column
	invaderCubes[21]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(0.0f,  2.0f, 0.0f)));
	invaderCubes[22]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(0.0f,  1.0f, 0.0f)));
	invaderCubes[23]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(0.0f,  0.0f, 0.0f)));
	invaderCubes[24]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(0.0f, -1.0f, 0.0f)));
	//seventh column
	invaderCubes[25]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(1.0f, 2.0f, 0.0f)));
	invaderCubes[26]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(1.0f, 1.0f, 0.0f)));
	invaderCubes[27]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(1.0f, 0.0f, 0.0f)));
	invaderCubes[28]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(1.0f, -1.0f, 0.0f)));
	invaderCubes[29]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(1.0f, -3.0f, 0.0f)));
	//eight column
	invaderCubes[30]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(2.0f, 3.0f, 0.0f)));
	invaderCubes[31]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(2.0f, 2.0f, 0.0f)));
	invaderCubes[32]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(2.0f, 0.0f, 0.0f)));
	invaderCubes[33]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(2.0f, -1.0f, 0.0f)));
	invaderCubes[34]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(2.0f, -3.0f, 0.0f)));
	//ninth column
	invaderCubes[35]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(3.0f, 4.0f, 0.0f)));
	invaderCubes[36]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(3.0f, 2.0f, 0.0f)));
	invaderCubes[37]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(3.0f, 1.0f, 0.0f)));
	invaderCubes[38]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(3.0f, 0.0f, 0.0f)));
	invaderCubes[39]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(3.0f, -1.0f, 0.0f)));
	invaderCubes[40]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(3.0f, -2.0f, 0.0f)));
	//tenth column
	invaderCubes[41]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(4.0f, 1.0f, 0.0f)));
	invaderCubes[42]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(4.0f, 0.0f, 0.0f)));
	//elevnth column
	invaderCubes[43]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(5.0f, -2.0f, 0.0f)));
	invaderCubes[44]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(5.0f, -1.0f, 0.0f)));
	invaderCubes[45]->Render(m4Projection, m4View, glm::translate(m4Translate, vector3(5.0f, 0.0f, 0.0f)));
}