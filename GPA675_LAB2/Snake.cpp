#include "Snake.h"
#include "Pellet.h"

#include "SnakeKeyboardController.h"
#include "SnakeKeyboardAbsoluteController.h"

Snake::Snake(Board& board)
    :DynamicEntity(board)
    , mController{ new SnakeKeyboardAbsoluteController(*this)}    //controller par default
    , mName{}
    , mScore{ 0 }
    , mBody{Body(QPoint(32,32))}
    , mHeadDirection{ Direction::toUp }
    , mSpeed{1}
    , mSizeToGrow{ 0 }
    , mHeadColor{ QColor(0, 255, 0) }
    , mBodyColor{ QColor(0, 122, 0) }
    , mReverseProhibited{}
    , LUTTurnLeftDirection{}
    , LUTTurnRightDirection{}
    , LUTOppositeDirection{}
    , LUTDirectionAction{}
    , mTicTime{0.0}
{
    grow(6);

    //mBoard.setValue(32, 32, this);  //assigne un pointeur du board au premier Body
}

Snake::~Snake()
{
    //delete mController;
}

bool Snake::isValid()
{
    // v?rifie la taille minimal du serpent
    if (mBody.size() < 2) { //la verification pour la taille du corps inclus la tete ou seulement le reste du corps?
        return false;
    }


    //verifier que nous n'avons pas des positions dupliquees?

    //verifier la tete du serpent se trouve dans les limites de l'arene?

    return true;
}

bool Snake::isAlive()
{
    ////v?rifier si le serpent s'est frapp? lui m?me
    //if (mBody.size() > 4) {

    //    if (mBody.isColliding(headPosition())) {

    //        return false;
    //    }
    //}

    ////v?rifier si le serpent ? frapp? un mur    
    ////a confirmer si on a des bordures


    return true;
}

void Snake::ticPrepare(real elapsedTime)
{


    if (elapsedTime > 0) {
        mTicTime += elapsedTime;
    }
   
    if (mTicTime > 1 / mSpeed) {


        /***************mouvement********************/

        mController->control(mPressedKeys);

        

        /********************************************/

        grow(1);                                    //utiliser pour faire avancer le serpent en grandissant la partie avant
        if (dynamic_cast<Pellet*>(mColliding)) {    //si collision avec une Pellet
            mColliding = nullptr;                   //reset l'etat de collision
        }
        else {
            removeLast();                           //sinon retire une partie arriere
        }
        mTicTime = 0;
    }
    






    //1) calculer la nouvelle position de la tete du serpent dependament de la direction
    //2) verifier s'il y collision  --> fruit, serpent, mur --> a la prochaine position
    // 
    //if (isColliding()) {        //si il y a collision

    //    if (!isAlive) {         //confirme si cest avec un mur ou serpent

    //                
    //    }

    //    mScore += 1;            //sinon cest un fruit
    //    grow(1);


    //}

    //3) preparer les changements de taille du serpent -> croissance, retrecissement

}

void Snake::ticExecute()
{
    //1) Mettre a jour la position de la tete du serpent et ajouter les nouveaux segments
    
    

    //2) collision avec fruit->augmentation de la taille du serpent et point







    //3) collision avec mur ou lui meme/autre serpent  --> reduire serpent ou le detruire.






    /************segment pour grandir serpent**************/
    //if (mSizeToGrow > 0) {
    //
    //    for (size_t i{}; i < mSizeToGrow; ++i) {
    //        mBody.addLast()
    //    }
    //}



}

void Snake::draw(QPainter& painter)
{

    /**************configuration t?te********************************/
    //section a revoir si on dessine une forme comme un rectangle pour utiliser le Qbrush
    //ou si nous changeons directement la couleur du pixel avec painter.drawPoint();
    //painter.setBrush(QBrush(mHeadColor));

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
    return mColliding; //voir avec william pour l'implementation
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

bool Snake::isReverseProhibited()
{
    return mReverseProhibited;
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
    //R?initialise la t?te du serpent
    mBody.clear();                      //on s'assure que le corps est vide
    addFirst(headPosition);       //cr?er la t?te ? la position donn?e
    mHeadDirection = headDirection;     //r?initialise la direction

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
        addLast(pos);         //apr?s le calcul, nous rajoutons la partie du serpent
    }

    mSpeed = initialSpeed;          //r?initialise la vitesse
    mScore = 0;                     //r?initialise le score
    mSizeToGrow = 0;                //r?initialise la croissance
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
    mSpeed *= 1 - percentLess; //percentless doit etre deja en pourcentage
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

void Snake::prohibitedReverse(bool Prohibited)
{
    mReverseProhibited = Prohibited;
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
    if (!isReverseProhibited() || mHeadDirection != LUTOppositeDirection[static_cast<int>(Direction::toUp)]) {
        mHeadDirection = Direction::toUp;
    }
}

void Snake::goRight()
{
    if (!isReverseProhibited() || mHeadDirection != LUTOppositeDirection[static_cast<int>(Direction::toRight)]) {
        mHeadDirection = Direction::toRight;
    }
}

void Snake::goDown()
{
    if (!isReverseProhibited() || mHeadDirection != LUTOppositeDirection[static_cast<int>(Direction::toDown)]) {
        mHeadDirection = Direction::toDown;
    }
}

void Snake::goLeft()
{
    if (!isReverseProhibited() || mHeadDirection != LUTOppositeDirection[static_cast<int>(Direction::toLeft)]) {
        mHeadDirection = Direction::toLeft;
    }
}

void Snake::goToward(Direction direction)
{
    if (!isReverseProhibited() || mHeadDirection != LUTOppositeDirection[static_cast<int>(direction)]) {
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