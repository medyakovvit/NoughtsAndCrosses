#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

class Player : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int wins READ wins WRITE setWins NOTIFY winsChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
    Q_PROPERTY(Player* nextPlayer READ nextPlayer WRITE setNextPlayer NOTIFY nextPlayerChanged)

public:
    explicit Player(QString playerName = "", QObject *parent = 0);

    bool active(){return m_active;}
    int wins()const{return m_wins;}
    QString name()const{return m_name;}
    Player* nextPlayer()const{return p_nextPlayer;}

signals:
    void winsChanged(int wins);
    void nameChanged(QString playerName);
    void activeChanged(bool isActive);
    void nextPlayerChanged(Player* next);

public slots:
    void addWin();
    void setWins(int w);
    void setName(const QString& newName);
    void setActive(bool a);
    void setNextPlayer(Player* aPlayer);

protected:
    bool m_active;
    int m_wins;
    QString m_name;
    Player *p_nextPlayer;
};

#endif // PLAYER_H
