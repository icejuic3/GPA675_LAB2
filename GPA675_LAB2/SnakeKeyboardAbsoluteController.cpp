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
        case Qt::Key_W: // Utiliser 'W' pour monter 
            mControlledSnake.goUp();
            break;
        case Qt::Key_S: // Utiliser 'S' pour descendre
            mControlledSnake.goDown();
            break;
        case Qt::Key_A: // Utiliser 'A' pour aller à gauche
            mControlledSnake.goLeft();
            break;
        case Qt::Key_D: // Utiliser 'D' pour aller à droite
            mControlledSnake.goRight();
            break;
        }
    }
}
