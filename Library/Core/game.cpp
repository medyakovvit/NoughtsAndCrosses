#include "game.h"

#include "referee.h"

Game::Game(QObject *parent) : QObject(parent),
    m_moveCounter(0), m_active(false)
{
    p_board = new BoardModel(this);

    p_firstPlayer = new Player("x", "Player 1", p_board, this);
    p_activePlayer = p_firstPlayer;
    p_secondPlayer = new Player("o", "Player2", p_board, this);

    connect(p_firstPlayer, &Player::marked, this, &Game::on_activePlayerMarked);
    connect(p_firstPlayer, &Player::won, this, &Game::on_someoneWon);
    connect(p_secondPlayer, &Player::marked, this, &Game::on_activePlayerMarked);
    connect(p_secondPlayer, &Player::won, this, &Game::on_someoneWon);

    p_firstPlayer->setNextPlayer(p_secondPlayer);
    p_secondPlayer->setNextPlayer(p_firstPlayer);
    p_firstPlayer->setActive(true);
}

void Game::start()
{
    this->setActive(true);
    emit started();
}

void Game::reset()
{
    if(p_board)
    {
        p_board->clearBoard();
        emit reseted();
    }

    if(p_activePlayer != p_firstPlayer)
    {
        if(p_activePlayer)
            p_activePlayer->setActive(false);
        p_activePlayer = p_firstPlayer;
        if(p_activePlayer)
            p_activePlayer->setActive(true);
    }
}

void Game::nextPlayer()
{
    if(p_activePlayer)
    {
        p_activePlayer->setActive(false);
        p_activePlayer = p_activePlayer->nextPlayer();
        if(p_activePlayer)
            p_activePlayer->setActive(true);
    }
}

void Game::on_activePlayerMarked()
{
    if(!p_board)
        return;

    if(!m_active)
        return;

    m_moveCounter++;
    if(m_moveCounter >=5)
    {
        Referee referee;
        QString res = referee.checkWinner(p_board->items());

        if(res == "" && m_moveCounter == 9)
            emit draw();
        else if(res == "x")
        {
            if(p_firstPlayer)
                p_firstPlayer->win();
        }
        else if(res == "o")
        {
            if(p_secondPlayer)
                p_secondPlayer->win();
        }
        else
            this->nextPlayer();
    }
    else
        this->nextPlayer();
}

void Game::setActive(bool a)
{
    if(m_active == a)
        return;

    m_active = a;
    emit activeChanged(a);
}

void Game::on_someoneWon()
{
    this->setActive(false);
}
