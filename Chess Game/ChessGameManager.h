#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>
#include "GlobalTypes.h"

#include "Light.h"
class GameState;
class Player;
class ChessBoard;
class ChessPiece;

class ChessGameManager {

private:
	GameState* _currentGameState;
	std::vector<Player*> _players;
	Player* _currentPlayer;
	ChessBoard* _gameBoard;
	ChessPiece* _selectedPiece;
	Light light;
	std::vector<glm::ivec2> validMoveSet;
	

public:

	ChessGameManager();

	/// <summary>
	/// Use this to initialize anything at the very start, when the game first launches
	/// </summary>
	void Init();

	/// <summary>
	/// This is where logic is run once a frame: we have a target of 60 fps
	/// </summary>
	/// <param name="deltaTime">Time since last frame</param>
	void Update(float deltaTime);

	/// <summary>
	/// This is where all the draw calls will be
	/// </summary>
	void Render(glm::mat4 view, glm::mat4 projection, glm::vec3 viewPos);

	/// <summary>
	/// Cleanup for when we close the program
	/// </summary>
	void Shutdown();

	/// <summary>
	/// Returns the current active player (whoever's turn it is)
	/// </summary>
	Player* getCurrentPlayer() { return _currentPlayer; }
	Player* getPlayerWithID(int id);
	ChessBoard* getBoard() { return _gameBoard; }
	ChessPiece* getCurrentPiece() { return _selectedPiece; }
	std::vector<glm::ivec2> getValidMoveSet() { return validMoveSet; }
	void setCurrentPiece(ChessPiece* piece); 
	void changeTurn();
};
#endif