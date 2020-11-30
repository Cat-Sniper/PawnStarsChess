/// "main.cpp"
/// ----------
/// Entrance to the program
/// Created: Oct. 8, 2020
/// Edited:  Oct. 8, 2020

#include <GL\glew.h>
#include <Windows.h>
#include <cstdio>
#include <glfw3.h>
#include <iostream>
#include "Texture.h"
#include "Model.h"
#include "Shader.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <math.h>
#include "ChessPiece.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "Rook.h"
#include "GlobalTypes.h"
#include "Camera.h"

// Internal globals for timing
double gPCFrequency = 0.0;
__int64 gCounterStart = 0;
double gLastFrame;

// Game manager - controls game stuff
//ChessGameManager gameManager;



/// <summary>
/// Initializes the counter at startup
/// </summary>
void StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
	{
		printf("Failed to init performance counters.");
	}
	gPCFrequency = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	gCounterStart = li.QuadPart;
}

/// <summary>
/// Returns the time since the start of the program
/// </summary>
double GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return (double(li.QuadPart - gCounterStart) / gPCFrequency);
}

/// <summary>
/// Initializes OpenGL Graphics
/// </summary>
void InitGL()
{
	StartCounter();
	gLastFrame = GetCounter();
	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


/// <summary>
/// OpenGL calls this.
/// </summary>
void Display() 
{
	//glClear(GL_COLOR_BUFFER_BIT);
	//gameManager.Render();
	//glFlush();
}


/// <summary>
/// OpenGL calls this...
/// </summary>
void Idle()
{
	static double prevTime = GetCounter();
	double tick = GetCounter() - prevTime;
	double currentTime = GetCounter();
	double deltaTime = currentTime - gLastFrame;

	//gameManager.Update((float)deltaTime);
}

//------------------------------------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

float deltaTime = 0.0f;
float lastFrame = 0.0f;
glm::vec3 cameraPos = glm::vec3(3.5f, -3.5f, 7.0f);
glm::vec3 cameraRight = glm::vec3(1.0f, 0.0f, 0.0f);
glm::vec3 cameraTarget = glm::vec3(3.5f, 3.5f, 0.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 0.0f, 1.0f);

constexpr float shift = glm::radians(40.0f);
constexpr float clamp_max = glm::radians(90.0f);
constexpr glm::mat4 identity = glm::mat4(1.0f);

Camera gameCamera = Camera(cameraPos, cameraTarget, cameraUp, shift);

int main() {
	
#pragma region _setup
	std::string relativePath = "../Chess Game/Dependencies/";

	if (!glfwInit()) return -1;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1000, 1000, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	
	if (glewInit() != GLEW_OK) {
		std::cout << "glew is angry\n";
		return -2;
	}

	glViewport(0, 0, 1000, 1000);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glEnable(GL_DEPTH_TEST);
#pragma endregion

#pragma region cubeBuffer
	float cubeVertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	unsigned int cubeIndicies[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35 };

	unsigned int cubeVAO, cubeVBO, cubeIBO;
	glGenVertexArrays(1, &cubeVAO);
	glGenBuffers(1, &cubeVBO);
	glBindVertexArray(cubeVAO);
	glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glGenBuffers(1, &cubeIBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeIBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeIndicies), cubeIndicies, GL_STATIC_DRAW);
	glBindVertexArray(0);
#pragma endregion

	//Textures
	Texture cubeTextures[2] = {Texture(relativePath + "blackMarble.jpg", GL_RGB, 0), Texture(relativePath + "whiteMarble.jpg", GL_RGB, 1)};

	//Matricies
	glm::mat4 models[64];

	glm::mat4 view;
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			models[8 * i + j] = glm::translate(identity, glm::vec3((float)j, (float)i, 0.0f));
		}
	}

	glm::vec3 lightPos = glm::vec3(-1.5f, 3.5f, 4.0f);
	glm::mat4 lightModel = glm::translate(identity, lightPos);

	glm::mat4 rKingModel = glm::translate(identity, glm::vec3(4.0f, 0.0f, 0.5f));
	rKingModel = glm::rotate(rKingModel, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	rKingModel = glm::scale(rKingModel, glm::vec3(0.4f, 0.4f, 0.4f));

	//Shaders
	Shader boardShader = Shader("texVertex.vert", "texFragment.frag");
	Shader lightShader = Shader("lightVertex.vert", "lightFragment.frag");
	Shader pieceShader = Shader("vertex.vert", "fragment.frag");

	//Models

	std::vector<std::string> modelFiles = {"King.obj", "Queen.obj", "Bishop.obj", "knight.obj", "Rook.obj", "Pawn.obj"};//this will be the order used for the co-related vectors
	std::vector<Model> pieceModels;
	std::vector<std::vector<glm::vec3>> modelPositions = std::vector<std::vector<glm::vec3>>(6);//latter half of sub-vector is "black", fore half is "white"
	std::vector<std::vector<glm::mat4>> modelRSMats = std::vector<std::vector<glm::mat4>>(6);
	std::vector<std::vector<glm::mat4>> modelNMats = std::vector<std::vector<glm::mat4>>(6);
	
	for (int i = 0; i < modelFiles.size(); i++) {
		std::string path = relativePath + modelFiles[i];
		pieceModels.push_back(Model(&path[0]));
	}

	glm::mat4 rsModel;
	glm::vec3 redColor = glm::vec3(PLAYER1_COLOR.r, PLAYER1_COLOR.g, PLAYER1_COLOR.b);
	glm::vec3 blueColor = glm::vec3(PLAYER2_COLOR.r, PLAYER2_COLOR.g, PLAYER2_COLOR.b);
	std::vector<ChessPiece> redPieces;
	std::vector<ChessPiece> bluePieces;
	

	//kings

	rsModel = glm::rotate(identity, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	rsModel = glm::scale(rsModel, glm::vec3(0.4f, 0.4f, 0.4f));
	glm::ivec2 pos = glm::ivec2(4, 0);
	ChessPiece piece = King(0, pos, redColor, rsModel, pieceModels[0], pieceShader);
	redPieces.push_back(piece);

	pos = glm::ivec2(4, 7);
	piece = King(1, pos, blueColor, rsModel, pieceModels[0], pieceShader);
	bluePieces.push_back(piece);

	//queens

	pos = glm::ivec2(3, 0);
	redPieces.push_back(Queen(0, pos, redColor, rsModel, pieceModels[1], pieceShader));

	pos = glm::ivec2(3, 7);
	bluePieces.push_back(Queen(1, pos, blueColor, rsModel, pieceModels[1], pieceShader));

	//bishops

	rsModel = glm::rotate(identity, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	rsModel = glm::scale(rsModel, glm::vec3(0.3f, 0.3f, 0.3f));

	pos = glm::ivec2(2, 0);
	redPieces.push_back(Bishop(0, pos, redColor, rsModel, pieceModels[2], pieceShader));
	pos = glm::ivec2(5, 0);
	redPieces.push_back(Bishop(0, pos, redColor, rsModel, pieceModels[2], pieceShader));
	
	pos = glm::ivec2(2, 7);
	bluePieces.push_back(Bishop(1, pos, blueColor, rsModel, pieceModels[2], pieceShader));
	pos = glm::ivec2(5, 7);
	bluePieces.push_back(Bishop(1, pos, blueColor, rsModel, pieceModels[2], pieceShader));

	//knights

	rsModel = glm::rotate(identity, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	rsModel = glm::rotate(rsModel, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	rsModel = glm::scale(rsModel, glm::vec3(0.4f, 0.4f, 0.4f));

	pos = glm::ivec2(1, 0);
	redPieces.push_back(Knight(0, pos, redColor, rsModel, pieceModels[3], pieceShader));
	pos = glm::ivec2(6, 0);
	redPieces.push_back(Knight(0, pos, redColor, rsModel, pieceModels[3], pieceShader));

	rsModel = glm::rotate(identity, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	rsModel = glm::rotate(rsModel, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	rsModel = glm::scale(rsModel, glm::vec3(0.4f, 0.4f, 0.4f));
	
	pos = glm::ivec2(1, 7);
	redPieces.push_back(Knight(1, pos, blueColor, rsModel, pieceModels[3], pieceShader));
	pos = glm::ivec2(6, 7);
	redPieces.push_back(Knight(1, pos, blueColor, rsModel, pieceModels[3], pieceShader));

	//rooks

	rsModel = glm::rotate(identity, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	rsModel = glm::scale(rsModel, glm::vec3(0.4f, 0.4f, 0.4f));
	
	pos = glm::ivec2(0, 0);
	redPieces.push_back(Rook(0, pos, redColor, rsModel, pieceModels[4], pieceShader));
	pos = glm::ivec2(7, 0);
	redPieces.push_back(Rook(0, pos, redColor, rsModel, pieceModels[4], pieceShader));

	pos = glm::ivec2(0, 7);
	bluePieces.push_back(Rook(1, pos, blueColor, rsModel, pieceModels[4], pieceShader));
	pos = glm::ivec2(7, 7);
	bluePieces.push_back(Rook(1, pos, blueColor, rsModel, pieceModels[4], pieceShader));

	//pawns

	rsModel = glm::rotate(identity, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	rsModel = glm::scale(rsModel, glm::vec3(0.2f, 0.2f, 0.2f));
	
	for (int i = 0; i < 8; i++) {
		pos = glm::ivec2(i, 1);
		redPieces.push_back(Pawn(0, pos, redColor, rsModel, pieceModels[5], pieceShader));
	}

	for (int i = 0; i < 8; i++) {
		pos = glm::ivec2(i, 6);
		bluePieces.push_back(Pawn(1, pos, blueColor, rsModel, pieceModels[5], pieceShader));
	}

#pragma region _windowLoop
	int base = 0;

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		processInput(window);
		//view = glm::lookAt(cameraPos, glm::vec3(3.5f, 3.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		view = gameCamera.getViewMat();


		//render calls
		boardShader.bind();
		boardShader.setMat4Uniform("projection", glm::value_ptr(projection));
		boardShader.setMat4Uniform("view", glm::value_ptr(view));

		//drawing the board
		glBindVertexArray(cubeVAO);
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				boardShader.setMat4Uniform("model", glm::value_ptr(models[8*i + j]));
				boardShader.setIntUniform("Tex1", abs(base + j%2));
				glDrawElements(GL_TRIANGLES, sizeof(cubeIndicies) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);
			}
			base = (base == 0) ? -1 : 0;
		}

		//draw light source visual aid
		lightShader.bind();
		lightShader.setMat4Uniform("projection", glm::value_ptr(projection));
		lightShader.setMat4Uniform("view", glm::value_ptr(view));
		lightShader.setMat4Uniform("model", glm::value_ptr(lightModel));
		glDrawElements(GL_TRIANGLES, sizeof(cubeIndicies) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);

		//draw pieces
		for (ChessPiece p : redPieces) {
			p.draw(view, projection, lightPos, cameraPos);
		}

		for (ChessPiece p : bluePieces) {
			p.draw(view, projection, lightPos, cameraPos);
		}

		//Final display calls
		glFlush();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
#pragma endregion

#pragma region termination_cleanup
	glfwTerminate();
	return 0;
#pragma endregion
}
//------------------------------------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {//zoom out
		/*
		glm::vec4 cameraH = glm::vec4(cameraPos.x, cameraPos.y, cameraPos.z, 1.0f);
		glm::mat4 translation = glm::translate(identity, glm::vec3(-3.5f, -3.5f, 0.0f));
		cameraH = translation * cameraH;
		cameraH = glm::vec4(cameraH.x * 1.1, cameraH.y * 1.1, cameraH.z * 1.1, 1.0f);
		translation = glm::translate(identity, glm::vec3(3.5f, 3.5f, 0.0f));
		cameraH = translation * cameraH;

		cameraPos.x = cameraH.x;
		cameraPos.y = cameraH.y;
		cameraPos.z = cameraH.z;
		*/
		gameCamera.out(deltaTime);
	}
	else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
		/*
		glm::vec4 cameraH = glm::vec4(cameraPos.x, cameraPos.y, cameraPos.z, 1.0f);
		glm::mat4 translation = glm::translate(identity, glm::vec3(-3.5f, -3.5f, 0.0f));
		cameraH = translation * cameraH;
		cameraH = glm::vec4(cameraH.x * 0.9, cameraH.y * 0.9, cameraH.z * 0.9, 1.0f);
		translation = glm::translate(identity, glm::vec3(3.5f, 3.5f, 0.0f));
		cameraH = translation * cameraH;

		cameraPos.x = cameraH.x;
		cameraPos.y = cameraH.y;
		cameraPos.z = cameraH.z;
		*/
		gameCamera.in(deltaTime);
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {//camera moves up
		/*
		//conversion to homogeneous
		glm::vec4 cameraH = glm::vec4(cameraPos.x, cameraPos.y, cameraPos.z, 1.0f);
		glm::vec4 cameraHR = glm::vec4(cameraRight.x, cameraRight.y, cameraRight.z, 1.0f);

		//translation of the camera position
		glm::mat4 translation = glm::translate(identity, glm::vec3(-3.5f, -3.5f, 0.0f));
		cameraH = translation * cameraH;

		//rotation of the camera position and right vector
		glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), shift * deltaTime, glm::vec3(0.0f, 0.0f, 1.0f));
		cameraH = rotation * cameraH;
		cameraHR = rotation * cameraHR;

		//translate camera position back
		translation = glm::translate(identity, glm::vec3(3.5f, 3.5f, 0.0f));
		cameraH = translation * cameraH;

		//reassignment
		cameraPos.x = cameraH.x;
		cameraPos.y = cameraH.y;
		cameraPos.z = cameraH.z;

		cameraRight.x = cameraHR.x;
		cameraRight.y = cameraHR.y;
		cameraRight.z = cameraHR.z;
		*/
		gameCamera.right(deltaTime);
	}
	else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		/*
		//conversion to homogeneous
		glm::vec4 cameraH = glm::vec4(cameraPos.x, cameraPos.y, cameraPos.z, 1.0f);
		glm::vec4 cameraHR = glm::vec4(cameraRight.x, cameraRight.y, cameraRight.z, 1.0f);

		//translation of the camera position
		glm::mat4 translation = glm::translate(identity, glm::vec3(-3.5f, -3.5f, 0.0f));
		cameraH = translation * cameraH;

		//rotation of the camera position and right vector
		glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), -shift * deltaTime, glm::vec3(0.0f, 0.0f, 1.0f));
		cameraH = rotation * cameraH;
		cameraHR = rotation * cameraHR;

		//translate camera position back
		translation = glm::translate(identity, glm::vec3(3.5f, 3.5f, 0.0f));
		cameraH = translation * cameraH;

		//reassignment
		cameraPos.x = cameraH.x;
		cameraPos.y = cameraH.y;
		cameraPos.z = cameraH.z;

		cameraRight.x = cameraHR.x;
		cameraRight.y = cameraHR.y;
		cameraRight.z = cameraHR.z;
		*/
		gameCamera.left(deltaTime);
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		/*
		glm::vec4 cameraH = glm::vec4(cameraPos.x, cameraPos.y, cameraPos.z, 1.0f);
		glm::mat4 translation = glm::translate(identity, glm::vec3(-3.5f, -3.5f, 0.0f));
		cameraH = translation * cameraH;
		glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), shift * deltaTime, cameraRight);
		cameraH = rotation * cameraH;
		translation = glm::translate(identity, glm::vec3(3.5f, 3.5f, 0.0f));
		cameraH = translation * cameraH;
		cameraPos.x = cameraH.x;
		cameraPos.y = cameraH.y;
		cameraPos.z = cameraH.z;
		*/
		gameCamera.down(deltaTime);
	}
	else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		/*
		glm::vec4 cameraH = glm::vec4(cameraPos.x, cameraPos.y, cameraPos.z, 1.0f);
		glm::mat4 translation = glm::translate(identity, glm::vec3(-3.5f, -3.5f, 0.0f));
		cameraH = translation * cameraH;
		glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), -shift * deltaTime, cameraRight);
		cameraH = rotation * cameraH;
		translation = glm::translate(identity, glm::vec3(3.5f, 3.5f, 0.0f));
		cameraH = translation * cameraH;
		cameraPos.x = cameraH.x;
		cameraPos.y = cameraH.y;
		cameraPos.z = cameraH.z;
		*/
		gameCamera.up(deltaTime);
	}
}

/*
abstracting the pieces and info for rendering:

Chesspiece
has: model, rsMatrix, nMatrix, color, instance locations, reference to a shader used for drawing

methods?
-drawElements - draw the elemtns off a shader used for all the pieces
-moveInstance - modify the instance location
-setInstance - hard code the new loaction of the instance

this gives the necessary info for drawing a piece

need the board:
board has cells
each cell should have the reference to the piece type and the index of the instance - allows identification for movement
*/
