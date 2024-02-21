#include "Snake.h"

Snake::Snake()
{
}

Snake::Snake(Snake::DynamicEntity other)
{
}

Snake& Snake::operator=(Snake::DynamicEntity other)
{
    // TODO: insérer une instruction return ici
}

Snake::~Snake()
{
}

bool Snake::isValid()
{
    return false;
}

bool Snake::isAlive()
{
    return false;
}

void Snake::ticPrepare(real elapsedTime)
{
}

void Snake::ticExecute()
{
}

void Snake::draw(QPainter& painter)
{
}

bool Snake::isColliding(QPoint const& position)
{
    return false;
}

QString Snake::name()
{
    return QString();
}

int Snake::score()
{
    return 0;
}

size_t Snake::bodyLength()
{
    return size_t();
}

QPoint Snake::headPosition()
{
    return QPoint();
}

Direction Snake::headDirection()
{
    return Direction();
}

SpeedType Snake::speed()
{
    return SpeedType();
}

QColor Snake::headColor()
{
    return QColor();
}

QColor Snake::bodyColor()
{
    return QColor();
}

bool Snake::isReverseProhibited()
{
    return false;
}

Controller& Snake::controller()
{
    // TODO: insérer une instruction return ici
}

void Snake::setName(QString name)
{
}

void Snake::reset(QPoint headPosition, direction headDirection, size_t bodyLength, SpeedType initialSpeed)
{
}

void Snake::setSpeed(SpeedType speed)
{
}

void Snake::increaseSpeed(SpeedType amout)
{
}

void Snake::decreaseSpeed(SpeedType amout)
{
}

void Snake::decelerate(SpeedType percentLess)
{
}

void Snake::accelerate(SpeedType percentMore)
{
}

void Snake::setColors(QColor head, QColor body)
{
}

void Snake::prohibitedReverse(bool Prohibited)
{
}

void Snake::adjustScore(int score)
{
}

void Snake::turnRight()
{
}

void Snake::turnLeft()
{
}

void Snake::goUp()
{
}

void Snake::goRight()
{
}

void Snake::goDown()
{
}

void Snake::goLeft()
{
}

void Snake::goToward(Direction direction)
{
}

void Snake::grow(size_t size)
{
}

void Snake::shrink(size_t size)
{
}

Controller::Controller(Snake& snake)
{
}

Controller::~Controller()
{
}

void Controller::control()
{
}
