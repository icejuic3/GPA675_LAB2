#include "SnakeGameApplication.h"
#include "HomeState.h"
#include "GamingState.h"
#include "GameOverState.h"
#include "PauseState.h"

SnakeGameApplication::SnakeGameApplication()
    : QWidget(nullptr)
    , mFsm{}
    , mPressedKeys{}
    , mWindowSize(1024, 1024)
    , mTimer()
    , mElapsedTimer()
{
    setWindowTitle("Snake Equipe D");
    setFixedSize(mWindowSize);
    setFocusPolicy(Qt::StrongFocus);
    mTimer.setSingleShot(true);
    connect(&mTimer, &QTimer::timeout, this, &SnakeGameApplication::tic);
    mTimer.start();
}

void SnakeGameApplication::keyPressEvent(QKeyEvent* event)
{
    if (!event->isAutoRepeat()) {
        mPressedKeys.push_back(static_cast<Qt::Key>(event->key()));


        if (mFsm.currentState() != nullptr) {

            auto* state = dynamic_cast<SnakeGameState*> (mFsm.currentState());
            state->updateKeys(mPressedKeys);
        }
    }
}

void SnakeGameApplication::keyReleaseEvent(QKeyEvent* event)
{
    if (!event->isAutoRepeat()) {
        auto it = std::find(mPressedKeys.begin(), mPressedKeys.end(), event->key());
        if (it != mPressedKeys.end()) {
            mPressedKeys.erase(it);


            if (mFsm.currentState() != nullptr) {

                auto* state = dynamic_cast<SnakeGameState*> (mFsm.currentState());
                state->updateKeys(mPressedKeys);
            }
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
}

void SnakeGameApplication::tic()
{
    double elapsedTime{ mElapsedTimer.restart() / 1.0e3 };

    mFsm.tic(elapsedTime);
   
    repaint();
    mTimer.start();
}