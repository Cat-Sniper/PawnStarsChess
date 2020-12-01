/// ChessBoard.cpp
/// -----------------------------------------
/// 8x8 grid composed of 'Cells' who know which ChessPiece is sitting on them.
/// Created Ashraf 
#include "ChessBoard.h"


// Reference headers
#include "GlobalTypes.h"
#include "ChessGameManager.h"
#include "Player.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "ChessPiece.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "Texture.h"
#include <string>




ChessBoard::ChessBoard(ChessGameManager* game) : _pieceShader("vertex.vert", "fragment.frag"), _boardShader("texVertex.vert", "texFragment.frag") {
	_gameManager = game;
	boardInit();
}

ChessBoard::~ChessBoard()
{
	// Delete all chess pieces that were added to the heap
	for (int i = 0; i < 8; i++) {
		
		for (int j = 0; j < 8; j++) {
			
			if (_board[i][j].getCurrentChessPiece() != nullptr) delete _board[i][j].getCurrentChessPiece();
		}
	}
}

void ChessBoard::boardInit()
{

	glGenVertexArrays(1, &cubeVAO);
	glGenBuffers(1, &cubeVBO);
	glBindVertexArray(cubeVAO);
	glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glGenBuffers(1, &cubeIBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeIBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeIndicies), cubeIndicies, GL_STATIC_DRAW);
	glBindVertexArray(0);

	Texture cubeTextures[2] = { Texture(RELATIVE_PATH + "blackMarble.jpg", GL_RGB, 0), Texture(RELATIVE_PATH + "whiteMarble.jpg", GL_RGB, 1) };
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			_board[i][j] = Cell();
			models[8 * i + j] = glm::translate(identity, glm::vec3((float)j, (float)i, 0.0f));
			
			if (isEven(i, j)) //COLORS THE BOARD ROW BY ROW
			{
				_board[i][j].setBlack();
			}
			else
				_board[i][j].setWhite();

			if (i == 0 || i == 1 || i == 6 || i == 7) //if within the furst two rows or the last two rows.
			{
				switch (i)
				{
					//CASE 0 AND 1 ARE FOR PLAYER 0 (WHITE)
				case 0: //fill bottom row, passing the column as the argument
					_board[i][j].addChessPiece(createBTRow(j , 0));
					_board[i][j].getCurrentChessPiece()->setPosition(glm::ivec2(i,j));
					_gameManager->getPlayerWithID(0)->givePiece(_board[i][j].getCurrentChessPiece());
					
					break;
				case 1:
					_board[i][j].addChessPiece(createChessPiece("pawn", 0));
					_board[i][j].getCurrentChessPiece()->setPosition(glm::ivec2(i, j));
					_gameManager->getPlayerWithID(0)->givePiece(_board[i][j].getCurrentChessPiece());
					break;

					//CASE 6 AND 7 ARE FOR PLAYER 1 (BLACK)
				case 6:
					_board[i][j].addChessPiece(createChessPiece("pawn", 1));
					_board[i][j].getCurrentChessPiece()->setPosition(glm::ivec2(i, j));
					_gameManager->getPlayerWithID(1)->givePiece(_board[i][j].getCurrentChessPiece());
					break;
				case 7:
					_board[i][j].addChessPiece(createBTRow(j, 1));
					_board[i][j].getCurrentChessPiece()->setPosition(glm::ivec2(i, j));
					_gameManager->getPlayerWithID(1)->givePiece(_board[i][j].getCurrentChessPiece());
					break;
				default: //SHOULD I KEEP THIS?
					_board[i][j].removeChessPiece();
				}
			}
		}
	}
}

bool ChessBoard::isEven(int i, int j)
{
	if ((i + j) % 2 == 0)
	{
		return true;
	}
	else
		return false;
}

