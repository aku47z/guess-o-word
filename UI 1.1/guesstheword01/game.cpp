#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
}

game::~game()
{
    delete ui;
}

void game::on_pushButton_clicked()
{
    // Emit the signal to show the main window
    emit showMainWindowSignal();
        // Close the rules window
    this->close();
}

