#include "keyboard_window.h"
#include "input_window.h"
#include <QDebug>

KeyboardWindow::KeyboardWindow(QWidget *parent, Game *game, InputWindow *inputWindow)
    : QWidget(parent), game(game), inputWindow(inputWindow)
{
    gridLayout = new QGridLayout(this);

    for (int i = 0; i < 26; i++)
    {
        Cells[i] = new Cell(this);
        Cells[i]->setType(2);
        Cells[i]->setLetter(QString(keyMap[i]));

        int row, column;

        if (i < 10) { row = 0; column = i*2; } 
        else if (i < 19) { row = 1; column = (i-10)*2+1; } 
        else { row = 2; column = (i-19)*2+3; }
        gridLayout->addWidget(Cells[i], row, column, 1, 2);
    }
    setLayout(gridLayout);
}

KeyboardWindow::~KeyboardWindow()
{
    for (int i = 0; i < 26; ++i)
    {
        delete Cells[i];
    }
}

void KeyboardWindow::setInputWindow(InputWindow *inputWindow)
{
    this->inputWindow = inputWindow;
}

void KeyboardWindow::flushKeyboard()
{
    for (int i = 0; i < 26; i++)
    {
        Cells[i]->color = game->gameStatus.letter_color[KeyMap2[i]];
        Cells[i]->changeColor();
    }
}

void KeyboardWindow::resetKeyboard()
{
    for (int i = 0; i < 26; i++)
    {
        Cells[i]->color = Cell::Color::gray;
        Cells[i]->changeColor();
    }
}
