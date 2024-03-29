#pragma once
#include "State.h"
#include "SnakeGameEngine.h"
#include <Qrect>
#include <qcoreapplication.h>
#include <iostream>
#include <sstream>
#include <string>


class SnakeGameState: public State
{
public:
	SnakeGameState();
	virtual ~SnakeGameState() = default;
	virtual void draw(QPainter& painter) = 0;
	
	virtual bool isValid() = 0;
	virtual void entering() = 0;
	virtual void exiting() = 0;
	virtual void tic(qreal elapsedTime) = 0;
	virtual void updateKeys(const PressedKeys& pressedKeys) = 0;
	SnakeGameEngine& getEngine() const;
	
protected:
	SnakeGameEngine& mSnakeEngine;
	PressedKeys mPressedKeys;

};