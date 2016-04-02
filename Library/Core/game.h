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
    Q_PROPERTY(Player* activePlayer READ activePlayer NOTIFY activePlayerChanged)
    Q_PROPERTY(BoardModel* board READ board NOTIFY boardChanged)
    Q_PROPERTY(bool active READ active NOTIFY activeChanged)

public:
    explicit Game(QObject *parent = 0);

    Player* firstPlayer()const{return p_firstPlayer;}
    Player* secondPlayer()const{return p_secondPlayer;}
    Player* activePlayer()const{return p_activePlayer;}
    BoardModel* board()const{return p_board;}
    bool active()const{return m_active;}

signals:
    void started();
    void reseted();
    void firstPlayerChanged(Player* first);
    void secondPlayerChanged(Player* srcond);
    void activePlayerChanged(Player* active);
    void boardChanged(BoardModel* board);
    void activeChanged(bool isActive);

    void draw();

public slots:
    void start();
    void reset();
    void nextPlayer();

protected slots:
    void on_activePlayerMarked();

protected:
    int m_moveCounter;
    int m_active;
    Player* p_firstPlayer;
    Player* p_secondPlayer;
    Player* p_activePlayer;
    BoardModel* p_board;
};

#endif // GAME_H
