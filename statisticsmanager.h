#ifndef STATISTICSMANAGER_H
#define STATISTICSMANAGER_H

#include <QObject>
#include <QString>

class Game; // Forward declaration to indicate that Game is a class

class StatisticsManager : public QObject
{
    Q_OBJECT
public:
    explicit StatisticsManager(QObject *parent = nullptr);

    void updateGamesPlayed();
    void updateWins();
    void updateMaxStreak();
    void resetCurrentStreak();
    void updateGameMode();
    int getGamesPlayed() const;
    int getWins() const;
    int getCurrentStreak() const;
    int getMaxStreak() const;
    void passInstance(Game &game);
    int getDifficultyNumber() const;

private:
    int m_gamesPlayed;
    int m_wins;
    int m_maxStreak;
    int m_currentStreak;
    bool easy_mode = true;
    Game *gameInstancePtr;
};

#endif // STATISTICSMANAGER_H
