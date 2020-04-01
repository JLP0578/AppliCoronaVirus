#ifndef DAILYSURVEYDIALOG_H
#define DAILYSURVEYDIALOG_H

#include <QDialog>

namespace Ui {
class DailySurveyDialog;
}

class DailySurveyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DailySurveyDialog(QWidget *parent = nullptr);
    ~DailySurveyDialog();
    void initForm();

private slots:
    void on_pushButtonNextQuestion_clicked();

    void on_pushButtonPreviousQuestion_clicked();

private:
    Ui::DailySurveyDialog *ui;


};

#endif // DAILYSURVEYDIALOG_H
