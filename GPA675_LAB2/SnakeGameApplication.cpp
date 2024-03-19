#include "SnakeGameApplication.h"
#include <QKeyEvent>
#include <QDebug>
#include <QPainter>
#include "Pellet.h"
#include "Snake.h"


SnakeGameApplication::SnakeGameApplication()
    : QWidget(nullptr)
    , mWindowSize(1024, 1024)
    , mTimer()
    , mElapsedTimer()
    , mSnakeGameEngine(mWindowSize)
    , mBoard{ Board(64, 64) }
{
    setWindowTitle("Snake Equipe D");
    setFixedSize(mWindowSize);
    setFocusPolicy(Qt::StrongFocus);
    mTimer.setSingleShot(true);
    connect(&mTimer, &QTimer::timeout, this, &SnakeGameApplication::tic);
    mTimer.start();

    Pellet* a = new Pellet(mBoard);
    a->setPosition(QPoint(32, 20));
    mSnakeGameEngine.addEntity(new Snake(mBoard));  //rajoute le serpent au board
    mSnakeGameEngine.addEntity(a);
    
    //mSnakeGameEngine.startGameEngine();
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

    mSnakeGameEngine.draw(painter);
}

void SnakeGameApplication::tic()
{
    double elapsedTime{ mElapsedTimer.restart() / 1.0e3 };
    mSnakeGameEngine.tic(elapsedTime);
    repaint();

    mTimer.start();
}