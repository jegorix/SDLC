#include "models/HappinessModel.h"
#include <algorithm>

HappinessModel::HappinessModel(QObject *parent) : QObject(parent) {}

void HappinessModel::calculateHappiness(double sleep, double coffee, double social, double work, double weekend) {
    // 1. Оценка сна (норма 49ч/нед = 7ч/день). Вес 40%
    double sleepScore = 0.0;
    if (sleep < 42.0) {
        sleepScore = (sleep / 49.0) * 40.0; 
    } else if (sleep <= 56.0) {
        sleepScore = (sleep / 49.0) * 100.0;
        if (sleepScore > 100.0) sleepScore = 100.0;
    } else {
        sleepScore = std::max(50.0, 100.0 - (sleep - 56.0) * 2.0);
    }

    // 2. Оценка работы (норма до 40ч/нед). Вес 30%
    double workScore = 100.0;
    if (work > 40.0) {
        workScore = std::max(0.0, 100.0 - (work - 40.0) * 2.5);
    }

    // 3. Выходные и общение. Вес 15% и 15%
    double weekendScore = std::min(100.0, (weekend / 48.0) * 100.0);
    double socialScore = std::min(100.0, (social / 15.0) * 100.0);

    // 4. Штраф за кофе (>14 чашек в неделю)
    double coffeePenalty = (coffee > 14.0) ? (coffee - 14.0) * 1.0 : 0.0;

    double total = (sleepScore * 0.40) + (workScore * 0.30) + (weekendScore * 0.15) + (socialScore * 0.15) - coffeePenalty;
    total = std::max(0.0, std::min(100.0, total));

    QString recommendation;
    if (sleep < 42.0) {
        recommendation = "Критический недосып! Вы спите меньше 6 часов в день. Срочно выспитесь!";
    } else if (work > 50.0) {
        recommendation = "Опасная перегрузка работой! Пора подумать об увольнении или отпуске.";
    } else if (total < 50.0) {
        recommendation = "Уровень счастья ниже нормы. Организм переутомлен, вам нужен полноценный отдых.";
    } else if (total < 75.0) {
        recommendation = "Уровень счастья в норме. Купите пиццу и устройте себе хороший вечер!";
    } else {
        recommendation = "Прекрасный баланс жизни и работы! Продолжайте в том же духе.";
    }

    emit dataUpdated(total, recommendation, sleep, coffee, social, work, weekend);
}