/// "main.cpp"
/// ----------
/// Entrance to the program
/// Created: Oct. 8, 2020
/// Edited:  Oct. 8, 2020

#include <Windows.h>
#include <cstdio>
#include <string>
#include <iostream>

#include <GL\glew.h>
#include <glfw3.h>
#include <math.h>

#include "GlobalTypes.h"


#include "ChessGameManager.h"
#include "Player.h"
#include "ChessPiece.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "Rook.h"
#include "Camera.h"
#include "Texture.h"

// Internal globals for timing
double gPCFrequency = 0.0;
__int64 gCounterStart = 0;
double gLastFrame;

// Game manager - controls game stuff
ChessGameManager* gameManager;

float deltaTime = 0.0f;
float lastFrame = 0.0f;
glm::vec3 cameraPos = glm::vec3(3.5f, -3.5f, 7.0f);
glm::vec3 cameraRight = glm::vec3(1.0f, 0.0f, 0.0f);
glm::vec3 cameraTarget = glm::vec3(3.5f, 3.5f, 0.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 0.0f, 1.0f);

glm::mat4 view;
glm::mat4 projection;

Camera gameCamera = Camera(cameraPos, cameraTarget, cameraUp, shift);
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

/* check if a ray and a sphere intersect. if not hit, returns false. it rejects
intersections behind the ray caster's origin, and sets intersection_distance to
the closest intersection */
bool ray_sphere(glm::vec3 ray_origin_wor, glm::vec3 ray_direction_wor, glm::vec3 sphere_centre_wor, float sphere_radius, float* intersection_distance) {
	// work out components of quadratic
	glm::vec3 dist_to_sphere = ray_origin_wor - sphere_centre_wor;
	float b = dot(ray_direction_wor, dist_to_sphere);
	float c = dot(dist_to_sphere, dist_to_sphere) - sphere_radius * sphere_radius;
	float b_squared_minus_c = b * b - c;
	// check for "imaginary" answer. == ray completely misses sphere
	if (b_squared_minus_c < 0.0f) { return false; }
	// check for ray hitting twice (in and out of the sphere)
	if (b_squared_minus_c > 0.0f) {
		// get the 2 intersection distances along ray
		float t_a = -b + sqrt(b_squared_minus_c);
		float t_b = -b - sqrt(b_squared_minus_c);
		*intersection_distance = t_b;
		// if behind viewer, throw one or both away
		if (t_a < 0.0) {
			if (t_b < 0.0) { return false; }
		}
		else if (t_b < 0.0) {
			*intersection_distance = t_a;
		}

		return true;
	}

	// check for ray hitting once (skimming the surface)
	if (0.0f == b_squared_minus_c) {
		// if behind viewer, throw away
		float t = -b + sqrt(b_squared_minus_c);
		if (t < 0.0f) { return false; }
		*intersection_distance = t;
		return true;
	}
	// note: could also check if ray origin is inside sphere radius
	return false;
}

/* takes mouse position on screen and return ray in world coords */
glm::vec3 get_ray_from_mouse(float mouse_x, float mouse_y) {

	// screen space (viewport coordinates)
	float x = (2.0f * mouse_x) / CHESS_WINDOW_WIDTH - 1.0f;
	float y = 1.0f - (2.0f * mouse_y) / CHESS_WINDOW_HEIGHT;
	float z = 1.0f;
	// normalised device space
	glm::vec3 ray_nds = glm::vec3(x, y, z);
	// clip space
	glm:: vec4 ray_clip = glm::vec4(ray_nds.x, ray_nds.y, -1.0, 1.0);
	// eye space
	glm::vec4 ray_eye = glm::inverse(projection) * ray_clip;
	ray_eye = glm::vec4(ray_eye.x, ray_eye.y, -1.0, 0.0);
	// world space
	glm::vec3 ray_wor = glm::vec3(glm::inverse(view) * ray_eye);
	// don't forget to normalise the vector at some point
	ray_wor = glm::normalize(ray_wor);
	return ray_wor;
}

