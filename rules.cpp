#include "rules.h"
#include "ui_rules.h"
#include "homewindow.h"

rules::rules(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rules)
{
    ui->setupUi(this);

    // Connect the clicked signal of pushButton to the on_pushButton_clicked() slot
    connect(ui->pushButton, &QPushButton::clicked, this, &rules::on_pushButton_clicked);
}

rules::~rules()
{
    delete ui;
}

void rules::on_pushButton_clicked()
{
    // Hide the current rules window
    this->hide();

    // Assuming HomeWindow is an instance of HomeWindow class, not a class itself
    HomeWindow *homeWindow = qobject_cast<HomeWindow*>(parentWidget());

    if (homeWindow) {
        // Show the HomeWindow
        homeWindow->show();
    }
}
