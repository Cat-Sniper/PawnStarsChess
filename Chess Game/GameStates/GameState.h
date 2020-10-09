#ifndef GAMESTATE_H
#define GAMESTATE_H

// Forward Declaration
class ChessGameManager;

class GameState {
public:
	virtual void Enter(ChessGameManager& gameManager) {}
	virtual void HandleInput(ChessGameManager& gameManager) {}
	virtual void Update(ChessGameManager& gameManager, float deltaTime) {}
	virtual ~GameState() {}	// Destructor aka exit
};
#endif
