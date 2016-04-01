#include "game.h"

Game::Game(QObject *parent) : QObject(parent)
{
    p_board = new BoardModel(this);

    p_firstPlayer = new Player("x", "Player 1", p_board, this);
    p_activePlayer = p_firstPlayer;
    p_secondPlayer = new Player("o", "Player2", p_board, this);

    connect(p_firstPlayer, &Player::marked, this, &Game::on_activePlayerMarked);
    connect(p_secondPlayer, &Player::marked, this, &Game::on_activePlayerMarked);

    p_firstPlayer->setNextPlayer(p_secondPlayer);
    p_secondPlayer->setNextPlayer(p_firstPlayer);
    p_firstPlayer->setActive(true);
}

void Game::start()
{
    emit started();
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
    this->nextPlayer();
}
