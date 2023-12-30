#include "mainwindow.h"
#include "game.h"
#include <QApplication>
#include <QDebug>
#include "homewindow.h"
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
