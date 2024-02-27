#include "SnakeGameEngine.h"
#include "Entity.h"

SnakeGameEngine::SnakeGameEngine(Entity& entity) : 
    mEntity.push_front(&entity);
{
    
}

SnakeGameEngine::~SnakeGameEngine()
{
}

void SnakeGameEngine::tic(qreal elapsedTime)
{
    //mTotalElapsedTime += elapsedTime;
    //mPosition += getKeyboardDirection(keys) * mSpeed * elapsedTime;
    //constrainPosition();
}
void SnakeGameEngine::addEntity(Entity* entity)
{

}
void SnakeGameEngine::clearAllEntity()
{
}

void SnakeGameEngine::draw(QPainter& painter)
{
    
}


