/// "ChessPiece.h"
/// ----------------------------------
/// The abstract class ChestPiece, from which all the specific pieces are derived.
/// Author: Yile Zhu
/// Edited: Michael Ward - November 28, 2020

#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "GlobalTypes.h"

#include "Model.h"
#include "Shader.h"

#include <vector>


class ChessPiece {	

protected:
	int _playerID;
	bool _isAttacked;
	bool _hasMoved;
	bool _isAlive;
	bool _selected;
	glm::ivec2 _position;
	glm::vec3 _color;
	Shader* _targetShader;
	glm::mat4 _rsMat;
	glm::mat4 _nMat;
	Model _pieceModel;

public:
	ChessPiece(int playerID, glm::ivec2& position, glm::vec3& color, glm::mat4& rsMat, Shader& targetShader);

	int getPlayerID();
	void setPlayerID(int newPlayerID);

	bool getAttacked();
	void setAttacked(bool attacked);

	bool getMoved();
	void setMoved(bool moved);

	bool getAlive();
	void setAlive(bool alive);

	bool getSelected();
	void setSelected(bool selected);

	glm::ivec2 getPosition();
	void setPosition(glm::ivec2 newPos);

	glm::vec3 getColor();
	void setColor(glm::vec3& newColor);

	Model getModel();		

	inline Shader* getShaderPtr();
	void setShaderPtr(Shader* newShaderPtr);

	glm::mat4 getRSMat();
	void setRSMat(glm::mat4& newRSMat);

	glm::mat4 getNMat();
	//cannot set nMat, it is based on the model matrix and will be re-derived whenever a new RSMat is assigned

	static bool outOfBounds(glm::ivec2& testPos, int xLimit, int yLimit);
	void draw(glm::mat4& view, glm::mat4& projection, glm::vec3& lightPos, glm::vec3& viewPos);

	virtual std::vector<glm::ivec2> getMoves(int xLimit, int yLimit);
};   

#endif  // CHESSPIECE_H