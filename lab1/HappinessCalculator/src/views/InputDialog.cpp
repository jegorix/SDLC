#include "views/InputDialog.h"
#include <QFormLayout>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QIntValidator>

InputDialog::InputDialog(int lSleep, int lCoffee, int lSocial, int lWork, int lWeekend, QWidget *parent)
    : QDialog(parent) {
    setWindowTitle("Параметры недели");
    setMinimumWidth(420); // Увеличенное окно ввода

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(30, 30, 30, 30);
    mainLayout->setSpacing(20);

    QFormLayout *formLayout = new QFormLayout();
    formLayout->setSpacing(15);

    sleepEdit = createLineEdit(lSleep, 168);
    coffeeEdit = createLineEdit(lCoffee, 999);
    socialEdit = createLineEdit(lSocial, 168);
    workEdit = createLineEdit(lWork, 168);
    weekendEdit = createLineEdit(lWeekend, 168);

    formLayout->addRow("Сон (часов/нед):", sleepEdit);
    formLayout->addRow("Кофе (чашек/нед):", coffeeEdit);
    formLayout->addRow("Общение (часов/нед):", socialEdit);
    formLayout->addRow("Работа (часов/нед):", workEdit);
    formLayout->addRow("Выходные (часов/нед):", weekendEdit);

    mainLayout->addLayout(formLayout);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    buttonBox->button(QDialogButtonBox::Ok)->setText("Подтвердить");
    buttonBox->button(QDialogButtonBox::Cancel)->setText("Отмена");

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    mainLayout->addWidget(buttonBox);
}

QLineEdit* InputDialog::createLineEdit(int val, int maxVal) {
    QLineEdit *edit = new QLineEdit(this);
    edit->setValidator(new QIntValidator(0, maxVal, this));
    edit->setPlaceholderText("0");
    if (val > 0) {
        edit->setText(QString::number(val));
    }
    return edit;
}

int InputDialog::getSleep() const { return sleepEdit->text().toInt(); }
int InputDialog::getCoffee() const { return coffeeEdit->text().toInt(); }
int InputDialog::getSocial() const { return socialEdit->text().toInt(); }
int InputDialog::getWork() const { return workEdit->text().toInt(); }
int InputDialog::getWeekend() const { return weekendEdit->text().toInt(); }