void glfw_mouse_click_callback(GLFWwindow* window, int button, int action, int mods) {
	
	// Note: could query if window has lost focus here
	if (GLFW_PRESS == action) {
		
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		// work out ray
		glm::vec3 ray_wor = get_ray_from_mouse((float)xpos, (float)ypos);
		
		// check ray against all pieces for current active player in scene
		ChessPiece* closestPieceClicked = nullptr;
		float closestIntersection = 0.0f;
		
		// TODO: Finish colliders.
		// For each piece in active player:
		
		if (gameManager->getCurrentPlayer()->getPieces().size() > 0) {
			for (std::vector<ChessPiece*>::iterator it = std::begin(gameManager->getCurrentPlayer()->getPieces()); it != std::end(gameManager->getCurrentPlayer()->getPieces()); ++it) {

				
				

				float t_dist = 0.0f;
				glm::vec3 collider_position = glm::vec3((*it)->getPosition(), 0.75f);


				if (ray_sphere(gameCamera.getPosition(), ray_wor, collider_position, 0.4, &t_dist)) {
					
					// if more than one piece is in path of ray, only use the closest one
					if (nullptr == closestPieceClicked || t_dist < closestIntersection) {

						closestPieceClicked = (*it);
						closestIntersection = t_dist;
					}
				}
				else {

					// remove selection if we have clicked off this piece.
					if ((*it)->getSelected()) (*it)->setSelected(false);
				}
			}

			if (closestPieceClicked != nullptr) {
				closestPieceClicked->setSelected(true);
				std::string str = "clicked on piece at (" + std::to_string((int)closestPieceClicked->getPosition().x) + ", " + std::to_string((int)closestPieceClicked->getPosition().y) + ")";
				std::cout << str << std::endl;
				
			}
			else {
				std::cout << "Aint no chess pieces around here..." << std::endl;
			}
		}

		/* code from tutorial - clicking on spheres.... reference until i get this shit working
		for (int i = 0; i < NUM_SPHERES; i++) {
			float t_dist = 0.0f;
			if (ray_sphere(cam_pos, ray_wor, sphere_pos_wor[i], sphere_radius, &t_dist)) {
				// if more than one sphere is in path of ray, only use the closest one
				if (-1 == closest_sphere_clicked || t_dist < closest_intersection) {
					closest_sphere_clicked = i;
					closest_intersection = t_dist;
				}
			}
		} // endfor
		g_selected_sphere = closest_sphere_clicked;
		printf("sphere %i was clicked\n", closest_sphere_clicked);
		*/
	}
}

//------------------------------------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);



int main() {
	
#pragma region _setup
	
	if (!glfwInit()) return -1;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(CHESS_WINDOW_WIDTH, CHESS_WINDOW_HEIGHT, "PawnStars Chess", NULL, NULL);
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

	glfwSetMouseButtonCallback(window, glfw_mouse_click_callback);
#pragma endregion
	gameManager = new ChessGameManager();

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
	Texture cubeTextures[2] = {Texture(RELATIVE_PATH + "blackMarble.jpg", GL_RGB, 0), Texture(RELATIVE_PATH + "whiteMarble.jpg", GL_RGB, 1)};

	//Matricies
	glm::mat4 models[64];

	projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			models[8 * i + j] = glm::translate(identity, glm::vec3((float)j, (float)i, 0.0f));
		}
	}

	glm::vec3 lightPos = glm::vec3(-1.5f, 3.5f, 4.0f);
	glm::mat4 lightModel = glm::translate(identity, lightPos);

	//glm::mat4 rKingModel = glm::translate(identity, glm::vec3(4.0f, 0.0f, 0.5f));


	Shader boardShader = Shader("texVertex.vert", "texFragment.frag");
	Shader lightShader = Shader("lightVertex.vert", "lightFragment.frag");
	

#pragma region _windowLoop
	int base = 0;

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		processInput(window);
		gameManager->Update(deltaTime);


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
		gameManager->Render(view, projection, lightPos, cameraPos);
		view = gameCamera.getViewMat();

		//Final display calls
		glFlush();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
#pragma endregion

#pragma region termination_cleanup
	glfwTerminate();

	delete gameManager;
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
