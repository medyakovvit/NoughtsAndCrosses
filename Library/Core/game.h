#ifndef GAME_H
#define GAME_H

#include "core_global.h"

#include <QObject>
#include "player.h"

class CORESHARED_EXPORT Game : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Player* firstPlayer READ firstPlayer NOTIFY firstPlayerChanged)
    Q_PROPERTY(Player* secondPlayer READ secondPlayer NOTIFY secondPlayerChanged)

public:
    explicit Game(QObject *parent = 0);

    Player* firstPlayer()const{return p_firstPlayer;}
    Player* secondPlayer()const{return p_secondPlayer;}

signals:
    void started();
    void firstPlayerChanged(Player* first);
    void secondPlayerChanged(Player* srcond);

public slots:
    void start();

protected:
    Player* p_firstPlayer;
    Player* p_secondPlayer;
};

#endif // GAME_H
