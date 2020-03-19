#include "qlineeditform.h"
#include <QDebug>

QLineEditForm::QLineEditForm(QWidget *parent) : QLineEdit(parent)
{

}

void QLineEditForm::setInvalidStyle()
{
    setStyleSheet("QLineEdit{ "
                  "border: 1px solid red;}");
}

void QLineEditForm::setDefaultStyle()
{
    setStyleSheet("");
}

bool QLineEditForm::checkPseudoValid()
{
    bool check = true;

    if(text().length() < 6 || text().length() > 64) {
        check = false;
    } else {
        for (int i = 0 ; i<text().length() ; i++) {
            if (text()[i] == " "){
                check = false;
            }
        }
    }

    return check;
}

bool QLineEditForm::checkPasswordValid()
{
    bool check = true;

    if(text().length() < 6 || text().length() > 32) {
        check = false;
    } else {
        for (int i = 0 ; i<text().length() ; i++) {
            if (text()[i] == " "){
                check = false;
            }
        }
    }
    return check;
}

bool QLineEditForm::checkAddressValid()
{
    bool check = true;

    if(text().length() < 3 || text().length() > 64) {
        check = false;
    } else {
        for (int i = 0 ; i<text().length() ; i++) {
            if (text()[i] == "?" || text()[i] == "!" || text()[i] == "_" || text()[i] == "\"" || text()[i] == "%" || text()[i] == "ù"){
                check = false;
            }
        }
    }
    return check;
}

bool QLineEditForm::checkCityValid()
{
    bool check = true;

    if(text().length() < 3 || text().length() > 64) {
        check = false;
    } else {
        for (int i = 0 ; i<text().length() ; i++) {
            if (text()[i] == "?" || text()[i] == "!" || text()[i] == "_" || text()[i] == "\"" || text()[i] == "%" || text()[i] == "ù"){
                check = false;
            }
        }
    }
    return check;
}

bool QLineEditForm::checkPostCodeValid()
{
    bool check = true;
    if(text().length() < 5 || text().length() > 5) {
        check = false;
    } else {
        for (int i = 0 ; i<text().length() ; i++) {
            if (!(text()[i] == "0" || text()[i] == "1" || text()[i] == "2" || text()[i] == "3" || text()[i] == "4" || text()[i] == "5" ||
                  text()[i] == "6" || text()[i] == "7" || text()[i] == "8" || text()[i] == "9")){
                check = false;
            }
        }
    }
    return check;
}
