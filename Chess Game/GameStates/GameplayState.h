#ifndef GAMPEPLAY_STATE_H
#define GAMEPLAY_STATE_H

#include "GameState.h"
class GameplayState : public GameState {

private:

public:
	GameplayState();
	void Enter(ChessGameManager& gameManager);
	void HandleInput(ChessGameManager& gameManager);
	void Update(ChessGameManager& gameManager);
	~GameplayState();
};

#endif