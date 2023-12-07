#ifndef GAME_H
#define GAME_H

#include <QWidget>
// Forward declaration of MainWindow
class MainWindow;

namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = nullptr);
    ~game();

signals:
    void showMainWindowSignal();

private slots:
    void on_pushButton_clicked();

private:
    Ui::game *ui;
     MainWindow *mains; // Now we can use pointers to MainWindow without including the full definition
};

#endif // GAME_H
