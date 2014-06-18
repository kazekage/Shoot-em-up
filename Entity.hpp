#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Scenenode.hpp"
using namespace std;

using namespace sf;

class Entity : public SceneNode
{

    private:
		virtual void updateCurrent(sf::Time dt);

    public:
        void SetVelocity(sf::Vector2f velocity);
        void SetVelocity(float vx,float vy);
        sf::Vector2f getVelocity() const;

    private:
        sf::Vector2f mVelocity;
};


#endif // ENTITY_HPP
