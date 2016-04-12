#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include <game.h>
#include <player.h>
#include <boardmodel.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterUncreatableType<Player>("my.Xs_and_Os.Game", 1, 0, "Player", "Player is uncreatable type");
    qmlRegisterUncreatableType<BoardModel>("my.Xs_and_Os.Game", 1, 0, "BoardModel", "BoardModel is uncreatable type");

    Game game;
    engine.rootContext()->setContextProperty("myGame", &game);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