ChessPiece *ChessBoard::createChessPiece(std::string pieceType, int playerID)
{
	glm::mat4 rsModel;

	if (pieceType == "bishop")
	{
		rsModel = glm::rotate(identity, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		rsModel = glm::scale(rsModel, glm::vec3(0.3f, 0.3f, 0.3f));
		return new Bishop(playerID, rsModel, _pieceShader);
	}
	else if (pieceType == "king")
	{

		rsModel = glm::rotate(identity, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		rsModel = glm::scale(rsModel, glm::vec3(0.4f, 0.4f, 0.4f));
		return new King(playerID, rsModel, _pieceShader);
	}
	else if (pieceType == "knight")
	{
		if (playerID == 0) {
			rsModel = glm::rotate(identity, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			rsModel = glm::rotate(rsModel, glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		}
		else {
			rsModel = glm::rotate(identity, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		}
		rsModel = glm::scale(rsModel, glm::vec3(0.4f, 0.45f, 0.4f));
		return new Knight(playerID, rsModel, _pieceShader);
	}
	else if (pieceType == "pawn")
	{
		rsModel = glm::rotate(identity, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		rsModel = glm::scale(rsModel, glm::vec3(0.22f, 0.25f, 0.22f));
		return new Pawn(playerID, rsModel, _pieceShader);
	}
	else if (pieceType == "queen")
	{
		rsModel = glm::rotate(identity, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		rsModel = glm::scale(rsModel, glm::vec3(0.4f, 0.4f, 0.4f));
		return new Queen(playerID, rsModel, _pieceShader);
	}
	else if (pieceType == "rook")
	{
		rsModel = glm::rotate(identity, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		rsModel = glm::scale(rsModel, glm::vec3(0.4f, 0.7f, 0.4f));
		return new Rook(playerID, rsModel, _pieceShader);
	}

	return nullptr;
}

ChessPiece *ChessBoard::createBTRow(int columnPosition, int playerID) //based on position in the column (PASS j) it will create the subsequent chess piece, NOTE player 0 is white 1 is black
{
	switch (columnPosition)
	{
	case 0:
	case 7:
		return createChessPiece("rook", playerID);
		break;

	case 1:
	case 6:
		return createChessPiece("knight", playerID);
		break;

	case 2:
	case 5:
		return createChessPiece("bishop", playerID);
		break;

	case 3:
		return createChessPiece("queen", playerID);
		break;

	case 4:
		return createChessPiece("king", playerID);
		break;
	}
}

void ChessBoard::movePiece(glm::ivec2 pos1, glm::ivec2 pos2)
{
	ChessPiece* piece = getPieceAtLocation(pos1);
	_board[pos1.x][pos1.y].deleteChessPiece();

	// check if the moved piece just took out another piece
	ChessPiece* deadPiece = _board[pos2.x][pos2.y].getCurrentChessPiece();
	if (deadPiece != nullptr) {
		deadPiece->setAlive(false);
	}

	piece->setPosition(pos2);
	_board[pos2.x][pos2.y].addChessPiece(piece);
}

/// <summary>
/// Erase moves from the move list generated by the chess piece. return the final valid move set.
/// </summary>
/// <param name="piece">the currently selected chess piece</param>
/// <returns> a vector with all the moves the player can make</returns>
std::vector<glm::ivec2> ChessBoard::getValidatedMoves(ChessPiece *piece)
{
	std::vector<glm::ivec2> moveList = piece->getMoves(BOARD_WIDTH, BOARD_HEIGHT);

	for (int i = 0; i < moveList.size(); i++)
	{
		glm::ivec2 pos = moveList[i]; // if it's occupied by the same player
		if (_board[pos.x][pos.y].isOccupied() && _board[pos.x][pos.y].getCurrentChessPiece()->getPlayerID() == piece->getPlayerID())
		{
			moveList.erase(moveList.begin()); //remove the position from the list of positions
		}
	}

	return moveList;
}

void ChessBoard::drawBoard(glm::mat4 view, glm::mat4 projection, glm::vec3 lightPos, glm::vec3 viewPos) {
	int base = 0;

	_boardShader.bind();
	_boardShader.setMat4Uniform("projection", glm::value_ptr(projection));
	_boardShader.setMat4Uniform("view", glm::value_ptr(view));

	//drawing the board
	glBindVertexArray(cubeVAO);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			_boardShader.setMat4Uniform("model", glm::value_ptr(models[8 * i + j]));
			_boardShader.setIntUniform("Tex1", abs(base + j % 2));
			glDrawElements(GL_TRIANGLES, sizeof(cubeIndicies) / sizeof(unsigned int), GL_UNSIGNED_INT, 0);
		}
		base = (base == 0) ? -1 : 0;
	}
}
void ChessBoard::drawHighlights(glm::mat4 view, glm::mat4 projection, glm::vec3 lightPos, glm::vec3 viewPos)
{

}
