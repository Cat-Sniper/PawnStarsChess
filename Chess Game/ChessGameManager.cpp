/// "ChessGameManager.cpp"
/// ----------------------
/// Essentially the core system to the game - manages the game loop and glues everything together.
/// Created: Oct. 8, 2020 Michael Ward
///  Edited: Oct. 20, 2020 Michael Ward

#include "ChessGameManager.h"
#include "Player.h"
#include "ChessPiece.h"
#include "GameStates/GameState.h"

ChessGameManager::ChessGameManager()
{
	_currentGameState = nullptr;

}

void ChessGameManager::Init()
{
	_players.push_back(new Player(0));
	_players.push_back(new Player(1));
}

void ChessGameManager::Update(float deltaTime)
{
	_currentGameState->HandleInput(*this);
	_currentGameState->Update(*this, deltaTime);

	for (auto& player : _players) {
		//player->Update();
	}
}

void ChessGameManager::Render()
{
	for (auto& player : _players) {

		for (auto& chessPiece : player->getPieces()) {
			//chessPiece->Render();
		}
	}
}

void ChessGameManager::Shutdown()
{

}


