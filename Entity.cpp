#include "Entity.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

void Entity::SetVelocity(Vector2f velocity)
{
    mVelocity=velocity;
}
void Entity::SetVelocity(float vx,float vy)
{
    mVelocity.x=vx;
    mVelocity.y=vy;
}
sf::Vector2f Entity::getVelocity() const
{
    return mVelocity;
}

void Entity::updateCurrent(sf::Time dt)
{
	move(mVelocity * dt.asSeconds());
}
