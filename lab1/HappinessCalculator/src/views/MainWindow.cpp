#include "views/MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Калькулятор счастья");
    setMinimumSize(1100, 500);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(35, 35, 35, 35);
    mainLayout->setSpacing(30);

    // Левая колонка (Индекс и Кнопка)
    QVBoxLayout *leftLayout = new QVBoxLayout();
    leftLayout->setSpacing(15);

    QLabel *title = new QLabel("Ваш индекс счастья", this);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font-size: 20px; font-weight: bold; color: #7f8c8d;");

    indexLabel = new QLabel("— %", this);
    indexLabel->setAlignment(Qt::AlignCenter);
    indexLabel->setStyleSheet("font-size: 60px; font-weight: bold; color: #27ae60; margin: 5px 0;");

    recLabel = new QLabel("Введите данные о вашей неделе, чтобы получить расчет.", this);
    recLabel->setAlignment(Qt::AlignCenter);
    recLabel->setWordWrap(true);
    recLabel->setStyleSheet("font-size: 15px; color: #34495e;");

    inputButton = new QPushButton("Рассчитать счастье", this);
    inputButton->setCursor(Qt::PointingHandCursor);

    leftLayout->addWidget(title);
    leftLayout->addWidget(indexLabel);
    leftLayout->addWidget(recLabel);
    leftLayout->addStretch();
    leftLayout->addWidget(inputButton);

    // Правая колонка (Круговая диаграмма)
    series = new QPieSeries();
    series->setHoleSize(0.42);

    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Распределение 168 часов недели");

    QFont titleFont = chart->titleFont();
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    chart->setTitleFont(titleFont);

    chart->setAnimationOptions(QChart::AllAnimations);

    // Легенда справа
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
    QFont legendFont = chart->legend()->font();
    legendFont.setPointSize(13);
    chart->legend()->setFont(legendFont);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    mainLayout->addLayout(leftLayout, 2);
    mainLayout->addWidget(chartView, 3);
}

void MainWindow::onModelUpdated(double percentage, QString rec, double sleep, double coffee, double social, double work, double weekend) {
    indexLabel->setText(QString("%1%").arg(percentage, 0, 'f', 2));

    if (percentage < 50.0) {
        indexLabel->setStyleSheet("font-size: 60px; font-weight: bold; color: #e74c3c; margin: 5px 0;");
    } else if (percentage < 75.0) {
        indexLabel->setStyleSheet("font-size: 60px; font-weight: bold; color: #f39c12; margin: 5px 0;");
    } else {
        indexLabel->setStyleSheet("font-size: 60px; font-weight: bold; color: #27ae60; margin: 5px 0;");
    }

    recLabel->setText(rec);

    series->clear();

    double otherTime = std::max(0.0, 168.0 - (sleep + work + weekend + social));

    // Формируем полный текст подписи для легенды: "Категория: Х ч (Y.Y%)"
    auto addSlice = [this](const QString &name, double hours, const QColor &color) {
        if (hours <= 0) return;

        double percentOfWeek = (hours / 168.0) * 100.0;

        QString fullLabel = QString("%1: %2 ч (%3%)")
                                .arg(name)
                                .arg(hours, 0, 'f', 0)
                                .arg(percentOfWeek, 0, 'f', 1);

        QPieSlice *slice = series->append(fullLabel, hours);
        slice->setColor(color);
        slice->setLabelVisible(false); // Подпись отображается в легенде справа
    };

    addSlice("Сон", sleep, QColor("#3498db"));
    addSlice("Работа", work, QColor("#e74c3c"));
    addSlice("Выходные", weekend, QColor("#2ecc71"));
    addSlice("Общение", social, QColor("#9b59b6"));
    addSlice("Прочее", otherTime, QColor("#95a5a6"));
}