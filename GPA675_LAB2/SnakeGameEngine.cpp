#include "SnakeGameEngine.h"
#include "SnakeOrigin.h"
#include "Snakify.h"

#include "control.h"
#include "SnakeKeyboardAbsoluteController.h"
#include "SnakeKeyboardRelativeController.h"
#include "State.h"

SnakeGameEngine::SnakeGameEngine()
    : mEntities{}
    , mSpeed{ 500.0 }
    , mTotalElapsedTime{ 0.0 }
    , mBoard{ Board(64, 64) }
    , mPressedKeys{}
    , mGameMode()
    , mDeadSnake{false}
{
}

SnakeGameEngine::~SnakeGameEngine()
{
}

void SnakeGameEngine::tic(qreal elapsedTime)
{
    mTotalElapsedTime += elapsedTime;


    //boucle pour le premier mode de jeu
    if ( mGameMode == 1) {

        for (auto i = mEntities.begin(); i != mEntities.end(); ++i) {

            Snake* snake{ dynamic_cast<Snake*>(*i) };

            if (snake) {
                if (!mPressedKeys.empty()) {
                    snake->updateKeys(mPressedKeys);    //met a jour le changement de direction du serpent
                    //mPressedKeys.clear();
                }
            }
            (*i)->ticPrepare(elapsedTime);
            (*i)->ticExecute();
        }
    }

    //boucle pour le deuxieme mode de jeu            *********devons changer cette boucle pour que les snakes ai chacun leur propre controller
    else if(mGameMode == 2) {

        for (auto i = mEntities.begin(); i != mEntities.end(); ++i) {

            Snake* snake{ dynamic_cast<Snake*>(*i) };

            if (snake) {
                if (!mPressedKeys.empty()) {
                    snake->updateKeys(mPressedKeys);    //met a jour le changement de direction du serpent
                    //mPressedKeys.clear();
                }
            }
            (*i)->ticPrepare(elapsedTime);
            (*i)->ticExecute();
        }
    }

    //boucle pour le troisieme mode de jeu
    else if (mGameMode == 3) {

		for (auto i = mEntities.begin(); i != mEntities.end(); ++i) {

			Snake* snake{ dynamic_cast<Snake*>(*i) };

			if (snake) {
				if (!mPressedKeys.empty()) {
					snake->updateKeys(mPressedKeys);    //met a jour le changement de direction du serpent
					//mPressedKeys.clear();
				}
			}
			(*i)->ticPrepare(elapsedTime);
			(*i)->ticExecute();
		}
    }

    //Verification de destruction des entitees
    for (auto i = mEntities.begin(); i != mEntities.end();) {

        if (!(*i)->isAlive()) {

            if ((*i) == dynamic_cast<Pellet*> (*i)) {   //verifie si l'entite morte est une Statique

                if (mGameMode == 1) {

                    randomGrowingPellet();  //rajoute une pomme sur le jeu
                }
                else if (mGameMode == 2) {

                    randomPellet();         //Rajoute pastille aleatoire
                }
                else if (mGameMode == 3) {

					randomGrowingPellet();  //rajoute une pomme sur le jeu
                    
                    randomObstacle(); 
                    
                    if (nbObstacle >= 3 && nbObstacle <= 3) {
                        randomObstaclePellet(); //ajoute une pellet de reduction d'obstacle
                    }
                   
                }

            }
            if ((*i) == dynamic_cast<Snake*> (*i)) {
                mDeadSnake = true;
                ++i;
            }
            else {
                delete* i;
                i = mEntities.erase(i);
                if (mGameMode == 3)
                {
                    deleteObstacle();
                }
            }
            //Ajouter un etat pour l'ajout d'entity
            

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

void SnakeGameEngine::setGameMode(const int gameMode)
{
    mGameMode = gameMode;
}

QPoint SnakeGameEngine::randomPosition()
{
    int xPos = rand() % 64;
    int yPos = rand() % 42;

    while (nullptr != mBoard.value(xPos,yPos))
    {
        xPos = rand() % 64;
        yPos = rand() % 42;
    }
    QPoint a(xPos, yPos);

    return a;
}

void SnakeGameEngine::randomPellet()
{
    int pellet = rand() % 100;
    if (pellet == 1)
    {
        randomGrowingPellet();
    }
    else
    {
        randomAccPellet();
    }
}

void SnakeGameEngine::randomGrowingPellet()
{
    GrowingPellet* a = new GrowingPellet(mBoard);
    a->setPosition(randomPosition());
    addEntity(a);
}

void SnakeGameEngine::randomAccPellet()
{
    AcceleratingPellet* a = new AcceleratingPellet(mBoard);
    a->setPosition(randomPosition());
    addEntity(a);
}

void SnakeGameEngine::randomObstaclePellet()
{
	AddObstaclePellet* a = new AddObstaclePellet(mBoard);
	a->setPosition(randomPosition());
	addEntity(a);
}

void SnakeGameEngine::randomObstacle()
{
    Obstacle* a = new Obstacle(mBoard);
    a->setPosition(randomPosition());
    addEntity(a);
    nbObstacle++;
}

void SnakeGameEngine::deleteObstacle()
{
    //clearAllEntity();
    //nbObstacle = 0;
}


void SnakeGameEngine::arene()
{
    //  Les cotes gauche et droite
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

    // Les cotes haut et bas
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

void SnakeGameEngine::addSnake(int nbSnake)
{   //*********************IMPORTANT
    //**********changement de logique du controller on doit faire des new absolute ou relatif avec les touches necessaire et ensuite les assigner aux snakes correspondant
    //**********iL va falloir aussi changer les SnakeKeyboardAbsoluteController.h et SnakeKeyboardRelativeController.h pour la nouvelle logique 
    // ainsi que le constructeur du snake pour ne pas creer un new controller a cet endroit la

    if (nbSnake == 1)
    {
        QPoint point1;
        point1.setX(mBoard.getWidth() / 2);
        point1.setY(mBoard.getHeight() / 2);
        Snake* snake1 = new Snake(mBoard, point1);
        addEntity(snake1);

        Controller* mc1 = new SnakeKeyboardAbsoluteController(*snake1, Qt::Key_Up, Qt::Key_Down, Qt::Key_Left, Qt::Key_Right);

        snake1->setController(*(mc1));
    }
    if (nbSnake == 2)
    {
        //Serpent 1
        QPoint point1;
        point1.setX(mBoard.getWidth() / 3);
        point1.setY(mBoard.getHeight() / 2);
        Snake* snake1 = new Snake(mBoard,point1);
        snake1->setColors(QColor(240, 0, 0), QColor(120,0, 0));

        //Serpent 2
        QPoint point2;
        point2.setX((mBoard.getWidth() / 3) * 2);
        point2.setY(mBoard.getHeight() / 2);
        Snake* snake2 = new Snake(mBoard,point2);    
        snake2->setColors(QColor(0, 240, 0), QColor(0, 120, 0));

        addEntity(snake1);
        addEntity(snake2);

        Controller* mc1 = new SnakeKeyboardAbsoluteController(*snake1, Qt::Key_W, Qt::Key_S, Qt::Key_A, Qt::Key_D);
        Controller* mc2 = new SnakeKeyboardAbsoluteController(*snake2, Qt::Key_I, Qt::Key_K, Qt::Key_J, Qt::Key_L);

        snake1->setController(*(mc1));
        snake2->setController(*(mc2));
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

bool SnakeGameEngine::deadSnake() const
{
    return mDeadSnake;
}