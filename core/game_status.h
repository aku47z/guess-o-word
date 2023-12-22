#ifndef GAME_STATUS_H
#define GAME_STATUS_H

#include "load_data.h"
#include "../gui/cell.h"
#include <QStringList>

#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QRandomGenerator>
#include <QDebug>

struct GameStatus
{

    QString ans_word;
    int cur_row;
    int cur_col;
    QString cur_word = "";
    Cell::Color cur_word_color[5];
    Cell::Color prev_word_color[5];
    QStringList guessed_words;
    Cell::Color letter_color[26];
    int letter_occurrence[26]; // min occurrence of each letter (yellow & green)
    bool has_fixed[26]; // when a letter is darkGray, its occurrence is entirely fixed
    int impossible_position[26]; // 0~31(2^5-1), in each bit, 1 means impossible
    QChar green_letter[5]; // green letters
    bool has_game_started;
    bool is_game_over;
    bool is_game_won;

    QVector<QString> wordlist;

    GameStatus() 
    {
        resetGameStatus();
    }
    ~GameStatus() {}

    void resetGameStatus()
    {
        // Open text file
        QFile file(":/valid_word.txt");

        // Check if the file opened successfully
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);

            // Copy words from the file to a QVector
            QString tempword;
            while (!in.atEnd())
            {
                tempword = in.readLine();
                wordlist.push_back(tempword);
            }

            // Close the file
            file.close();

            // Select a random word
            QRandomGenerator randomGenerator = QRandomGenerator::securelySeeded();
            int randomIndex = randomGenerator.bounded(wordlist.size());
            ans_word = wordlist[randomIndex];
        }
        else
        {
            qDebug() << "Error opening file! Terminating program" << file.errorString();
            exit(EXIT_FAILURE);
        }


        cur_row = 0;
        cur_col = 0;
        cur_word = "";
        for (int i = 0; i < 5; i++) cur_word_color[i] = Cell::Color::gray;
        for (int i = 0; i < 5; i++) prev_word_color[i] = Cell::Color::gray;
        guessed_words = QStringList();
        for (int i = 0; i < 26; i++) letter_color[i] = Cell::Color::gray;
        for (int i = 0; i < 26; i++) letter_occurrence[i] = 0;
        for (int i = 0; i < 26; i++) has_fixed[i] = false;
        for (int i = 0; i < 26; i++) impossible_position[i] = 0;
        for (int i = 0; i < 5; i++) green_letter[i] = ' ';
        has_game_started = false;
        is_game_over = false;
        is_game_won = false;
    }
};

#endif // GAME_STATUS_H
