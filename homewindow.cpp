#include "homewindow.h"
#include "gui/mainwindow.h"
#include "statistics.h"
#include "statisticsmanager.h"
#include "rules.h"

extern StatisticsManager statsManager;


HomeWindow::HomeWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::HomeWindow),
    game(new Game())
{
    ui->setupUi(this);

}

HomeWindow::~HomeWindow()
{
    delete ui;
    delete game;
}

void HomeWindow::on_pushButton_clicked()
{
    //this->hide();

    //Update number of games played
    statsManager.updateGamesPlayed();

    // Create an instance of MainWindow
    MainWindow *mainWindow = new MainWindow(nullptr, game);

    // Show the MainWindow
    mainWindow->show();
}

void HomeWindow::on_pushButton_2_clicked()
{
    leaderboard leaderboard;
    int numberOfGames = statsManager.getGamesPlayed(); //later change to use statisticsmanager to use values
    int winCount=statsManager.getWins();
    int currentStreak=statsManager.getCurrentStreak();
    int maxStreak=statsManager.getMaxStreak();
    leaderboard.updateGamesPlayedLabel(numberOfGames);
    leaderboard.updateWinCountLabel(winCount);
    leaderboard.updateCurrentStreakLabel(currentStreak);
    leaderboard.updateMaxStreakLabel(maxStreak);
    leaderboard.exec();
}

void HomeWindow::on_pushButton_3_clicked()
{
    rules *rw= new rules(this);
    rw-> show();
}


void HomeWindow::on_pushButton_4_clicked()
{
    if (isEasy) {
        // Change icon and functionality for difficult mode
        ui->pushButton_4->setIcon(QIcon(":/skull-solid.png"));
        statsManager.updateGameMode();
    } else {
        // Change icon and functionality for easy mode
        ui->pushButton_4->setIcon(QIcon(":/face-smile-regular.png"));
        statsManager.updateGameMode();
    }
    isEasy = !isEasy; // Toggle the state after the changes
}
