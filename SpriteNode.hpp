/* In order to display our Background sprite through scenegraph
we created a new SceneNode type , the spritenode which act as simple
sprite than can be plugged into out tree structure
we create a spritenode and attach it to our background layer*/

#ifndef SPRITENODE_HPP
#define SPRITENODE_HPP

#include "Scenenode.hpp"

#include <SFML/Graphics/Sprite.hpp>

using namespace std;
using namespace sf;

class SpriteNode : public SceneNode
{
    public:
        explicit SpriteNode(const Texture& texture);
                 SpriteNode(const Texture& texture,const IntRect& textureRect);

    private:
		virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        Sprite mSprite;



};

#endif //SPRITENODE_HPP
