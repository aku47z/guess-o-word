#include "rules.h"
#include "ui_rules.h"

rules::rules(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rules)
{
    ui->setupUi(this);
}

rules::~rules()
{
    delete ui;
}

void rules::on_pushButton_clicked()
{
    // Emit the signal to show the main window
    emit showMainWindowSignal();
     // Close the rules window
    this->close();
}

