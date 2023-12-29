#include "input_window.h"
#include "keyboard_window.h"
#include "homewindow.h"
#include <QDebug>
#include <QMessageBox>

InputWindow::InputWindow(QWidget *parent, Game *game, KeyboardWindow *keyboardWindow)
    : QWidget(parent), game(game), keyboardWindow(keyboardWindow)
//constructor
{
    setFocusPolicy(Qt::StrongFocus);
    // setGeometry(350, 100, 500, 600);
    setStyleSheet("background-color: #ffffff");

    gridLayout = new QGridLayout(this);
    for (int row = 0; row < 6; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            Cells[row][col] = new Cell(this);
            Cells[row][col] -> setStyle(50, 50, 0);
            Cells[row][col] -> setLetterStyle(20, 15, 20, 20, 15);
            gridLayout->addWidget(Cells[row][col], row, col);
        }
    }
    setLayout(gridLayout);
    game->resetGame();
    resetInputWindow();
}

InputWindow::~InputWindow() //destructor
{
    for (int row = 0; row < 6; ++row)
    {
        for (int col = 0; col < 5; ++col)
        {
            delete Cells[row][col];
        }
    }
}

void InputWindow::setKeyboardWindow(KeyboardWindow *keyboardWindow)
{
    this->keyboardWindow = keyboardWindow;
}


void InputWindow::_flushColor(int signal, int row, int col) // signal: 0: flush current row, 1: flush previous row
{
    if (signal == 0)
        Cells[row][col]->color = game->cur_word_color[col];
    else if (signal == 1)
        Cells[row][col]->color = game->prev_word_color[col];
    Cells[row][col]->changeColor();
    return;
}

void InputWindow::_handleKeyInput(int _signal, const QString & key)
{
    if (_signal == 1) // key input
    {
        int signal = game->handleKeyPress(key.toLower());
        if (signal == 1)
        {
            Cells[game->cur_row][game->cur_col - 1]->setLetter(key.toUpper());
            _flushColor(0, game->cur_row, game->cur_col - 1);
        }
    }
    else if (_signal == 2) // backspace
    {
        int signal = game->handleBackspace();
        if (signal == 1)
        {
            Cells[game->cur_row][game->cur_col]->setLetter("");
            _flushColor(0, game->cur_row, game->cur_col);
        }
    }
    else // enter
    {
        int signal = game->handleEnter(); // 0: do nothing, 1: word not valid, 2: word valid then enter

        if (signal == 2)
        {
            for (int i = 0; i < 5; i++)
            {
                _flushColor(1, game->cur_row - 1, i);
                keyboardWindow->flushKeyboard();
            }
        }

        if (game->is_game_over)
        {
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setWindowTitle("Game Over");

            if (game->is_game_won)
            {
                msgBox.setText("You win!");
                msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Retry);
            }
            else
            {
                msgBox.setText("You lose! The correct word is: " + game->ans_word.toUpper());
                msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Retry);
            }

            int result = msgBox.exec();

            if (result == QMessageBox::Retry)
            {
                // User clicked "Play Again"
                game->resetGame();
                resetInputWindow();
            }
            else if (result == QMessageBox::Ok)
            {
                // User clicked "Exit" or closed the dialog
                // Handle exit logic or close the application
                this->close();
                HomeWindow home;
                home.show();
                game->resetGame();
                resetInputWindow();
            }
            else
            {

                // no key
            }
            game->resetGame();
            resetInputWindow();
        }

    }
    return;
}

void InputWindow::keyPressEvent(QKeyEvent *event)
{
    QString keyText = event->text();
    if (keyText.length() == 1 && keyText.at(0).isLetter()) 
    {
        _handleKeyInput(1, keyText);
    }
    else if (event->key() == Qt::Key_Backspace) 
    {
        _handleKeyInput(2, "");
    }
    else if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) 
    {
        _handleKeyInput(3, "");
    }
    return;
}


void InputWindow::resetInputWindow()
{
    for (int row = 0; row < 6; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            Cells[row][col]->setLetter("");
            Cells[row][col]->color = Cell::Color::gray;
            Cells[row][col]->changeColor();
        }
    }
    return;
}
