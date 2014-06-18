#ifndef WORLD_HPP
#define WORLD_HPP

#include "TextureHolder.hpp"
#include "Aircraft.hpp"
#include "Scenenode.hpp"
#include <array>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

using namespace sf;

/* Since we have only one world and we dont want it to
get copied so we derive it privately from Nomcopyable */

class World: private NonCopyable
{
    public:
        World(RenderWindow& window);
        void update(Time dt);
        void draw();

    private:
        void loadTexture();
        void buildScene();

    private:
        enum Layer
        {
            Background,
            Air,
            Layercount
        };

    private:
        RenderWindow& mWindow;
        View mWorldView;
        TextureHolder mTextures;
        SceneNode mSceneGraph;
        std::array<SceneNode*, Layercount> mSceneLayers;
        FloatRect mWorldBounds;
        Vector2f mSpawPosition;
        float mScrollSpeed;
        Aircraft* mPlayerAircraft;




};
#endif // WORLD_HPP
