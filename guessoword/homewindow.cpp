#include "homewindow.h"
#include "gui/mainwindow.h"

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
    this->hide();

    // Create an instance of MainWindow
    MainWindow *mainWindow = new MainWindow(nullptr, game);

    // Show the MainWindow
    mainWindow->show();
}

