#pragma once

#ifndef ENTITY_H
#define ENTITY_H
#include <qpoint.h>
#include <qpainter.h>
#include "Board.h"

using real = double;

class Entity
{
public:
	Entity(Board& board);
	virtual ~Entity();

	double age();											//query
	void setDead();

	virtual bool isValid() = 0;								//query
	virtual bool isAlive() = 0;								//query
	virtual void ticPrepare(real elapsedTime) = 0;
	virtual void ticExecute() = 0;
	virtual void draw(QPainter& painter) = 0;
	virtual bool isColliding(QPoint const& position) = 0;	//query

protected:
	Board& mBoard;
	bool mAlive;
	double mAge;
};
#endif