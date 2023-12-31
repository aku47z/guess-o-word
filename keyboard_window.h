#ifndef KEYBOARD_WINDOW_H
#define KEYBOARD_WINDOW_H

#include <QGridLayout>
#include <QLabel>
#include <QWidget>
#include "cell.h"
#include "game.h"

class InputWindow;

class KeyboardWindow : public QWidget
{
    Q_OBJECT

public:
    KeyboardWindow(QWidget *parent = nullptr,
                   Game *game = nullptr,
                   InputWindow *inputWindow = nullptr);
    ~KeyboardWindow();

    void setInputWindow(InputWindow *inputWindow);
    void flushKeyboard();
    void resetKeyboard();

private:
    QGridLayout *gridLayout;
    Cell *keys[26];
    QChar keyMap[26] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D',
                        'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};

    Game *game;
    InputWindow *inputWindow;
};

#endif // KEYBOARD_WINDOW_H
