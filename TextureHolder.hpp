#ifndef TEXTUREHOLDER_HPP
#define TEXTUREHOLDER_HPP

#include<SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

using namespace std;
using namespace sf;

namespace Textures
{
    enum ID
    {
        Eagle,
        Raptor,
        Desert
    };
}
class TextureHolder
{
    public:
        TextureHolder();

    public:
        void load(Textures::ID id,const string& filename);
        sf::Texture& get(Textures::ID id);
        const sf::Texture& get(Textures::ID id) const;

    private:
        map<Textures::ID,unique_ptr<sf::Texture>> mTexturemap;


};

#endif // TEXTUREHOLDER_HPP

