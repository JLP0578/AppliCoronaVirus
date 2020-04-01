#include "mainwindow.h"
#include "signinsignupdialog.h"
#include "dailysurveydialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    DailySurveyDialog d;
    d.show();


    return a.exec();
}
