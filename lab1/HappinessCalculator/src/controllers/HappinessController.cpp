#include "controllers/HappinessController.h"
#include "views/InputDialog.h"
#include <QMessageBox>
#include <QSettings>

HappinessController::HappinessController(HappinessModel *m, MainWindow *v, QObject *parent)
    : QObject(parent), model(m), view(v) {
    
    connect(model, &HappinessModel::dataUpdated, view, &MainWindow::onModelUpdated);
    connect(view->inputButton, &QPushButton::clicked, this, &HappinessController::onInputButtonClicked);

    // Восстанавливаем данные из реестра/файла настроек при старте
    loadSavedData();
}

void HappinessController::loadSavedData() {
    QSettings settings("BSUIR", "HappinessCalculator");
    if (settings.value("hasSavedData", false).toBool()) {
        view->lastSleep = settings.value("sleep", 0).toDouble();
        view->lastCoffee = settings.value("coffee", 0).toDouble();
        view->lastSocial = settings.value("social", 0).toDouble();
        view->lastWork = settings.value("work", 0).toDouble();
        view->lastWeekend = settings.value("weekend", 0).toDouble();

        model->calculateHappiness(view->lastSleep, view->lastCoffee, view->lastSocial, view->lastWork, view->lastWeekend);
    }
}

void HappinessController::onInputButtonClicked() {
    InputDialog dialog(view->lastSleep, view->lastCoffee, view->lastSocial, view->lastWork, view->lastWeekend, view);
    
    if (dialog.exec() == QDialog::Accepted) {
        double s = dialog.getSleep();
        double c = dialog.getCoffee();
        double soc = dialog.getSocial();
        double w = dialog.getWork();
        double wk = dialog.getWeekend();

        if (s + soc + w + wk > 168.0) {
            QMessageBox::critical(view, "Ошибка", "Некорректные данные!\nСумма часов в неделю не может превышать 168.");
            return;
        }

        // Сохранение в оперативную память
        view->lastSleep = s;
        view->lastCoffee = c;
        view->lastSocial = soc;
        view->lastWork = w;
        view->lastWeekend = wk;

        // Сохранение на диск (QSettings)
        QSettings settings("BSUIR", "HappinessCalculator");
        settings.setValue("sleep", s);
        settings.setValue("coffee", c);
        settings.setValue("social", soc);
        settings.setValue("work", w);
        settings.setValue("weekend", wk);
        settings.setValue("hasSavedData", true);

        model->calculateHappiness(s, c, soc, w, wk);
    }
}