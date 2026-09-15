#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QLineEdit>

class InputDialog : public QDialog {
    Q_OBJECT
public:
    explicit InputDialog(int lSleep, int lCoffee, int lSocial, int lWork, int lWeekend, QWidget *parent = nullptr);

    QLineEdit *sleepEdit;
    QLineEdit *coffeeEdit;
    QLineEdit *socialEdit;
    QLineEdit *workEdit;
    QLineEdit *weekendEdit;

    int getSleep() const;
    int getCoffee() const;
    int getSocial() const;
    int getWork() const;
    int getWeekend() const;

private:
    QLineEdit* createLineEdit(int val, int maxVal);
};

#endif // INPUTDIALOG_H