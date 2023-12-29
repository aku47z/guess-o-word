#include "statistics.h"
#include "ui_statistics.h"

leaderboard::leaderboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::leaderboard)
{
    ui->setupUi(this);
}

leaderboard::~leaderboard()
{
    delete ui;
}

void leaderboard::on_pushButton_clicked() //close button
{
    this->close();
}

void leaderboard::updateGamesPlayedLabel(int gamesPlayed)
{
    ui->gamesPlayedLabel->setText(QString::number(gamesPlayed));
}

void leaderboard::updateWinCountLabel(int winCount)
{
    ui->winCountLabel->setText(QString::number(winCount));
}

void leaderboard::updateCurrentStreakLabel(int currentStreak)
{
    ui->currentStreakLabel->setText(QString::number(currentStreak));
}

void leaderboard::updateMaxStreakLabel(int maxStreak)
{
    ui->maxStreakLabel->setText(QString::number(maxStreak));
}
