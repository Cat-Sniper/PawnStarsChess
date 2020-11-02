/// "ChessGameManager.cpp"
/// ----------------------
/// Essentially the core system to the game - manages the game loop and glues everything together.
/// Created: Oct. 8, 2020 Michael Ward
///  Edited: Oct. 20, 2020 Michael Ward

#include "ChessGameManager.h"
#include "GameStates/GameState.h"

ChessGameManager::ChessGameManager()
{
	m_currentGameState = nullptr;
}

void ChessGameManager::Init() 
{

}

void ChessGameManager::Update(float deltaTime)
{
	m_currentGameState->HandleInput(*this);
	m_currentGameState->Update(*this, deltaTime);
}

void ChessGameManager::Render()
{

}

void ChessGameManager::Shutdown()
{

}


