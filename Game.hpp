#ifndef GAME_HPP
#define GAME_HPP

#include "World.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Game : private sf::NonCopyable
{
    public:
        Game();
        void run();

    private:
        void processEvents();
        void update(sf::Time elapsedTime);
        void render();
		void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    private:
		static const   sf::Time TimePerFrame;
        RenderWindow   mWindow;
		World          mWorld;
        Font           mFont;
		Text           mStatisticsText;
};

#endif //GAME_HPP
