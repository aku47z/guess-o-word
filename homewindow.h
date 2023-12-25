#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>
#include "ui_homewindow.h"
#include <gui/mainwindow.h>
#include "core/game.h"

class HomeWindow : public QMainWindow

{
    Q_OBJECT

public:
    HomeWindow(QWidget *parent = nullptr);
    ~HomeWindow();

    Ui::HomeWindow *ui; // Add this line

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Game *game;
};

#endif // HOMEWINDOW_H
