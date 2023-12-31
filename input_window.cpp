#include "input_window.h"
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include "homewindow.h"
#include "keyboard_window.h"

InputWindow::InputWindow(QWidget *parent, Game *game, KeyboardWindow *keyboardWindow)
    : QWidget(parent)
    , game(game)
    , keyboardWindow(keyboardWindow)
//constructor
{
    setFocusPolicy(Qt::StrongFocus);
    setStyleSheet("background-color: #ffffff");

    gridLayout = new QGridLayout(this);
    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < statsManager.getDifficultyNumber(); col++) {
            Cells[row][col] = new Cell(this);
            Cells[row][col]->setStyle(50, 50, 0);
            Cells[row][col]->setLetterStyle(20, 15, 20, 20, 15);
            gridLayout->addWidget(Cells[row][col], row, col);
        }
    }
    game->resetGame();
    setLayout(gridLayout);
}

InputWindow::~InputWindow() //destructor
{
    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < statsManager.getDifficultyNumber(); ++col) {
            delete Cells[row][col];
        }
    }
}

void InputWindow::setKeyboardWindow(KeyboardWindow *keyboardWindow)
{
    this->keyboardWindow = keyboardWindow;
}

void InputWindow::_flushColor(int signal,
                              int row,
                              int col) // signal: 0: flush current row, 1: flush previous row
{
    if (signal == 0)
        Cells[row][col]->color = game->cur_word_color[col];
    else if (signal == 1)
        Cells[row][col]->color = game->prev_word_color[col];
    Cells[row][col]->changeColor();
    return;
}

void InputWindow::_handleKeyInput(int _signal, const QString &key)
{
    if (_signal == 1) // key input
    {
        int signal = game->handleKeyPress(key.toLower());
        if (signal == 1) {
            Cells[game->cur_row][game->cur_col - 1]->setLetter(key.toUpper());
            _flushColor(0, game->cur_row, game->cur_col - 1);
        }
    } else if (_signal == 2) // backspace
    {
        int signal = game->handleBackspace();
        if (signal == 1) {
            Cells[game->cur_row][game->cur_col]->setLetter("");
            _flushColor(0, game->cur_row, game->cur_col);
        }
    } else // enter
    {
        int signal = game->handleEnter(); // 0: do nothing, 1: word not valid, 2: word valid then enter

        if (signal == 2) {
            for (int i = 0; i < statsManager.getDifficultyNumber(); i++) {
                _flushColor(1, game->cur_row - 1, i);
                keyboardWindow->flushKeyboard();
            }
        }

        if (game->is_game_over) {
            QMessageBox msgBox;
            msgBox.setWindowTitle("Game Over");
            QPushButton *replayButton = msgBox.addButton("Play Again", QMessageBox::AcceptRole);
            QPushButton *statsButton = msgBox.addButton("Stats", QMessageBox::AcceptRole);
            QPushButton *exitButton = msgBox.addButton("Exit", QMessageBox::AcceptRole);

            if (game->is_game_won) {
                statsManager.updateWins(); //update win streak
                msgBox.setText("You win!");
            } else {
                statsManager.resetCurrentStreak(); //reset win streak
                msgBox.setText("You lose! The correct word is: " + game->ans_word.toUpper());
            }

            msgBox.exec();

            if (msgBox.clickedButton() == replayButton) {
                statsManager.updateGamesPlayed();
                game->resetGame();
                resetInputWindow();
                keyboardWindow->resetKeyboard();
            } else if (msgBox.clickedButton() == statsButton) {
                HomeWindow temp;
                temp.on_pushButton_2_clicked();

                QMessageBox msgBox2;
                msgBox2.setWindowTitle("Game Over");
                QPushButton *replayButton = msgBox2.addButton("Play Again", QMessageBox::AcceptRole);
                QPushButton *exitButton = msgBox2.addButton("Exit", QMessageBox::AcceptRole);

                msgBox2.exec();
                if (msgBox2.clickedButton() == replayButton)
                {
                    statsManager.updateGamesPlayed();
                    game->resetGame();
                    resetInputWindow();
                    keyboardWindow->resetKeyboard();
                }
                else if (msgBox2.clickedButton() == exitButton)
                {
                    exit(0);
                }

            }

            else if (msgBox.clickedButton() == exitButton) {
                exit(0);
            }
        }
    }
    return;
}

void InputWindow::keyPressEvent(QKeyEvent *event)
{
    QString keyText = event->text();
    if (keyText.length() == 1 && keyText.at(0).isLetter()) {
        _handleKeyInput(1, keyText);
    } else if (event->key() == Qt::Key_Backspace) {
        _handleKeyInput(2, "");
    } else if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        _handleKeyInput(3, "");
    }
    return;
}

void InputWindow::resetInputWindow()
{
    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < statsManager.getDifficultyNumber(); col++) {
            Cells[row][col]->setLetter("");
            Cells[row][col]->color = Cell::Color::gray;
            Cells[row][col]->changeColor();
        }
    }
    return;
}
