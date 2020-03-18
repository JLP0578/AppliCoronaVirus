#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGeoCoordinate>

#include <QWebEngineView>

#include <QQuickWidget>
#include <QQuickView>
#include <QtQuickWidgets/QtQuickWidgets>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:/Map/map.qml")));

    ui->setupUi(this);

//    QQuickWidget* widget = new QQuickWidget();
//    widget->setSource(QUrl(QStringLiteral("qrc:/Map/map.qml")));
//    widget->setResizeMode( QQuickWidget::SizeRootObjectToView );
//    ui->verticalLayout->addWidget(widget);

    QWebEngineView *view = new QWebEngineView();
    view->load(QUrl("http://www.qt.io/"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

