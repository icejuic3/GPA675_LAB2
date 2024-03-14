#include "SnakeKeyboardController.h"

SnakeKeyboardController::SnakeKeyboardController(Snake& snake)
	:Controller(snake)
	,mControlledSnake{ snake }
{
}

SnakeKeyboardController::~SnakeKeyboardController()
{
}

void SnakeKeyboardController::control(const PressedKeys& pressedKeys)
{
}