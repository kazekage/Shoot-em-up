#include "Scenenode.hpp"
#include "SpriteNode.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

SpriteNode::SpriteNode(const Texture& texture)
:   mSprite(texture)
{

}
 SpriteNode::SpriteNode(const Texture& texture,const IntRect& textureRect)
 :  mSprite(texture,textureRect)
 {

 }
void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}
