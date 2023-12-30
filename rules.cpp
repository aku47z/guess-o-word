#include "rules.h"
#include "homewindow.h"
#include "ui_rules.h"

rules::rules(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::rules)
{
    ui->setupUi(this);
}

rules::~rules()
{
    delete ui;
}

void rules::on_pushButton_clicked()
{
    this->close();
}
