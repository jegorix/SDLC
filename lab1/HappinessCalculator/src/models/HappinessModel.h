#ifndef HAPPINESSMODEL_H
#define HAPPINESSMODEL_H

#include <QObject>
#include <QString>

class HappinessModel : public QObject {
    Q_OBJECT
public:
    explicit HappinessModel(QObject *parent = nullptr);
    void calculateHappiness(double sleep, double coffee, double social, double work, double weekend);

signals:
    void dataUpdated(double index, QString recommendation, double sleep, double coffee, double social, double work, double weekend);
};

#endif // HAPPINESSMODEL_H