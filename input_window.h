#ifndef INPUT_WINDOW_H
#define INPUT_WINDOW_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QGridLayout>
#include "cell.h"
#include "game.h"

class KeyboardWindow;

class InputWindow : public QWidget
{
    Q_OBJECT

public:
    InputWindow(QWidget *parent = nullptr, Game *game = nullptr, KeyboardWindow *keyboardWindow = nullptr);
    ~InputWindow();

    void setKeyboardWindow(KeyboardWindow *keyboardWindow);

    void keyPressEvent(QKeyEvent *event);

    void resetInputWindow();

private:
    void _handleKeyInput(int _signal, const QString & key);
    void _flushColor(int signal, int row, int col);

    QGridLayout *gridLayout;
    Cell *Cells[6][6];
    Game *game;
    KeyboardWindow *keyboardWindow;
};

#endif // INPUT_WINDOW_H
