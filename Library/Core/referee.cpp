#include "referee.h"

Referee::Referee(QObject *parent) : QObject(parent)
{

}

QString Referee::checkWinner(const QVector<QString> &board)
{
    if(board.size() != 9)
        return QString();

    // Left-top corner
    if( (board[0] == board[1] && board[0] == board[2]) ||
            (board[0] == board[3] && board[0] == board[6]) )
        return board[0];

    // Center
    for(int i=4; i>0; i--)
    {
        if( board[4] == board[4-i] && board[4] == board[4+i])
            return board[4];
    }
    // Bottom-right corner
    if( (board[8] == board[5] && board[8] == board[2]) ||
            (board[8] == board[7] && board[8] == board[6]) )
        return board[8];

    // Draw
    return QString();
}
