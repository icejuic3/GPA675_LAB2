#include "SnakeGameEngine.h"
#include "Entity.h"
#include "Snake.h"


SnakeGameEngine::SnakeGameEngine(QSize const& size)
    : mSize{ size }
    , mEntities{}
    , mSpeed{ 500.0 }
    , mTotalElapsedTime{ 0.0 }
{
}

SnakeGameEngine::~SnakeGameEngine()
{
}

void SnakeGameEngine::tic(qreal elapsedTime)
{
    mTotalElapsedTime += elapsedTime;
    for (auto i = mEntities.begin(); i != mEntities.end(); ++i) {
        Snake* snake{ dynamic_cast<Snake*>(*i) };
        if (snake) {  
            snake->ticExecute();
        }

    }

}
void SnakeGameEngine::addEntity(Entity* entity)
{
    mEntities.push_back(entity);
}
QPoint SnakeGameEngine::randomPosition()
{
    int xPos = rand() % 64;
    int yPos = rand() % 64;
    while (nullptr != mBoard.value(xPos,yPos))
    {
        xPos = rand() % 64;
        yPos = rand() % 64;
    }
    QPoint a(xPos, yPos);

    return a;
}
void SnakeGameEngine::clearAllEntity()
{
    for (auto i = mEntities.begin(); i != mEntities.end(); ++i) {
        // *it pointe vers un pointeur d'Entity
        // Pour acc?der aux donn?es de l'objet Entity, on doit d?r?f?rencer le pointeur
        // puis appeler la m?thode ou acc?der aux membres
        (*i)->setDead();
    }

}

void SnakeGameEngine::draw(QPainter& painter)
{
    for (auto i = mEntities.begin(); i != mEntities.end(); ++i) {
        (*i)->draw(painter);

        // *it pointe vers un pointeur d'Entity
        // Pour acc?der aux donn?es de l'objet Entity, on doit d?r?f?rencer le pointeur
        // puis appeler la m?thode ou acc?der aux membres
        
    }
}

