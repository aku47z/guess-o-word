#include "game.h"
#include "statisticsmanager.h"

extern StatisticsManager statsManager; //to update win statistic


void Game::_cmpWord()
{
    QString cur_word = gameStatus.cur_word;
    QString ans_word = gameStatus.ans_word;
  
    for (short i = 0; i < 5; i++)
    {
        if (cur_word[i] == ans_word[i])
        {
            gameStatus.cur_word_color[i] = Cell::Color::green;
        }
        else
        {
            for (short j = 0; j < 5; j++)
            {
                if (cur_word[i] == ans_word[j])
                {
                    gameStatus.cur_word_color[i] = Cell::Color::yellow;
                    break;
                }
                else
                {
                    gameStatus.cur_word_color[i] = Cell::Color::darkGray;
                }
            }
        }
    }
}

int Game::_isValidWord() // 1: not valid, 2: valid
{
    QVector<QString> wordlist = gameStatus.wordlist;

    int left = 0;
    int right = wordlist.size() - 1;

    QString cur_word = gameStatus.cur_word;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (wordlist[mid] == cur_word)
        {
            return 2;
        }

        if (wordlist[mid] < cur_word)
        {
            left = mid + 1;
        }

        if (wordlist[mid] > cur_word)
        {
            right = mid - 1;
        }
    }
    return 1;
}

int Game::handleKeyPress(const QString &keyText)
{
    int signal = 0; // 0: do nothing, 1: add letter
    if (gameStatus.is_game_over) return signal;
    if (gameStatus.cur_col == 5) return signal;

    signal = 1;
    gameStatus.cur_word += keyText;
    gameStatus.cur_word_color[gameStatus.cur_col] = Cell::Color::black;
    gameStatus.cur_col++;
    return signal;
}

int Game::handleBackspace()
{
    int signal = 0; // 0: do nothing, 1: delete letter
    if (gameStatus.is_game_over) return signal;
    if (gameStatus.cur_col == 0) return signal;

    signal = 1;
    gameStatus.cur_word_color[gameStatus.cur_col - 1] = Cell::Color::gray;
    gameStatus.cur_word.remove(gameStatus.cur_col - 1, 1);
    gameStatus.cur_col--;
    return signal;
}

int Game::handleEnter()
{
    // 0: do nothing, 1: word not valid, 2: word valid then enter
    int x = 0;
    if (gameStatus.is_game_over) return x;
    if (gameStatus.cur_col < 5) return x;

    x = _isValidWord();
    if (x != 2)
        return x;

    gameStatus.has_game_started = true;
    _cmpWord();
    for (int i = 0; i < 5; i++) gameStatus.prev_word_color[i] = gameStatus.cur_word_color[i];
    if (gameStatus.cur_word == gameStatus.ans_word) 
    {
        statsManager.updateWins(); //update win stat
        gameStatus.is_game_won = true;
        gameStatus.is_game_over = true;
    }
    if (gameStatus.cur_row == 5)
    {
        statsManager.updateCurrentStreak(); //reset current streak
        gameStatus.is_game_over = true;
    }
    gameStatus.guessed_words.append(gameStatus.cur_word.toUpper());
    gameStatus.cur_row++;
    gameStatus.cur_col = 0;
    gameStatus.cur_word = "";
    for (int i = 0; i < 5; i++) gameStatus.cur_word_color[i] = Cell::Color::gray;
    return x;
}

void Game::resetGame()
{
    gameStatus.resetGameStatus();
}
