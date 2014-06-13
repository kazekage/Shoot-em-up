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

namespace Texture
{
    enum ID
    {
        Landscape,
        Airplane,
        Missile
    };
}
class TextureHolder
{
    public:
        TextureHolder();

    public:
        void load(Texture::ID id,const string& filename);
        sf::Texture& get(Texture::ID id);
        const sf::Texture& get(Texture::ID id) const;

    private:
        map<Texture::ID,unique_ptr<sf::Texture>> mTexturemap;


};

#endif // TEXTUREHOLDER_HPP
