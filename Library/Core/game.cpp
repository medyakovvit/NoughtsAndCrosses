#include "game.h"

Game::Game(QObject *parent) : QObject(parent)
{

}

void Game::start()
{
    emit started();
}
