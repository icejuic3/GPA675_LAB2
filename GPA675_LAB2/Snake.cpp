#include "Snake.h"
#include "Pellet.h"
#include "Obstacle.h"
//Pellet
#include "AcceleratingPellet.h"
#include "GrowingPellet.h"
#include "AddObstaclePellet.h"

#include "SnakeKeyboardController.h"
#include "SnakeKeyboardAbsoluteController.h"
#include "SnakeGameEngine.h"

Snake::Snake(Board& board, QPoint point)
    :DynamicEntity(board)
    , mName{}
    , mScore{ 0 }
    , mBody{Body(point)}
    , mHeadDirection{ Direction::toUp }
    , mSpeed{10}
    , mSizeToGrow{ 0 }
    , mHeadColor{ QColor(0, 255, 0) }
    , mBodyColor{ QColor(0, 122, 0) }
    , mReverseProhibited{}
    , LUTTurnLeftDirection{ Direction::toLeft,Direction::toUp, Direction::toRight,Direction::toDown }
    , LUTTurnRightDirection{ Direction::toRight,Direction::toDown, Direction::toLeft,Direction::toUp }
    , LUTOppositeDirection{ Direction::toDown, Direction::toLeft,Direction::toUp,Direction::toRight }
    , LUTDirectionAction{}
    , mTicTime{0.0}
    , mBodylength{2}
    , mAlive{true}
{
    grow(mBodylength);

}

Snake::~Snake()
{
}

bool Snake::isValid()
{
    // verifie la taille minimal du serpent
    if (mBody.size() < 2) { //la verification pour la taille du corps inclus la tete ou seulement le reste du corps?
        return false;
    }
    return true;
}

bool Snake::isAlive()
{

    return mAlive;
}

void Snake::ticPrepare(real elapsedTime)
{

    if (elapsedTime > 0) {
        mTicTime += elapsedTime;
    }
   
    if (mTicTime > 1 / mSpeed) {

        //prepare le changement de direction du serpent
        if (!mPressedKeys.empty()) {                
            mController->control(mPressedKeys);       
        }

        if (mSizeToGrow) {

            grow(1);
        }
        else {

            advance(1);
        }

        mTicTime = 0;
    }
}

void Snake::ticExecute()
{
    //1) Mettre a jour la position de la tete du serpent et ajouter les nouveaux segments
    //2) collision avec fruit->augmentation de la taille du serpent et point
    //3) collision avec mur ou lui meme/autre serpent  --> reduire serpent ou le detruire.


    if (dynamic_cast<GrowingPellet*>(mColliding)) {         //si collision avec une Growing Pellet

        mScore = +1;
        mSizeToGrow = 1;
        mColliding = nullptr;       //reset l'etat de collision

    }
    if (dynamic_cast<AcceleratingPellet*>(mColliding)) {    //si collision avec une Accelerating Pellet

        mScore = +1;
        mSpeed += 1;
        mColliding = nullptr;       //reset l'etat de collision

    }
    if (dynamic_cast<AddObstaclePellet*>(mColliding)) {     //si collision avec une Pellet

		
		mColliding = nullptr;       //reset l'etat de collision
    }
    if (dynamic_cast<Obstacle*>(mColliding)) {              //si collision avec un Obstacle

        mAlive = false;
        mColliding = nullptr;       //reset l'etat de collision
    }
   
    if (dynamic_cast<Snake*>(mColliding)) {

        mAlive = false;
        mColliding = nullptr;
    }
 
}

void Snake::draw(QPainter& painter)
{

    if (!mBody.isEmpty()) {

        for (auto it(mBody.begin()); it != mBody.end(); ++it) {

            if (it == mBody.begin()) {
                painter.setPen(QPen(mHeadColor));
                painter.drawPoint(*it);
            }
            else {
                painter.setPen(QPen(mBodyColor));
                painter.drawPoint(*it);
            }
        }
    }
}

bool Snake::isColliding(QPoint const& position)
{
    return mColliding;
}

QString Snake::name()
{
    return mName;
}

int Snake::score()
{
    return mScore;
}

size_t Snake::bodyLength()
{
    return mBody.size();
}

QPoint Snake::headPosition()
{
    return *mBody.first();
}

Direction Snake::headDirection()
{
    return mHeadDirection;
}

SpeedType Snake::speed()
{
    return mSpeed;
}

QColor Snake::headColor()
{
    return mHeadColor;
}

QColor Snake::bodyColor()
{
    return mBodyColor;
}

Controller* Snake::controller()
{
    return mController;
}

void Snake::updateKeys(const PressedKeys& pressedKeys)
{
    mPressedKeys = pressedKeys;
}

void Snake::setName(QString name)
{
    mName = name;
}

