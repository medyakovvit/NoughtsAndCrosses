#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include <boardmodel.h>
#include <game.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    BoardModel model;
    Game game;
    engine.rootContext()->setContextProperty("boardModel", &model);
    engine.rootContext()->setContextProperty("myGame", &game);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
