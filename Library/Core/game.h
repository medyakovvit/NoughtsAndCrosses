#ifndef GAME_H
#define GAME_H

#include "core_global.h"

#include <QObject>

class Player;
class BoardModel;

/*!
 * \class Game
 * \brief The Game class
 *
 * Holds players, board model, referee
 */

class CORESHARED_EXPORT Game : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Player* firstPlayer READ firstPlayer NOTIFY firstPlayerChanged)
    Q_PROPERTY(Player* secondPlayer READ secondPlayer NOTIFY secondPlayerChanged)
    Q_PROPERTY(Player* activePlayer READ activePlayer NOTIFY activePlayerChanged)
    Q_PROPERTY(BoardModel* board READ board NOTIFY boardChanged)
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
    Q_PROPERTY(bool firstRun READ firstRun NOTIFY firstRunChanged)

public:
    explicit Game(QObject *parent = 0);

    Player* firstPlayer()const{return p_firstPlayer;}
    Player* secondPlayer()const{return p_secondPlayer;}
    Player* activePlayer()const{return p_activePlayer;}
    BoardModel* board()const{return p_board;}
    bool active()const{return m_active;}
    bool firstRun()const{return m_firstRun;}

signals:
    void started();
    void reseted();
    void firstPlayerChanged(Player* first);
    void secondPlayerChanged(Player* srcond);
    void activePlayerChanged(Player* active);
    void boardChanged(BoardModel* board);
    void activeChanged(bool isActive);
    void firstRunChanged(bool isFirstRun);

    void draw();

public slots:
    /*! Start a game */
    void start();

    /*! Reset game: clear board*/
    void reset();

    /*! Activate next player to make move */
    void nextPlayer();

protected slots:
    void on_activePlayerMarked();
    void setActive(bool a);
    void on_someoneWon();

protected:
    int m_moveCounter;
    bool m_active;
    bool m_firstRun;
    Player* p_firstPlayer;
    Player* p_secondPlayer;
    Player* p_activePlayer;
    BoardModel* p_board;
};

#endif // GAME_H
