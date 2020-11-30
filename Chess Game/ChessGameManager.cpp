/// "ChessGameManager.cpp"
/// ----------------------
/// Essentially the core system to the game - manages the game loop and glues everything together.
/// Created: Michael Ward - Oct. 08, 2020
///  Edited: Michael Ward - Nov. 28, 2020

#include "ChessGameManager.h"
#include "Player.h"
#include "ChessPiece.h"
#include "ChessBoard.h"
#include "GameStates/GameState.h"
#include "GameStates/GameplayState.h"

ChessGameManager::ChessGameManager()
{
	_currentGameState = nullptr;
	_currentPlayer = nullptr;
	_gameBoard = nullptr;
	_selectedPiece = nullptr;

	//TESTING DELETE AFTER PLACING APPROPRIATELY IN MAIN.CPP
	Init();
}

void ChessGameManager::Init()
{
	_players.push_back(new Player(0));
	_players.push_back(new Player(1));

	_currentGameState = new GameplayState;

	//TESTING STUFF - DELETE LATER
	_currentPlayer = _players.at(0);
	//_gameBoard = new ChessBoard(this);
}

void ChessGameManager::Update(float deltaTime)
{
	_currentGameState->HandleInput(*this);
	_currentGameState->Update(*this, deltaTime);

	_currentPlayer->takeTurn();
}

void ChessGameManager::Render()
{
	//_gameBoard->Render();

	for (auto& player : _players) {

		for (auto& chessPiece : player->getPieces()) {
			if (chessPiece->getAlive()) {
				// chessPiece->Render();
			}
		}
	}
}

void ChessGameManager::Shutdown()
{
	// Delete objects instantiated on the heap
	for (auto& i : _players) {
		delete i;
	}

	delete _currentGameState;
	delete _gameBoard;
}

Player* ChessGameManager::getPlayerWithID(int id)
{
	for (auto& player : _players) {
		if (player->getID() == id) return player;
	}

	return nullptr;
}


