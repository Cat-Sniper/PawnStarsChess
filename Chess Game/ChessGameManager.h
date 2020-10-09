#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

class GameState;

class ChessGameManager {

private:
	GameState *m_currentGameState;
public:

	ChessGameManager();
	void Init();
	void Update(float deltaTime);
	void Render();
	void Shutdown();
};
#endif