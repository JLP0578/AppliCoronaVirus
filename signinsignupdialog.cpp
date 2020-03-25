#include "signinsignupdialog.h"
#include "ui_signinsignupdialog.h"
#include <QUrlQuery>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#define URL "http://lgt-dominique-villars6.pro.dns-orange.fr/~teamjulie/user/"
#define URLSIGNIN "http://lgt-dominique-villars6.pro.dns-orange.fr/~teamjulie/auth/"

SigninSignupDialog::SigninSignupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SigninSignupDialog)
{
    ui->setupUi(this);
    //espace pour les sessions
    myNWM.setCookieJar(&cookieJar);
}

SigninSignupDialog::~SigninSignupDialog()
{
    delete ui;
}

void SigninSignupDialog::on_pushButtonSignup_clicked()
{

   //verif du user et du pass
   QUrl serviceUrl(URL);
   QUrl donnees;
   QUrlQuery query;


   query.addQueryItem("pseudo", ui->lineEditPseudo->text());
   query.addQueryItem("password",ui->lineEditPassword->text());
   query.addQueryItem("age", ui->comboBoxAge->currentText());
   query.addQueryItem("address",ui->lineEditAddress->text());
   query.addQueryItem("city", ui->lineEditCity->text());
   query.addQueryItem("postCode",ui->lineEditPostCode->text());
   query.addQueryItem("country",ui->comboBoxCountry->currentText());

   qDebug()<<query.toString();

   donnees.setQuery(query);
   QByteArray postData(donnees.toString(QUrl::RemoveFragment).remove(0,1).toLatin1());
   //création de la requête http qui va interroger le service
   QNetworkRequest request(serviceUrl);
   request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
   //exécution de la requête http
   QNetworkReply *reply1 = myNWM.post(request,postData);

   //attente de la réception complète de la réponse
   while(!reply1->isFinished())
   {
       qApp->processEvents();
   }
   //lecture de la réponse
   QByteArray response_data = reply1->readAll();


   //formation du json à partir de la réponse
   QJsonDocument jsonResponse = QJsonDocument::fromJson(response_data);

   QJsonObject jsonResponseObject = jsonResponse.object();
   qDebug()<<jsonResponseObject;

   if (jsonResponseObject["new"].toObject()["status"].toBool()) {
       ui->labelDisplayMessage->setText(jsonResponseObject["new"].toObject()["message"].toString());
       //Reset Fields

   } else {
       ui->labelDisplayMessage->setText(jsonResponseObject["new"].toObject()["message"].toString());
   }

   //nettoyage de reply1
   reply1->deleteLater();
}

void SigninSignupDialog::on_pushButtonGoToSigninPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void SigninSignupDialog::on_lineEditPseudo_editingFinished()
{

    if (!ui->lineEditPseudo->checkPseudoValid()){
        ui->lineEditPseudo->setInvalidStyle();
    } else {
        ui->lineEditPseudo->setDefaultStyle();
    }
}

void SigninSignupDialog::on_lineEditPassword_editingFinished()
{
    if (!ui->lineEditPassword->checkPasswordValid()){
        ui->lineEditPassword->setInvalidStyle();
    } else {
        ui->lineEditPassword->setDefaultStyle();
    }
}


void SigninSignupDialog::on_lineEditAddress_editingFinished()
{
    if (!ui->lineEditAddress->checkAddressValid()){
        ui->lineEditAddress->setInvalidStyle();
    } else {
        ui->lineEditAddress->setDefaultStyle();
    }
}

void SigninSignupDialog::on_lineEditCity_editingFinished()
{
    if (!ui->lineEditCity->checkCityValid()){
        ui->lineEditCity->setInvalidStyle();
    } else {
        ui->lineEditCity->setDefaultStyle();
    }
}

void SigninSignupDialog::on_lineEditPostCode_editingFinished()
{
    if (!ui->lineEditPostCode->checkPostCodeValid()){
        ui->lineEditPostCode->setInvalidStyle();
    } else {
        ui->lineEditPostCode->setDefaultStyle();
    }
}

void SigninSignupDialog::on_pushButtonConnect_clicked()
{

    //verif du user et du pass
    QUrl serviceUrl(URLSIGNIN);
    QUrl donnees;
    QUrlQuery query;


    query.addQueryItem("pseudo", ui->lineEditPseudoSignin->text());
    query.addQueryItem("password",ui->lineEditPasswordSignin->text());

    qDebug()<<query.toString();

    donnees.setQuery(query);
    QByteArray postData(donnees.toString(QUrl::RemoveFragment).remove(0,1).toLatin1());
    //création de la requête http qui va interroger le service
    QNetworkRequest request(serviceUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    //exécution de la requête http
    QNetworkReply *reply1 = myNWM.post(request,postData);

    //attente de la réception complète de la réponse
    while(!reply1->isFinished())
    {
        qApp->processEvents();
    }
    //lecture de la réponse
    QByteArray response_data = reply1->readAll();


    //formation du json à partir de la réponse
    QJsonDocument jsonResponse = QJsonDocument::fromJson(response_data);

    QJsonObject jsonResponseObject = jsonResponse.object();
    qDebug()<<jsonResponseObject;

    if (jsonResponseObject["auth"].toObject()["status"].toBool()) {
        ui->labelDisplayMessageSignin->setText(jsonResponseObject["auth"].toObject()["message"].toString());
        //Reset Fields

    } else {
        ui->labelDisplayMessageSignin->setText(jsonResponseObject["auth"].toObject()["message"].toString());
    }

    //nettoyage de reply1
    reply1->deleteLater();
}

void SigninSignupDialog::on_pushButtonGoToSignupPage_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
