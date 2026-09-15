#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLabel window("Happiness Calculator project template");
    window.setWindowTitle("Happiness Calculator");
    window.resize(420, 120);
    window.show();

    return app.exec();
}
