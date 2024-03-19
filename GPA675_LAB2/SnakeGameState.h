#pragma once
#include "State.h"
#include "SnakeGameEngine.h"

class SnakeGameState: public State
{
public:

	SnakeGameState();
	virtual ~SnakeGameState() = default;
	virtual void draw(QPainter& painter) = 0;



protected:
	//SnakeGameEngine mSnakeEngine;
};