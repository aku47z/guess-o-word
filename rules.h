#ifndef RULES_H
#define RULES_H

#include "homewindow.h"
#include <QWidget>

namespace Ui {
class rules;
}

class rules : public QWidget
{
    Q_OBJECT

public:
    explicit rules(QWidget *parent = nullptr);
    ~rules();

private slots:
    void on_pushButton_clicked();

private:
    Ui::rules *ui;
};

#endif // RULES_H
