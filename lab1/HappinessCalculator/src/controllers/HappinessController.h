#ifndef HAPPINESSCONTROLLER_H
#define HAPPINESSCONTROLLER_H

#include <QObject>
#include "models/HappinessModel.h"
#include "views/MainWindow.h"

class HappinessController : public QObject {
    Q_OBJECT
public:
    HappinessController(HappinessModel *m, MainWindow *v, QObject *parent = nullptr);

private slots:
    void onInputButtonClicked();

private:
    void loadSavedData();
    HappinessModel *model;
    MainWindow *view;
};

#endif // HAPPINESSCONTROLLER_H