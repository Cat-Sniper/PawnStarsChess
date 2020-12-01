#include "ChessPiece.h"

ChessPiece::ChessPiece(int playerID, glm::mat4& rsMat, Shader& targetShader) {
	_playerID = playerID;
	_position = glm::ivec2(0, 0);
	_rsMat = rsMat;
	_targetShader = &targetShader;
	_nMat = glm::transpose(glm::inverse(rsMat));
	_isAlive = true;
	_isAttacked = false;
	_hasMoved = false;
	_selected = false;

	if (playerID == 0) _color = glm::vec3(PLAYER1_COLOR.r, PLAYER1_COLOR.g, PLAYER1_COLOR.b);
	else _color = glm::vec3(PLAYER2_COLOR.r, PLAYER2_COLOR.g, PLAYER2_COLOR.b);
}

int ChessPiece::getPlayerID() { return  _playerID; }
void ChessPiece::setPlayerID(int newPlayerID) {
	 _playerID = newPlayerID;
}

bool ChessPiece::getAttacked() { return _isAttacked; }
void ChessPiece::setAttacked(bool attacked) {
	_isAttacked = attacked;
}

bool ChessPiece::getMoved() {return _hasMoved; }
void ChessPiece::setMoved(bool moved) {
	_hasMoved = moved;
}

bool ChessPiece::getAlive() { return _isAlive; }
void ChessPiece::setAlive(bool alive) {
	_isAlive = alive;
}

bool ChessPiece::getSelected() { return _selected; }
void ChessPiece::setSelected(bool selected) {
	_selected = selected;
}

glm::ivec2 ChessPiece::getPosition() { return _position; }
void ChessPiece::setPosition(glm::ivec2 newPos) {
	_position = newPos;
}

glm::vec3 ChessPiece::getColor() { return _color; }
void ChessPiece::setColor(glm::vec3& newColor) {
	_color = newColor;
}

Model ChessPiece::getModel() { return _pieceModel; }


inline Shader* ChessPiece::getShaderPtr() { return _targetShader; }
void ChessPiece::setShaderPtr(Shader* newShaderPtr) {
	_targetShader = newShaderPtr;
}

inline glm::mat4 ChessPiece::getRSMat() { return _rsMat; }
void ChessPiece::setRSMat(glm::mat4& newRSMat) {
	_rsMat = newRSMat;
	_nMat = glm::transpose(glm::inverse(_rsMat));
}

inline glm::mat4 ChessPiece::getNMat() { return _nMat; }
//cannot set nMat, it is based on the model matrix and will be re-derived whenever a new RSMat is assigned

bool ChessPiece::outOfBounds(glm::ivec2& testPos, int xLimit, int yLimit) {
	if (testPos.x >= 0 && testPos.x < xLimit && testPos.y >= 0 && testPos.y < yLimit) return false;

	return true;
}

void ChessPiece::draw(glm::mat4 view, glm::mat4 projection, glm::vec3 lightPos, glm::vec3 viewPos) {
	
	//bind the shader
	_targetShader->bind();

	//generate model matrix
	glm::mat4 model_in_worldspace = glm::translate(identity, glm::vec3(_position, 0.5f));
	model_in_worldspace = model_in_worldspace * _rsMat;

	//set necessary uniforms
	_targetShader->setMat4Uniform("model", glm::value_ptr(model_in_worldspace));
	_targetShader->setMat4Uniform("view", glm::value_ptr(view));
	_targetShader->setMat4Uniform("projection", glm::value_ptr(projection));
	_targetShader->setMat4Uniform("nMat", glm::value_ptr(_nMat));
	_targetShader->setVec3Uniform("lightPos", glm::value_ptr(lightPos));
	_targetShader->setVec3Uniform("viewPos", glm::value_ptr(viewPos));
	_targetShader->setVec3Uniform("objectColor", glm::value_ptr(_color));

	//draw on the model
	_pieceModel.Draw(*_targetShader);
}

std::vector<glm::ivec2> ChessPiece::getMoves(int xLimit, int yLimit) { return {}; }