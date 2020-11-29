#include "GameplayState.h"

// Reference Headers
#include "../ChessGameManager.h"
#include "../ChessBoard.h"
#include "../ChessPiece.h"
#include "../Player.h"

GameplayState::GameplayState(){
}

void GameplayState::Enter(ChessGameManager& gameManager) {

}

void GameplayState::HandleInput(ChessGameManager& gameManager) {

	// PSEUDO If currentplayerID = currentPlayer's turn -> get input from that player
	// if( left mouse click -> cast ray into screen. If the ray hits a ChessPiece, return that ChessPiece
	// Can only click on own pieces. Once piece is clicked on, it is selected.
	ChessPiece* clickedPiece = nullptr; //TODO: = piece from ray cast

	if (clickedPiece != nullptr) {

		if (clickedPiece->getPlayerID() == gameManager.getCurrentPlayer()->getID()) {
			clickedPiece->setSelection(true);

			// Get all the possible cells that this piece may move to
			std::vector<glm::ivec2> moves = gameManager.getBoard()->highlightMoves(clickedPiece, clickedPiece->getPosition());
		}
	}
}

void GameplayState::Update(ChessGameManager& gameManager) {

	
}

GameplayState::~GameplayState() {

}
