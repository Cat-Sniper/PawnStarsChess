#include "ChessPiece.h"
#include "GL\glew.h"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"

ChessPiece::ChessPiece(int playerID, glm::ivec2& position, glm::vec3& color, glm::mat4& rsMat, Model& pieceModel, Shader& targetShader) {
	_playerID = playerID;
	_position = position;
	_color = color;
	_rsMat = rsMat;
	_pieceModel = &pieceModel;
	_targetShader = &targetShader;
	_nMat = glm::transpose(glm::inverse(rsMat));

	_isAlive = true;
	_isAttacked = false;
	_hasMoved = false;
	_selected = false;
}

inline int ChessPiece::getPlayerID() { return playerID; }
void ChessPiece::setPlayerID(int newPlayerID) {
	playerID = newPlayerID;
}

inline bool ChessPiece::getAttacked() { return isAttacked; }
void ChessPiece::setAttacked(bool attacked) {
	isAttacked = attacked;
}

inline bool ChessPiece::getMoved() {return hasMoved; }
void ChessPiece::setMoved(bool moved) {
	hasMoved = moved;
}

inline bool ChessPiece::getAlive() { return isAlive; }
void ChessPiece::setAlive(bool alive) {
	isAlive = alive;
}

inline bool ChessPiece::getSelected() { return selected; }
void ChessPiece::setSelected(bool selected) {
	this->selected = selected;
}

inline glm::ivec2 ChessPiece::getPosition() { return position; }
void ChessPiece::setPosition(glm::ivec2 newPos) {
	position = newPos;
}

inline glm::vec3 ChessPiece::getColor() { return color; }
void ChessPiece::setColor(glm::vec3& newColor) {
	color = newColor;
}

inline Model* ChessPiece::getModelPtr() { return pieceModel; }
void ChessPiece::setModelPtr(Model* newModelPtr) {
	pieceModel = newModelPtr;
}

inline Shader* ChessPiece::getShaderPtr() { return targetShader; }
void ChessPiece::setShaderPtr(Shader* newShaderPtr) {
	targetShader = newShaderPtr;
}

inline glm::mat4 ChessPiece::getRSMat() { return rsMat; }
void ChessPiece::setRSMat(glm::mat4& newRSMat) {
	rsMat = newRSMat;
	nMat = glm::transpose(glm::inverse(rsMat));
}

inline glm::mat4 ChessPiece::getNMat() { return nMat; }
//cannot set nMat, it is based on the model matrix and will be re-derived whenever a new RSMat is assigned

bool ChessPiece::outOfBounds(glm::ivec2& testPos, int xLimit, int yLimit) {
	if (testPos.x >= 0 && testPos.x < xLimit && testPos.y >= 0 && testPos.y < yLimit) return false;

	return true;
}

void ChessPiece::draw(glm::mat4& view, glm::mat4& projection, glm::vec3& lightPos, glm::vec3& viewPos) {
	//bind the shader
	targetShader->bind();

	//generate model matrix
	glm::mat4 id = glm::mat4(1.0f);
	glm::mat4 model = glm::translate(id, glm::vec3(position, 0.5f));
	model = model * rsMat;

	//set necessary uniforms
	targetShader->setMat4Uniform("model", glm::value_ptr(model));
	targetShader->setMat4Uniform("view", glm::value_ptr(view));
	targetShader->setMat4Uniform("projection", glm::value_ptr(projection));
	targetShader->setMat4Uniform("nMat", glm::value_ptr(nMat));
	targetShader->setVec3Uniform("lightPos", glm::value_ptr(lightPos));
	targetShader->setVec3Uniform("viewPos", glm::value_ptr(viewPos));
	targetShader->setVec3Uniform("objectColor", glm::value_ptr(color));

	//draw on the model
	pieceModel->Draw(*targetShader);
}

std::vector<glm::ivec2> ChessPiece::getMoves(int xLimit, int yLimit) { return {}; }