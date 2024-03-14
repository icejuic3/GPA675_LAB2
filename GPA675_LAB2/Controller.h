#pragma once
#include "Snake.h"

class Controller
{
public:

	Controller(Snake& snake);
	virtual ~Controller();
	virtual void control();

private:

	Snake& mControlledSnake;

	class SnakeKeyboardController
	{

	};

	class SnakeKeyboardAbsoluteController
	{
		snakeKeyboardAbsoluteController();

	};
}; 