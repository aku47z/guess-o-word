#include "game.h"

void Game::_cmpWord()
{
    for (int i = 0; i < statsManager.getDifficultyNumber(); i++)
    {
        if (cur_word[i] == ans_word[i])
        {
            cur_word_color[i] = Cell::Color::green;
        }
        else
        {
            for (int j = 0; j < statsManager.getDifficultyNumber(); j++)
            {
                if (cur_word[i] == ans_word[j])
                {
                    cur_word_color[i] = Cell::Color::yellow;
                    break;
                }
                else
                {
                    cur_word_color[i] = Cell::Color::darkGray;
                }
            }
        }
    }
}

int Game::_isValidWord() // 1: not valid, 2: valid
{
    int left = 0;
    int right = wordlist.size() - 1;

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
    if (is_game_over) return signal;
    if (cur_col == statsManager.getDifficultyNumber()) return signal;

    signal = 1;
    cur_word += keyText;
    cur_word_color[cur_col] = Cell::Color::black;
    cur_col++;
    return signal;
}

int Game::handleBackspace()
{
    int signal = 0; // 0: do nothing, 1: delete letter
    if (is_game_over) return signal;
    if (cur_col == 0) return signal;

    signal = 1;
    cur_word_color[cur_col - 1] = Cell::Color::gray;
    cur_word.remove(cur_col - 1, 1);
    cur_col--;
    return signal;
}

int Game::handleEnter()
{
    // 0: do nothing, 1: word not valid, 2: word valid then enter
    int x = 0;
    if (is_game_over)
        return x;
    if (cur_col < statsManager.getDifficultyNumber())
        return x;

    x = _isValidWord();
    if (x != 2)
        return x;

    has_game_started = true;
    _cmpWord();
    for (int i = 0; i < statsManager.getDifficultyNumber(); i++)
    {
        prev_word_color[i] = cur_word_color[i];
    }
    if (cur_word == ans_word)
    {
        statsManager.updateWins(); //update win stat
        is_game_won = true;
        is_game_over = true;
    }
    if (cur_row == 5)
    {
        statsManager.updateCurrentStreak(); //reset current streak
        is_game_over = true;
    }
    //guessed_words.append(cur_word.toUpper());
    cur_row++;
    cur_col = 0;
    //prev_word = cur_word;
    cur_word = "";
    for (int i = 0; i < statsManager.getDifficultyNumber(); i++)
    {
        cur_word_color[i] = Cell::Color::gray;
    }
    return x;
}
