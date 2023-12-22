#ifndef STATISTICSMANAGER_H
#define STATISTICSMANAGER_H

#include <QObject>

class StatisticsManager : public QObject
{
    Q_OBJECT
public:
    explicit StatisticsManager(QObject *parent = nullptr);

    // Functions to update individual statistics
    void updateGamesPlayed();
    void updateWins();
    void updateMaxStreak();
    void updateCurrentStreak();

    // Accessor functions for statistics
    int getGamesPlayed() const;
    int getWins() const;
    int getCurrentStreak() const;
    int getMaxStreak() const;

private:
    int m_gamesPlayed;
    int m_wins;
    int m_maxStreak;
    int m_currentStreak;
};

#endif // STATISTICSMANAGER_H
