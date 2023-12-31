// homewindow.h
#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>
#include "game.h"
#include "ui_homewindow.h"
#include "rules.h"

class HomeWindow : public QMainWindow

{
    Q_OBJECT

public:
    HomeWindow(QWidget *parent = nullptr);
    ~HomeWindow();

    Ui::HomeWindow *ui; // Add this line

public slots:
    void on_pushButton_2_clicked();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Game *game;
    rules rule;
    bool isEasy = true;
};

#endif // HOMEWINDOW_H
