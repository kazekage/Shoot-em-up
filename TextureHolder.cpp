#include "TextureHolder.hpp"

#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>
#include <iostream>

using namespace std;
using namespace sf;

TextureHolder::TextureHolder()
{

}

void TextureHolder::load(Texture::ID id,const string& filename)
{
    unique_ptr<sf::Texture> texture(new sf::Texture);
	if (!texture->loadFromFile(filename))
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

	// If loading successful, insert resource to map
	auto inserted=mTexturemap.insert(make_pair(id,move(texture)));

	assert(inserted.second);

}

sf::Texture& TextureHolder::get(Texture::ID id)
{
    auto found = mTexturemap.find(id);
	assert(found != mTexturemap.end());

	return *found->second;
}

const sf::Texture& TextureHolder::get(Texture::ID id) const
{
    auto found = mTexturemap.find(id);
	assert(found != mTexturemap.end());

	return *found->second;
}

