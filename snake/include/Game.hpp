#pragma once

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

#include "AssetMan.hpp"
#include "StateMan.hpp"

enum AssetID
{
    MAIN_FONT = 0,
    GRASS,
    FOOD,
    WALL,
    SNAKE
};

/*
The Context struct contains three unique pointers: 
m_assets, 
m_states,
m_window.
The Context constructor initializes these pointers by creating new instances of
Engine::AssetMan,
Engine::StateMan,
sf::RenderWindow.
*/
struct Context
{
    std::unique_ptr<Engine::AssetMan> m_assets;
    std::unique_ptr<Engine::StateMan> m_states;
    std::unique_ptr<sf::RenderWindow> m_window;
//*-----------------------------------------------

/*
This code defines a constructor for the Context struct.
It initializes three unique pointers
- m_assets,
- m_states,
- m_window 
By creating new instances of 
- Engine::AssetMan, 
- Engine::StateMan,
- sf::RenderWindow.
*/
    Context()
    {
        m_assets = std::make_unique<Engine::AssetMan>();
        m_states = std::make_unique<Engine::StateMan>();
        m_window = std::make_unique<sf::RenderWindow>();
    }
};

class Game
{
public:
    Game();
    ~Game();

    void Run();

private:
    std::shared_ptr<Context> m_context;
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);
};
