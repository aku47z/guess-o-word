#ifndef GAME_H
#define GAME_H

#include <QDebug>
#include <QFile>
#include <QRandomGenerator>
#include <QTextStream>
#include <QVector>
#include "cell.h"
#include "statisticsmanager.h"

extern StatisticsManager statsManager; //to update win statistic

class Game
{
public:
    Game() {}
    ~Game() {}

    int handleKeyPress(const QString &keyText);
    int handleEnter(); // 0: do nothing, 1: word not valid, 2: word valid then enter
    int handleBackspace();

    QString ans_word;
    int cur_row;
    int cur_col;
    QString cur_word;
    QString prev_word;
    Cell::Color cur_word_color[6];
    Cell::Color prev_word_color[6];
    bool has_game_started;
    bool is_game_over;
    bool is_game_won;

    QVector<QString> wordlist;
    QVector<QString> answerlist;
    QFile file1;
    QFile file2;

    void resetGame()
    {
        // Open text file
        if (statsManager.getDifficultyNumber() == 5) {
            file1.setFileName(":/valid_words.txt");
        } else {
            file1.setFileName(":/hard_words.txt");
        }

        // Check if the file opened successfully
        if (file1.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file1);

            // Copy words from the file to a QVector
            QString tempword;
            while (!in.atEnd()) {
                tempword = in.readLine();
                wordlist.push_back(tempword);
            }

            // Close the file
            file1.close();
        } else {
            qDebug() << "Error opening file! Terminating program" << file1.errorString();
            exit(EXIT_FAILURE);
        }

        if (statsManager.getDifficultyNumber() == 5) {
            file2.setFileName(":/valid_answers.txt");
        } else {
            file2.setFileName(":/hard_words.txt");
        }

        // Check if the file opened successfully
        if (file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file2);

            // Copy words from the file to a QVector
            QString tempword;
            while (!in.atEnd()) {
                tempword = in.readLine();
                answerlist.push_back(tempword);
            }

            // Close the file
            file2.close();
        } else {
            qDebug() << "Error opening file! Terminating program" << file2.errorString();
            exit(EXIT_FAILURE);
        }

        // Select a random word
        QRandomGenerator randomGenerator = QRandomGenerator::securelySeeded();
        int randomIndex = randomGenerator.bounded(answerlist.size());
        ans_word = answerlist[randomIndex];

        cur_row = 0;
        cur_col = 0;
        cur_word = "";
        prev_word = "";
        for (int i = 0; i < 6; i++)
            cur_word_color[i] = Cell::Color::gray;
        for (int i = 0; i < 6; i++)
            prev_word_color[i] = Cell::Color::gray;
        has_game_started = false;
        is_game_over = false;
        is_game_won = false;
    }

private:
    void _cmpWord();
    int _isValidWord(); // 1: not valid, 2: valid
};

#endif // GAME_H
