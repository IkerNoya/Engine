#include "Game.h"

Game::Game() : Application()
{
}

Game::~Game()
{
}

Division::Application* Division::CreateApplication()
{
	return new Game();
}