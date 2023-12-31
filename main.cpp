#include <QApplication>
#include <QDebug>
#include "game.h"
#include "homewindow.h"
#include "mainwindow.h"
#include "statisticsmanager.h"

StatisticsManager statsManager;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game *game = new Game();

    statsManager.passInstance(*game);
    MainWindow mainWindow(nullptr, game);

    HomeWindow homeWindow;
    homeWindow.show();

    a.exec();

    return 0;
}
