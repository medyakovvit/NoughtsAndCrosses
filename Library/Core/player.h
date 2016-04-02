#ifndef PLAYER_H
#define PLAYER_H

#include "core_global.h"

#include <QObject>
#include "boardmodel.h"

/*!
 * \brief The Player class
 *
 */

class CORESHARED_EXPORT Player : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int wins READ wins WRITE setWins NOTIFY winsChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
    Q_PROPERTY(Player* nextPlayer READ nextPlayer WRITE setNextPlayer NOTIFY nextPlayerChanged)

public:
    explicit Player(QString symbol,
                    QString playerName = "",
                    BoardModel* board = 0,
                    QObject *parent = 0);

    bool active(){return m_active;}
    int wins()const{return m_wins;}
    QString name()const{return m_name;}
    Player* nextPlayer()const{return p_nextPlayer;}
    QString symbol()const{return m_symbol;}

signals:
    void winsChanged(int wins);
    void nameChanged(QString playerName);
    void activeChanged(bool isActive);
    void nextPlayerChanged(Player* next);
    void marked();
    void won();

public slots:
    void win();

    /*! Add 1 to the player's wins*/
    void addWin();
    void setWins(int w);
    void setName(const QString& newName);
    void setActive(bool a);
    void setNextPlayer(Player* aPlayer);
    void setBoard(BoardModel* board);

    /*!
     * Mark cell at index with symbol
     * @param index an integer argument
    */
    void mark(int index);

protected:
    bool m_active;
    int m_wins;
    QString m_name;
    Player *p_nextPlayer;
    QString m_symbol;
    BoardModel* p_board;
};

#endif // PLAYER_H
