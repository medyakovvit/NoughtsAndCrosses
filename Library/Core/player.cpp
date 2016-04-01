#include "player.h"

Player::Player(QString symbol, QString playerName, BoardModel *board, QObject *parent) : QObject(parent),
    m_active(false), m_name(playerName), m_symbol(symbol), p_board(board)
{

}

void Player::addWin()
{
    m_wins++;
    emit winsChanged(m_wins);
}

void Player::setWins(int w)
{
    if(m_wins == w)
        return;

    m_wins = w;
    emit winsChanged(w);
}

void Player::setName(const QString &newName)
{
    if(m_name == newName)
        return;

    m_name = newName;
    emit nameChanged(newName);
}

void Player::setActive(bool a)
{
    if(m_active == a)
        return;

    m_active = a;
    emit activeChanged(a);
}

void Player::setNextPlayer(Player *aPlayer)
{
    if(p_nextPlayer == aPlayer)
        return;

    p_nextPlayer = aPlayer;
    emit nextPlayerChanged(aPlayer);
}

void Player::setBoard(BoardModel *board)
{
    if(p_board == board)
        return;

    p_board = board;
}

void Player::mark(int index)
{
    if(p_board)
    {
        p_board->setSymbol(this->m_symbol, index);
        emit marked();
    }
}