void Snake::reset(QPoint headPosition, Direction headDirection, size_t bodyLength, SpeedType initialSpeed)
{
    //Reinitialise la tete du serpent
    mBody.clear();                      //on s'assure que le corps est vide
    addFirst(headPosition);             //creer la tete ? la position donnee
    mHeadDirection = headDirection;     //reinitialise la direction

    //on calcule chaque position ? rajouter au serpent individuellement
    QPoint pos = headPosition;

    for (size_t i{}; i < bodyLength - 1; ++i) {

        switch (headDirection) {

        case Direction::toUp:
            pos.setY(pos.y() - 1);
            break;

        case Direction::toRight:
            pos.setX(pos.x() - 1);
            break;

        case Direction::toDown:
            pos.setY(pos.y() + 1);
            break;

        case Direction::toLeft:
            pos.setX(pos.x() + 1);
            break;
        }
        addLast(pos);         //apres le calcul, nous rajoutons la partie du serpent
    }

    mSpeed = initialSpeed;          //reinitialise la vitesse
    mScore = 0;                     //reinitialise le score
    mSizeToGrow = 0;                //reinitialise la croissance
}

void Snake::setController(Controller& controller)
{
    mController = &controller;
}

void Snake::setSpeed(SpeedType speed)
{
    mSpeed = speed;
}

void Snake::increaseSpeed(SpeedType amout)
{
    mSpeed += amout;
}

void Snake::decreaseSpeed(SpeedType amout)
{
    mSpeed -= amout;
}

void Snake::addFirst(QPoint pos)
{
    mBody.addFirst(pos);
    mColliding = mBoard.setValue(pos.x(), pos.y(), this);
}

void Snake::decelerate(SpeedType percentLess)
{
    mSpeed *= 1 - percentLess; 
}

void Snake::advance(size_t size)
{
    for (size_t i{}; i < size; ++i) {

        QPoint curPos = headPosition();
        QPoint newPos = curPos;

        if (headDirection() == Direction::toUp) {
            newPos.setY(curPos.y() - 1);
        }
        else if (headDirection() == Direction::toRight) {
            newPos.setX(curPos.x() + 1);
        }
        else if (headDirection() == Direction::toDown) {
            newPos.setY(curPos.y() + 1);
        }
        else if (headDirection() == Direction::toLeft) {
            newPos.setX(curPos.x() - 1);
        }
        addFirst(newPos);
        removeLast();
    }
}

void Snake::addLast(QPoint pos)
{
    mBody.addLast(pos);
    mBoard.setValue(pos.x(), pos.y(), this);
}

void Snake::accelerate(SpeedType percentMore)
{
    mSpeed = mSpeed * (percentMore + 1);
}

void Snake::removeLast()
{
    QPoint pos = *mBody.last();
    mBody.removeLast();
    mBoard.reset(pos.x(), pos.y());
}

void Snake::setColors(QColor head, QColor body)
{
    mHeadColor = head;
    mBodyColor = body;
}

void Snake::adjustScore(int score)
{
    mScore = score;
}

void Snake::turnRight()
{
    mHeadDirection = LUTTurnRightDirection[static_cast<int>(mHeadDirection)];
}

void Snake::turnLeft()
{
    mHeadDirection = LUTTurnLeftDirection[static_cast<int>(mHeadDirection)];
}

void Snake::goUp()
{
    if (mHeadDirection != LUTOppositeDirection[static_cast<int>(Direction::toUp)]) {
        mHeadDirection = Direction::toUp;
    }
}

void Snake::goRight()
{
    if (mHeadDirection != LUTOppositeDirection[static_cast<int>(Direction::toRight)]) {
        mHeadDirection = Direction::toRight;
    }
}

void Snake::goDown()
{
    if (mHeadDirection != LUTOppositeDirection[static_cast<int>(Direction::toDown)]) {
        mHeadDirection = Direction::toDown;
    }
}

void Snake::goLeft()
{
    if (mHeadDirection != LUTOppositeDirection[static_cast<int>(Direction::toLeft)]) {
        mHeadDirection = Direction::toLeft;
    }
}

void Snake::goToward(Direction direction)
{
    if (mHeadDirection != LUTOppositeDirection[static_cast<int>(direction)]) {
        mHeadDirection = direction;
    }
}

void Snake::grow(size_t size)
{
    for (size_t i{}; i < size; ++i) {

        QPoint curPos = headPosition();
        QPoint newPos = curPos;
        
        if (headDirection() == Direction::toUp) {
            newPos.setY(curPos.y() - 1);
        }
        else if (headDirection() == Direction::toRight) {
            newPos.setX(curPos.x() + 1);
        }
        else if (headDirection() == Direction::toDown) {
            newPos.setY(curPos.y() + 1);
        }
        else if (headDirection() == Direction::toLeft) {
            newPos.setX(curPos.x() - 1);
        }
        addFirst(newPos);
    }
    mSizeToGrow = 0;
}

void Snake::shrink(size_t size)
{
    mSizeToGrow -= size;
}