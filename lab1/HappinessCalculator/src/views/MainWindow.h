#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QString>

#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QChart>

class MainWindow : public QWidget {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    double lastSleep = 0, lastCoffee = 0, lastSocial = 0, lastWork = 0, lastWeekend = 0;

    QLabel *indexLabel;
    QLabel *recLabel;
    QPushButton *inputButton;

    QChart *chart;
    QChartView *chartView;
    QPieSeries *series;

public slots:
    void onModelUpdated(double percentage, QString rec, double sleep, double coffee, double social, double work, double weekend);
};

#endif // MAINWINDOW_H