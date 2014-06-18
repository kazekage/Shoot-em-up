#include "Aircraft.hpp"
#include "TextureHolder.hpp"
#include <iostream>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

using namespace std;

using namespace sf;

Textures::ID toTextureID(Aircraft::Type type)
{
	switch (type)
	{
		case Aircraft::Eagle:
			return Textures::Eagle;

		case Aircraft::Raptor:
			return Textures::Raptor;
	}
	return Textures::Eagle;
}

Aircraft::Aircraft(Type type,const TextureHolder& texture)
:   mtype(type)
,   mSprite(texture.get(toTextureID(mtype)))
{
    FloatRect bounds=mSprite.getLocalBounds();
    mSprite.setOrigin(bounds.width/2.f,bounds.height/2.f);
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}
