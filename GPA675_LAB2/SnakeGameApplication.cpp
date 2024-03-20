#include "SnakeGameApplication.h"


#include "HomeState.h"
#include "GamingState.h"
#include "GameOverState.h"
#include "PauseState.h"

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
    painter.setRenderHint(QPainter::Antialiasing);
    painter.scale(16, 16);


    if (mFsm.currentState() != nullptr) {

        auto* homeState = dynamic_cast<HomeState*> (mFsm.currentState());
        auto* gamingState = dynamic_cast<GamingState*> (mFsm.currentState());
        auto* gameOverState = dynamic_cast<GameOverState*> (mFsm.currentState());
        auto* pauseState = dynamic_cast<PauseState*> (mFsm.currentState());


        if (homeState) {
            homeState->draw(painter);
        }
        else if (gamingState) {

            gamingState->draw(painter);
        }
        else if (gameOverState) {

            gameOverState->draw(painter);
        }
        else if (pauseState) {

            pauseState->draw(painter);
        }


        //***A utiliser si on ne fait pas de changement de windows******//
        //auto* state = dynamic_cast<SnakeGameState*> (mFsm.currentState());
        //state->draw(painter);    

    }

    /*************************code a supprimer***********************************************/

    mSnakeGameEngine.draw(painter);
    /****************************************************************************************/
}

void SnakeGameApplication::tic()
{
    double elapsedTime{ mElapsedTimer.restart() / 1.0e3 };

    if (mFsm.currentState() != nullptr) {
        auto* state = dynamic_cast<SnakeGameState*> (mFsm.currentState());

        if (state) {
            state->tic(elapsedTime);
        }
    }

    /*************************code a supprimer***********************************************/
    mSnakeGameEngine.tic(elapsedTime);
    /****************************************************************************************/
    
    repaint();
    mTimer.start();
}