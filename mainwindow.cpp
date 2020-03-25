#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGeoCoordinate>

#include <QWebEngineView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWebEngineView *view = new QWebEngineView();
    view->setUrl(QUrl("http://lgt-dominique-villars6.pro.dns-orange.fr/~teamjulie/map.php"));
    //ui->horizontalLayout->addWidget(view);
    view->show();
    ui->horizontalLayout->addWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

