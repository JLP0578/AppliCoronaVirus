#include "mainwindow.h"
#include "signinsignupdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    SigninSignupDialog d;
    d.show();


    return a.exec();
}
