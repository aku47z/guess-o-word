#include "keyboard_window.h"
#include "input_window.h"
#include <QDebug>

KeyboardWindow::KeyboardWindow(QWidget *parent, Game *game, InputWindow *inputWindow)
    : QWidget(parent), game(game), inputWindow(inputWindow)
{
    gridLayout = new QGridLayout(this);

    for (int i = 0; i < 26; i++)
    {
        keys[i] = new Cell(this);
        keys[i]->setLetter(QChar(keyMap[i]));
        keys[i]->setStyle(40, 50, 8);
        keys[i]->setLetterStyle(13, 10, 30, 30, 15);
        if (i < 10)
        {
            gridLayout->addWidget(keys[i], 0, i * 2, 1, 2);
        }
        else if (i < 19)
        {
            gridLayout->addWidget(keys[i], 1, (i - 10) * 2 + 1, 1, 2);
        }
        else
        {
            gridLayout->addWidget(keys[i], 2, (i - 19) * 2 + 3, 1, 2);
        }
    }
    setLayout(gridLayout);
}

KeyboardWindow::~KeyboardWindow()
{
    for (int i = 0; i < 26; ++i)
    {
        delete keys[i];
    }
}

void KeyboardWindow::setInputWindow(InputWindow *inputWindow)
{
    this->inputWindow = inputWindow;
}

void KeyboardWindow::flushKeyboard()
{
    for(int i = 0; i < statsManager.getDifficultyNumber(); i++)
    {
        if (game->prev_word_color[i] == Cell::Color::darkGray)
        {
            for (int j = 0; j < 26; j++)
            {
                if(keyMap[j].toLower() == game -> prev_word[i])
                {
                    keys[j]->color = Cell::Color::darkGray;
                    keys[j]->changeColor();
                }
            }
        }
    }
}

void KeyboardWindow::resetKeyboard()
{
    for (int i = 0; i < 26; i++)
    {
        keys[i]->show();
    }
}
