/// "ChessGameManager.cpp"
/// ----------------------
/// Essentially the core system to the game - manages the game loop and glues everything together.
/// Created: Oct. 8, 2020 Michael Ward
///  Edited: Oct. 8, 2020 Michael Ward

#include "ChessGameManager.h"
#include "GameStates/GameState.h"

ChessGameManager::ChessGameManager()
{
	m_currentGameState = nullptr;
}

/// <summary>
/// Use this to initialize anything at the very start, when the game first launches
/// </summary>
void ChessGameManager::Init() 
{

}

/// <summary>
/// This is where logic is run once a frame: we have a target of 60 fps
/// </summary>
/// <param name="deltaTime">Time since last frame</param>
void ChessGameManager::Update(float deltaTime)
{
	m_currentGameState->HandleInput(*this);
	m_currentGameState->Update(*this, deltaTime);
}

/// <summary>
/// This is where all the draw calls will be
/// </summary>
void ChessGameManager::Render()
{

}


/// <summary>
/// Cleanup for when we close the program
/// </summary>
void ChessGameManager::Shutdown()
{

}


