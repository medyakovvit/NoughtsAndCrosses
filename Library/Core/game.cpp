#include "game.h"

Game::Game(QObject *parent) : QObject(parent)
{
    p_firstPlayer = new Player("Player 1", this);
    p_secondPlayer = new Player("Player2", this);
    p_firstPlayer->setNextPlayer(p_secondPlayer);
    p_secondPlayer->setNextPlayer(p_firstPlayer);
    p_firstPlayer->setActive(true);
}

void Game::start()
{
    emit started();
}
