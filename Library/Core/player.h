#ifndef PLAYER_H
#define PLAYER_H

#include "core_global.h"

#include <QObject>
#include "boardmodel.h"

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

public slots:
    void addWin();
    void setWins(int w);
    void setName(const QString& newName);
    void setActive(bool a);
    void setNextPlayer(Player* aPlayer);
    void setBoard(BoardModel* board);
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
