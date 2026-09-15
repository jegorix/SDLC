#include <QApplication>
#include "models/HappinessModel.h"
#include "views/MainWindow.h"
#include "controllers/HappinessController.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Глобальные стили (QSS) для красивого и современного интерфейса
    QString styleSheet = R"(
        QWidget {
            font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Helvetica, Arial, sans-serif;
            font-size: 14px;
            color: #2c3e50;
            background-color: #f8f9fa;
        }
        QPushButton {
            background-color: #3498db;
            color: #ffffff;
            border: none;
            border-radius: 8px;
            padding: 12px 20px;
            font-size: 15px;
            font-weight: bold;
        }
        QPushButton:hover { background-color: #2980b9; }
        QPushButton:pressed { background-color: #1f618d; }
        QDoubleSpinBox {
            padding: 8px;
            border: 1px solid #ced4da;
            border-radius: 6px;
            background-color: #ffffff;
        }
        QDoubleSpinBox:focus { border: 1px solid #3498db; }
        QDialog { background-color: #ffffff; }
    )";
    app.setStyleSheet(styleSheet);

    HappinessModel model;
    MainWindow view;
    HappinessController controller(&model, &view);

    view.show();

    return app.exec();
}