#pragma once
#include "Snake.h"
#include "PressedKeys.h"


class Controller
{
public:

	Controller(Snake& snake);
	virtual ~Controller();
	virtual void control(const PressedKeys& pressedKeys) = 0;

private:

	Snake& mControlledSnake;
};
