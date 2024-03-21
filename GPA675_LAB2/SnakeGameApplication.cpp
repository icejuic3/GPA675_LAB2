#include "SnakeGameApplication.h"


#include "HomeState.h"
#include "GamingState.h"
#include "GameOverState.h"
#include "PauseState.h"

SnakeGameApplication::SnakeGameApplication()
    : QWidget(nullptr)
    , mFsm{}
    , mWindowSize(1024, 1024)
    , mTimer()
    , mElapsedTimer()
    , mSnakeScenario(&mSnakeGameEngine)
    , mFsm{}
    //, mSnakeGameEngine(mWindowSize)
    //, mBoard{ Board(64, 64) }
{
    setWindowTitle("Snake Equipe D");
    setFixedSize(mWindowSize);
    setFocusPolicy(Qt::StrongFocus);
    mTimer.setSingleShot(true);
    connect(&mTimer, &QTimer::timeout, this, &SnakeGameApplication::tic);
    mTimer.start();


    mSnakeScenario.snakeOrigin();
   // mSnakeGameEngine.startGameEngine();
}

void SnakeGameApplication::keyPressEvent(QKeyEvent* event)
{
    if (!event->isAutoRepeat()) {
        mPressedKeys.push_back(static_cast<Qt::Key>(event->key()));

        //mSnakeGameEngine.snakeDirection(mPressedKeys);
    }
}

void SnakeGameApplication::keyReleaseEvent(QKeyEvent* event)
{
    if (!event->isAutoRepeat()) {
        auto it = std::find(mPressedKeys.begin(), mPressedKeys.end(), event->key());
        if (it != mPressedKeys.end()) {
            mPressedKeys.erase(it);
        }
    }
}

void SnakeGameApplication::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.scale(16, 16);


    if (mFsm.currentState() != nullptr) {

        auto* state = dynamic_cast<SnakeGameState*> (mFsm.currentState());
        state->draw(painter);    
    }

    /*************************code a supprimer***********************************************/

    //mSnakeGameEngine.draw(painter);
    /****************************************************************************************/
}

void SnakeGameApplication::tic()
{
    double elapsedTime{ mElapsedTimer.restart() / 1.0e3 };

    mFsm.tic(elapsedTime);  
    
    /*************************code a supprimer***********************************************/
    //mSnakeGameEngine.tic(elapsedTime);
    /****************************************************************************************/
    
    repaint();
    mTimer.start();
}