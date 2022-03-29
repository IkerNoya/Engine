#include "Game.h"

Game::Game() : Application(){
	PushOverlay(new Division::GuiLayer);
}

Game::~Game(){
}

Division::Application* Division::CreateApplication(){
	return new Game();
}