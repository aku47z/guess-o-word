#ifndef STATISTICS_H
#define STATISTICS_H

#include <QDialog>

namespace Ui {
class Statistics;
}

class leaderboard : public QDialog
{
    Q_OBJECT

public:
    explicit leaderboard(QWidget *parent = nullptr);
    ~leaderboard();
    void updateGamesPlayedLabel(int gamesPlayed);
    void updateWinCountLabel(int winCount);
    void updateCurrentStreakLabel(int currentStreak);
    void updateMaxStreakLabel(int maxStreak);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Statistics *ui;
};

#endif // STATISTICS_H
