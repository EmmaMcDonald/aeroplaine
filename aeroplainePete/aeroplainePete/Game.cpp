/// <summary>
/// @author Emma McDonald
/// @date wed-26-jan-2022
///
/// you need to change the above lines or lose marks
/// </summary>

#include "Game.h"
#include <iostream>



/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800U, 600U, 32U }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{

	setupSprite(); // load texture
	background();


}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	
	
	m_window.draw(m_skySprite);
	m_window.draw(m_smallPlaneSprite);
	m_window.display();
}



/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	if ( !m_planeTexture.loadFromFile("assets\\images\\planes.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading plane" << std::endl;
	}
	// get sprite to use texture
	m_smallPlaneSprite.setTexture(m_planeTexture);
	// get sprite to use small part of texture
	m_smallPlaneSprite.setTextureRect(sf::IntRect(362,212, 115, 85));
	// set sprite to desired location on screen
	m_smallPlaneSprite.setPosition(400.0f, 300.0f);
	// set origin of sprite to middle
	m_smallPlaneSprite.setOrigin(57.5f,42.5f);
	// set rotation to default 0
	m_smallPlaneSprite.setRotation(45.0f);
	// set scale to default 1:1
	m_smallPlaneSprite.setScale(2.0f, 2.0f);	
	// set opacity to default 255
	m_smallPlaneSprite.setColor(sf::Color{ 255,255,255,160 });

}

void Game::background()
{
	if (!m_skyTexture.loadFromFile("assets\\images\\sky.jpg"))
	{
		//message if sky fails to load
		std::cout << "problem loading sky" << std::endl;
	}
	m_skySprite.setTexture(m_skyTexture);
	//m_skySprite.setTextureRect(sf::IntRect(362, 212, 115, 85));
	m_skySprite.setPosition(0.0f, 0.0f);
	m_skyTexture.setRepeated(true);
	m_skySprite.setTextureRect(sf::IntRect(0, 0, WIDTH, HEIGHT));
}
