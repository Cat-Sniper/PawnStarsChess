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
#include "ChessBoard.h"
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
//------------------------------------------------------------------------------------------------------------------------

void glfw_mouse_click_callback(GLFWwindow* window, int button, int action, int mods) {
	
	// Note: could query if window has lost focus here
	if (GLFW_PRESS == action) {
		
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		// work out ray
		glm::vec3 ray_wor = get_ray_from_mouse((float)xpos, (float)ypos);


		Cell* closestClickedCell = nullptr;
		glm::ivec2 clickedCellPos;
		float closestIntersection_cell = 0.0f;

		// Cell checking gets priority... but we are only interested in what is closest to  the screen (should always be a piece since it has a wider radius)
		if (gameManager->getBoard() != nullptr) {
			// check ray against all cells on the board...
			for (int i = 0; i < 8; i++) {

				for (int j = 0; j < 8; j++) {

					float t_dist = 0.0f;
					glm::vec3 cell_collider = glm::vec3(i, j, 0.5f);

					// if clicked on the cell and there is a selected piece
					if (ray_sphere(gameCamera.getPosition(), ray_wor, cell_collider, 0.4, &t_dist)) {

						if (closestClickedCell == nullptr || t_dist < closestIntersection_cell) {

							closestClickedCell = gameManager->getBoard()->getCell(i, j);

							clickedCellPos = glm::ivec2(i, j);
							closestIntersection_cell = t_dist;

						}
					}
				}

			}
		}

		ChessPiece* closestPieceClicked = nullptr;
		float closestIntersection_piece = 0.0f;

		// Check the ray against all chesspieces for the active player
		// For each piece in active player:
		if (gameManager->getCurrentPlayer()->getPieces().size() > 0) {
			for (std::vector<ChessPiece*>::iterator it = std::begin(gameManager->getCurrentPlayer()->getPieces()); it != std::end(gameManager->getCurrentPlayer()->getPieces()); ++it) {


				float t_dist = 0.0f;
				glm::vec3 piece_collider = glm::vec3((*it)->getPosition(), 0.75f);
				

				if (ray_sphere(gameCamera.getPosition(), ray_wor, piece_collider, 0.4, &t_dist)) {

					// if more than one piece is in path of ray, only use the closest one
					if (nullptr == closestPieceClicked || t_dist < closestIntersection_piece) {

						closestPieceClicked = (*it);
						closestIntersection_piece = t_dist;
					}
				}

			}
			
		}

		// after both..
		// The cell is closer than the piece.
		if (closestIntersection_cell < closestIntersection_piece || closestIntersection_piece == 0.0f  && closestClickedCell != nullptr ) {


				std::string str1 = "CELL at (" + std::to_string(clickedCellPos.x) + ", " + std::to_string(clickedCellPos.y) + ")";
				std::cout << str1 << std::endl;


			// check all the validated moves to see if this was an available move.
			if (gameManager->getCurrentPiece() != nullptr) {

				std::string str2 = "got inside.";
				std::cout << str2 << std::endl;

				std::vector<glm::ivec2> validMoveSet = gameManager->getValidMoveSet();
				for (std::vector<glm::ivec2>::iterator it = std::begin(validMoveSet); it != std::end(validMoveSet); ++it) {
					std::string str = "valid move (" + std::to_string((*it).x) + ", " + std::to_string((*it).y) + ")";
					std::cout << str << std::endl;

					// if it was an available move
					if ((*it) == clickedCellPos) {
						gameManager->getBoard()->movePiece(gameManager->getCurrentPiece()->getPosition(), (*it));
						gameManager->changeTurn();
					}
				}
			}

		}
		// Piece is the closest
		else if( closestPieceClicked != nullptr ){	// implied piece <= cell
			gameManager->setCurrentPiece(closestPieceClicked);
			std::string str = "PIECE at (" + std::to_string((int)closestPieceClicked->getPosition().x) + ", " + std::to_string((int)closestPieceClicked->getPosition().y) + ")";
			std::cout << str << std::endl;
		}
		// nothing
		else {
			std::cout << "Aint no pieces or board around here..." << std::endl;
			gameManager->setCurrentPiece(nullptr);
		}

	}
}

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
		gameCamera.out(deltaTime);
	}
	else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
		gameCamera.in(deltaTime);
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {//camera moves up
		gameCamera.right(deltaTime);
	}
	else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		gameCamera.left(deltaTime);
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		gameCamera.down(deltaTime);
	}
	else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		gameCamera.up(deltaTime);
	}
}

//------------------------------------------------------------------------------------------------------------------------

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

	StartCounter();
	gLastFrame = GetCounter();

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glEnable(GL_DEPTH_TEST);

	glfwSetMouseButtonCallback(window, glfw_mouse_click_callback);
#pragma endregion

	gameManager = new ChessGameManager;
	unsigned int cubeIndicies[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35 };
	projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
	view = gameCamera.getViewMat();

#pragma region _windowLoop

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		static double prevTime = GetCounter();
		double tick = GetCounter() - prevTime;
		double currentTime = GetCounter();
		double deltaTime = currentTime - gLastFrame;

		// input
		processInput(window);

		// update
		gameManager->Update(deltaTime);

		//draw stuff
		gameManager->Render(view, projection, gameCamera.getPosition());

		//view update
		view = gameCamera.getViewMat();

		//Final display calls
		glFlush();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
#pragma endregion

#pragma region termination_cleanup

	gameManager->Shutdown();
	delete gameManager;
	glfwTerminate();
	return 0;
#pragma endregion
}
