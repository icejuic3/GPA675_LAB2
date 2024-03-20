#include "SnakeGameApplication.h"


#include "HomeState.h"
#include "GamingState.h"
#include "GameOverState.h"





SnakeGameApplication::SnakeGameApplication()
    : QWidget(nullptr)
    , mWindowSize(1024, 1024)
    , mTimer()
    , mElapsedTimer()
    , mSnakeGameEngine(mWindowSize)

    , mSnakeScenario(&mSnakeGameEngine)
    //, mBoard{ Board(64, 64) }

    , mFsm{}

{
    setWindowTitle("Snake Equipe D");
    setFixedSize(mWindowSize);
    setFocusPolicy(Qt::StrongFocus);
    mTimer.setSingleShot(true);
    connect(&mTimer, &QTimer::timeout, this, &SnakeGameApplication::tic);
    mTimer.start();

    //mSnakeScenario.snakeBlockade();
    mSnakeScenario.snakeOrigin();
   // mSnakeGameEngine.startGameEngine();
}

void SnakeGameApplication::keyPressEvent(QKeyEvent* event)
{
    if (!event->isAutoRepeat()) {
        mPressedKeys.push_back(static_cast<Qt::Key>(event->key()));

        mSnakeGameEngine.snakeDirection(mPressedKeys);
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
    painter.scale(16, 16);
    painter.setRenderHint(QPainter::Antialiasing);


    if (mFsm.currentState() != nullptr) {

        auto* gamingState = dynamic_cast<Gamin>

        //mFsm.currentState()->draw(painter); // Appel de la méthode draw de l'état courant
    }


    mFsm.currentState().













    /*************************code a supprimer***********************************************/

    mSnakeGameEngine.draw(painter);
    /****************************************************************************************/
}

void SnakeGameApplication::tic()
{
    double elapsedTime{ mElapsedTimer.restart() / 1.0e3 };
    mSnakeGameEngine.tic(elapsedTime);
    repaint();

    mTimer.start();
}