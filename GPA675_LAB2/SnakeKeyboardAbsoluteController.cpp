#include "SnakeKeyboardAbsoluteController.h"

SnakeKeyboardAbsoluteController::SnakeKeyboardAbsoluteController(Snake& snake)
	:SnakeKeyboardController(snake)
    ,mControlledSnake{ snake }
{
}

SnakeKeyboardAbsoluteController::~SnakeKeyboardAbsoluteController()
{
}

void SnakeKeyboardAbsoluteController::control(const PressedKeys& pressedKeys)
{

    for (Qt::Key key : pressedKeys) {

        switch (key) {

        case Qt::Key_Up: 
            mControlledSnake.goUp();
            break;

        case Qt::Key_Down: 
            mControlledSnake.goDown();
            break;

        case Qt::Key_Left: 
            mControlledSnake.goLeft();
            break;

        case Qt::Key_Right: 
            mControlledSnake.goRight();
            break;
        }
    }
}
