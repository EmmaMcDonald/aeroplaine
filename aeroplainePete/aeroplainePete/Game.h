/// @author Emma McDonald
/// @date wed-26-jan-2022
/// you need to change the above line or lose marks
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>

const int HEIGHT = 800;
const int WIDTH = 1000;

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	

	void setupSprite();
	void background();
	

	sf::RenderWindow m_window; // main SFML window
	sf::Texture m_planeTexture;// texture for all planes
	sf::Sprite m_smallPlaneSprite;// sprite for small plane
	bool m_exitGame; // control exiting game

	sf::Texture m_skyTexture;//background texture
	sf::Sprite m_skySprite;//sprite for background

};

#endif // !GAME_HPP

