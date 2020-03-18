#include "mainwindow.h"

#include <QApplication>
#include <QWebEngineView>

//#include <QGeoCoordinate>

//#include <QQuickView>
//#include <QGuiApplication>
//#include <QQmlApplicationEngine>
//#include <QString>
//#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


//    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/Map/map.qml")));

//    Debug
//    QQuickView view;
//    view.setSource(QUrl("qrc:/Map/map.qml"));
//    view.show();

    MainWindow w;
    w.show();
    return a.exec();
}
