#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"
#include "rules.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    gameWidget(new game),
    rulesWidget(new rules)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Lenovo/Desktop/guesstheword/GUESS-THE-WORD.jpg");
    ui->picture->setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));
    // Connect the signal from the Rules to the slot in MainWindow
    connect(rulesWidget, &rules::showMainWindowSignal, this, &MainWindow::showMainWindow);
    connect(gameWidget, &game::showMainWindowSignal, this, &MainWindow::showMainWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // Hide the main window and show the "game" widget
    this->hide();
    gameWidget->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    // Hide the main window and show the "rules" widget
    this->hide();
    rulesWidget->show();
}

void MainWindow::showMainWindow()
{
    this->show();
}
