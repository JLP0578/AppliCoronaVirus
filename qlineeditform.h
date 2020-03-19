#ifndef QLINEEDITFORM_H
#define QLINEEDITFORM_H
#include <QLineEdit>

class QLineEditForm : public QLineEdit
{
public:
    QLineEditForm(QWidget *parent = 0);
    void setInvalidStyle();
    void setDefaultStyle();
    bool checkPseudoValid();
    bool checkPasswordValid();
    bool checkAddressValid();
    bool checkCityValid();
    bool checkPostCodeValid();


};

#endif // QLINEEDITFORM_H
