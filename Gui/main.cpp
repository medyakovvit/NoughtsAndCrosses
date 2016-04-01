#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include <boardmodel.h>
#include <game.h>
#include <player.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    BoardModel model;
    Game game;

    //qmlRegisterType<Player>("my.X_And_O.Player", 1, 0, "Player");
    qmlRegisterUncreatableType<Player>("my.X_And_O.Player", 1, 0, "Player",
                                       QString("Player is uncreatable in qml"));
    engine.rootContext()->setContextProperty("boardModel", &model);
    engine.rootContext()->setContextProperty("myGame", &game);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
