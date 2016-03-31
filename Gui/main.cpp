#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include <boardmodel.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    BoardModel model;
    engine.rootContext()->setContextProperty("boardModel", &model);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
