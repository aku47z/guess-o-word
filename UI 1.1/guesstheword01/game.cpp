#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    ui->lineEdit->setFocus();
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

void game::on_lineEdit_textChanged(const QString &arg1)
{
    if (arg1.length() >=1)
        ui->lineEdit_2->setFocus();
}




void game::on_lineEdit_2_textChanged(const QString &arg1)
{
    if (arg1.length() >=1)
        ui->lineEdit_3->setFocus();
}


void game::on_lineEdit_3_textChanged(const QString &arg1)
{
    if (arg1.length() >=1)
        ui->lineEdit_4->setFocus();
}


void game::on_lineEdit_4_textChanged(const QString &arg1)
{
    if (arg1.length() >=1)
        ui->lineEdit_5->setFocus();
}

