#ifndef SIGNINSIGNUPDIALOG_H
#define SIGNINSIGNUPDIALOG_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkCookieJar>


namespace Ui {
class SigninSignupDialog;
}

class SigninSignupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SigninSignupDialog(QWidget *parent = nullptr);
    ~SigninSignupDialog();

private slots:
    void on_pushButtonSignup_clicked();

    void on_pushButtonGoToSigninPage_clicked();

    void on_lineEditPseudo_editingFinished();

    void on_lineEditPassword_editingFinished();


    void on_lineEditAddress_editingFinished();

    void on_lineEditCity_editingFinished();

    void on_lineEditPostCode_editingFinished();

private:
    Ui::SigninSignupDialog *ui;
    QString identifiant,nom,prenom;
    QNetworkAccessManager myNWM;
    QNetworkCookieJar cookieJar;
};

#endif // SIGNINSIGNUPDIALOG_H
