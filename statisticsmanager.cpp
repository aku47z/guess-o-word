#include "statisticsmanager.h"
#include"core/game.h"

StatisticsManager::StatisticsManager(QObject *parent) : QObject(parent), m_gamesPlayed(0), m_wins(0), m_maxStreak(0), m_currentStreak(0) {
    //constructor if needed
}

void StatisticsManager::updateGamesPlayed() {
    // Update games played
    m_gamesPlayed++;
}

void StatisticsManager::updateWins() {
    // Update no of wins
    m_currentStreak++;
    updateMaxStreak();
    m_wins++;
}

void StatisticsManager::updateMaxStreak() {
    // Update max streak
    if(m_currentStreak>m_maxStreak)
        m_maxStreak=m_currentStreak;
}

void StatisticsManager::updateCurrentStreak() {
    // Reset current streak
    m_currentStreak=0;
}

void StatisticsManager::updateGameMode(){
    easy_mode=!easy_mode;
    gameInstancePtr->resetGame();
}

QString StatisticsManager::getFilepath() const {
    if (easy_mode)
    {
        return ":/valid_answers.txt";
    }
    else
    {
        return ":/valid_words.txt";
    }
}

int StatisticsManager::getGamesPlayed() const {
    return m_gamesPlayed;
}

int StatisticsManager::getWins() const {
    return m_wins;
}

int StatisticsManager::getMaxStreak() const {
    return m_maxStreak;
}

int StatisticsManager::getCurrentStreak() const {
    return m_currentStreak;
}

int StatisticsManager::getDifficultyNumber() const{
    if (easy_mode)
    {
        return 5;
    }
    else
    {
        return 6;
    }
}

void StatisticsManager::passInstance(Game& game) {
    gameInstancePtr = &game;
}
