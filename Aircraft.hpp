#ifndef AIRCRAFT_HPP
#define AIRCRAFT_HPP
#include "TextureHolder.hpp"
#include "Entity.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

using namespace sf;

class Aircraft : public Entity
{
    public:
        enum Type
        {
            Eagle,
            Raptor
        };

    public:
        Aircraft(Type type,const TextureHolder& texture);

    private:
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        Type mtype;
        Sprite mSprite;
};
#endif // AIRCRAFT_HPP
