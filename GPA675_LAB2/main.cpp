#include "SnakeGameApplication.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication application(argc, argv);
    SnakeGameApplication window;
    window.show();

    return application.exec();
}