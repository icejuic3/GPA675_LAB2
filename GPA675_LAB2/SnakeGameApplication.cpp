#include "SnakeGameApplication.h"

#include <QKeyEvent>
#include <QDebug>

#include <QPainter>

SnakeGameApplication::SnakeGameApplication()
    : QWidget(nullptr)
    , mWindowSize(1024, 1024)
    , mTimer()
    , mElapsedTimer()
    , mSnakeGameEngine(mWindowSize)
{
    setWindowTitle("Snake++");
    setFixedSize(mWindowSize);
    setFocusPolicy(Qt::StrongFocus);
    mTimer.setSingleShot(true);
    connect(&mTimer, &QTimer::timeout, this, &SnakeGameApplication::tic);
    mTimer.start();
}

SnakeGameApplication::~SnakeGameApplication()
{
}

//void SnakeGameApplication::keyPressEvent(QKeyEvent* event)
//{
//    if (!event->isAutoRepeat()) {
//        mPressedKeys.push_back(static_cast<Qt::Key>(event->key()));
//    }
//}
//
//void SnakeGameApplication::keyReleaseEvent(QKeyEvent* event)
//{
//    if (!event->isAutoRepeat()) {
//        auto it = std::find(mPressedKeys.begin(), mPressedKeys.end(), event->key());
//        if (it != mPressedKeys.end()) {
//            mPressedKeys.erase(it);
//        }
//    }
//}

void SnakeGameApplication::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    mSnakeGameEngine.draw(painter);
}

void SnakeGameApplication::tic(qreal elapsedTime)
{
    double elapsedTime{ mElapsedTimer.restart() / 1.0e3 };
    mSnakeGameEngine.tic(elapsedTime);
    repaint();

    mTimer.start();
}