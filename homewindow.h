// homewindow.h
#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>
#include "core/game.h"
#include "ui_homewindow.h"
#include <gui/mainwindow.h>

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

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Game *game;
    bool isEasy = true;
};

#endif // HOMEWINDOW_H
