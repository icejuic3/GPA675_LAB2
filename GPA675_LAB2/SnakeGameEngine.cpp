#include "SnakeGameEngine.h"




SnakeGameEngine::SnakeGameEngine(QSize const& size)
//SnakeGameEngine::SnakeGameEngine()
    : mEntities{}
    , mSpeed{ 500.0 }
    , mTotalElapsedTime{ 0.0 }
    , mBoard{ Board(64, 64) }
    , mPressedKeys{}
    , mSize{ size }
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
            if (!mPressedKeys.empty()) {   
                snake->updateKeys(mPressedKeys);    //met a jour le changement de direction du serpent
                mPressedKeys.clear();   
            }
        } 
        (*i)->ticPrepare(elapsedTime);
        (*i)->ticExecute();
    }



    for (auto i = mEntities.begin(); i != mEntities.end();) {
        if (!(*i)->isAlive()) {
            delete* i;
            i = mEntities.erase(i);
        }
        else {
            ++i;
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

void SnakeGameEngine::randomPellet()
{
    Pellet* a = new Pellet(mBoard);
    a->setPosition(randomPosition());    
    addEntity(a);

}

void SnakeGameEngine::arene()
{
 

    // Création des obstacles sur les bords verticaux
    for (size_t i = 0; i < mBoard.getHeight(); ++i) {
        Obstacle* o1 = new Obstacle(mBoard);
        Obstacle* o2 = new Obstacle(mBoard);
        // Bord de gauche
        QPoint pos1(0, i);
        // Bord de droite
        QPoint pos2(mBoard.getWidth() - 1, i);

        o1->setPosition(pos1);
        o2->setPosition(pos2);
        addEntity(o1);
        addEntity(o2);
    }

    // Création des obstacles sur les bords horizontaux
    for (size_t i = 0; i < mBoard.getWidth(); ++i) {
        Obstacle* o1 = new Obstacle(mBoard);
        Obstacle* o2 = new Obstacle(mBoard);
        // Bord du haut
        QPoint pos1(i, 0);
        // Bord du bas
        QPoint pos2(i, mBoard.getHeight() - 1);

        o1->setPosition(pos1);
        o2->setPosition(pos2);
        addEntity(o1);
        addEntity(o2);
    }
    // Rajout des coins si necessaire

}

void SnakeGameEngine::addSnake()
{
    addEntity(new Snake(mBoard));
}

void SnakeGameEngine::startGameEngine()
{
    clearAllEntity();
    addEntity(new Snake(mBoard));
    arene();
    randomPellet();

    int a = 0;
    while (a < 64 )
    {
        randomPellet();
        a++;
    }
    
}

void SnakeGameEngine::snakeDirection(const PressedKeys& pressedKeys)
{
    mPressedKeys = pressedKeys;
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