#ifndef RULES_H
#define RULES_H

#include <QWidget>

// Forward declaration of MainWindow
class MainWindow;

namespace Ui {
class rules;
}

class rules : public QWidget
{
    Q_OBJECT

public:
    explicit rules(QWidget *parent = nullptr);
    ~rules();

signals:
    void showMainWindowSignal();

private slots:
    void on_pushButton_clicked();

private:
    Ui::rules *ui;
    MainWindow *mains; // Now we can use pointers to MainWindow without including the full definition

};

#endif // RULES_H
