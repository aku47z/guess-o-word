#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "input_window.h"
#include "keyboard_window.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, Game *game = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent* event) override;
    void closeEvent(QCloseEvent *event) override;

private:
    // Ui::MainWindow *ui;
    QLabel *title;
    InputWindow *inputWindow;
    KeyboardWindow *keyboardWindow;
    Game *game;
};

#endif // MAINWINDOW_H
