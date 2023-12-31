#include "mainwindow.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent, Game *game)
    : QMainWindow(parent)
    , game(game)
{
    setWindowTitle("Guess-O-Word");
    setStyleSheet("background-color: #051d0f");

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QHBoxLayout *outerLayout = new QHBoxLayout(centralWidget);
    QVBoxLayout *mainLayout = new QVBoxLayout();

    // main window components ----------------------------------------------
    inputWindow = new InputWindow(centralWidget, game, nullptr);
    keyboardWindow = new KeyboardWindow(centralWidget, game, nullptr);

    inputWindow->setKeyboardWindow(keyboardWindow);
    keyboardWindow->setInputWindow(inputWindow);

    // main layout --------------------------------------------------------
    QSpacerItem *spacer2 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    title = new QLabel("Guess-O-Word"); // title bar
    QFont font = title->font();
    font.setFamily("Consolas");

    font.setPointSize(50);
    font.setBold(true);
    title->setFont(font);

    mainLayout->addWidget(title, 0, Qt::AlignCenter);
    mainLayout->addWidget(inputWindow, 0, Qt::AlignCenter);
    mainLayout->addWidget(keyboardWindow, 0, Qt::AlignCenter);
    mainLayout->addItem(spacer2);

    // outer layout ---------------------------------------------------------
    QSpacerItem *leftSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QSpacerItem *rightSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    outerLayout->addItem(leftSpacer);
    outerLayout->addLayout(mainLayout);
    outerLayout->addItem(rightSpacer);

    centralWidget->setLayout(outerLayout);
}

MainWindow::~MainWindow()
{
    //delete ui;
    delete title;
    delete inputWindow;
    delete keyboardWindow;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);

    int minWidth = 600;
    int minHeight = 500;
    QSize currentSize = size();
    if (currentSize.width() < minWidth || currentSize.height() < minHeight) {
        resize(qMax(currentSize.width(), minWidth), qMax(currentSize.height(), minHeight));
    }
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
}
