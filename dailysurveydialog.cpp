#include "dailysurveydialog.h"
#include "ui_dailysurveydialog.h"

DailySurveyDialog::DailySurveyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DailySurveyDialog)
{
    ui->setupUi(this);
    initForm();
}

DailySurveyDialog::~DailySurveyDialog()
{
    delete ui;
}

void DailySurveyDialog::initForm()
{
    //Récupérer formulaire de l'api

    //Calculer le nombre de page qu'il y aura au formulaire
    //Ajouter à la propriété nbPages

    //initialiser poge Global status

    //initialiser page status

    //initialiser page symptom

    //initialiser pages des question

    /* Création d'un label
    QLabel *test = new QLabel("test",ui->stackedWidget->widget(1),Qt::Widget);
    test->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    //test->setFont(QFont::);
    //test->setSizePolicy(QSizePolicy::)
    */

}


void DailySurveyDialog::on_pushButtonNextQuestion_clicked()
{
    int currentWidget = ui->stackedWidget->currentIndex();
    int nextWidget = ui->stackedWidget->currentIndex()+1;
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex()+1);

}

void DailySurveyDialog::on_pushButtonPreviousQuestion_clicked()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex()-1);
}
