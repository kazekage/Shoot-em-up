#include "World.hpp"
#include <iostream>
#include <string>
#include  <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "TextureHolder.hpp"
#include "SpriteNode.hpp"

using namespace std;

using namespace sf;

World::World(RenderWindow& window)
:   mWindow(window)
,   mWorldView(window.getDefaultView())
,   mTextures()
,   mSceneGraph()
,   mSceneLayers()
,   mWorldBounds(
                    0.f,                    //Left
                    0.f,                    //Top
                    mWorldView.getSize().x,   //Width
                    2000.f                  //Height
                )
,   mSpawPosition(mWorldView.getSize().x/2.f,mWorldBounds.height-mWorldView.getSize().y/2.f)

,   mScrollSpeed(-50.f)         //Here the speed is -ve because y axis is facing in downward direction

,   mPlayerAircraft(nullptr)
{
    loadTexture();
    buildScene();
    mWorldView.setCenter(mSpawPosition);
}

void World::loadTexture()
{
    mTextures.load(Textures::Eagle  ,"C:/Users/Siddhant/Desktop/Eagle.png");
    mTextures.load(Textures::Raptor ,"C:/Users/Siddhant/Desktop/Raptor.png");
    mTextures.load(Textures::Desert ,"C:/Users/Siddhant/Desktop/Desert.png");
}

void World::buildScene()
{
    // Initialize the different layers
	for (int i = 0; i < Layercount; ++i)
	{
		unique_ptr<SceneNode> layer(new SceneNode());
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}

	Texture& textures=mTextures.get(Textures::Desert);
	textures.setRepeated(true);

	IntRect textureRect(mWorldBounds);

	unique_ptr<SpriteNode> BackGroundSprite(new SpriteNode(textures,textureRect));

	BackGroundSprite->setPosition(mWorldBounds.left,mWorldBounds.top);
	mSceneLayers[Background]->attachChild(std::move(BackGroundSprite));

	unique_ptr<Aircraft> leader(new Aircraft(Aircraft::Eagle,mTextures));
	mPlayerAircraft=leader.get();
	mPlayerAircraft->setPosition(mSpawPosition);
	mPlayerAircraft->SetVelocity(40.f,mScrollSpeed);
	mSceneLayers[Air]->attachChild(std::move(leader));

	unique_ptr<Aircraft> leftEscort(new Aircraft(Aircraft::Raptor,mTextures));
	leftEscort->setPosition(-80.f,50.f);
	mPlayerAircraft->attachChild(std::move(leftEscort));

	std::unique_ptr<Aircraft> rightEscort(new Aircraft(Aircraft::Raptor, mTextures));
	rightEscort->setPosition(80.f, 50.f);
	mPlayerAircraft->attachChild(std::move(rightEscort));

}

void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}

void World::update(sf::Time dt)
{
	// Scroll the world
	mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());

	// Move the player sidewards (plane scouts follow the main aircraft)
	sf::Vector2f position = mPlayerAircraft->getPosition();
	sf::Vector2f velocity = mPlayerAircraft->getVelocity();

	// If player touches borders, flip its X velocity
	if (position.x <= mWorldBounds.left + 150.f
	 || position.x >= mWorldBounds.left + mWorldBounds.width - 150.f)
	{
		velocity.x = -velocity.x;
		mPlayerAircraft->SetVelocity(velocity);
	}

	// Apply movements
	mSceneGraph.update(dt);
}

