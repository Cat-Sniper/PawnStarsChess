#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <vector>

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
	void Render();

	/// <summary>
	/// Cleanup for when we close the program
	/// </summary>
	void Shutdown();

	/// <summary>
	/// Returns the current active player (whoever's turn it is)
	/// </summary>
	Player* getCurrentPlayer() { return _currentPlayer; }
	ChessBoard* getBoard() { return _gameBoard; }
};
#endif