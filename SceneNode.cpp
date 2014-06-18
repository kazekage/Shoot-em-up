#include "Scenenode.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <algorithm>
#include <cassert>
#include <vector>
#include <memory>

using namespace std;

using namespace sf;

SceneNode::SceneNode()
:   mChildren()
,   mParent(nullptr)
{

}

void SceneNode::attachChild(Ptr child)
{
    child->mParent=this;
    mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
    auto found = std::find_if(mChildren.begin(), mChildren.end(), [&] (Ptr& p) { return p.get() == &node; });
	assert(found != mChildren.end());

	Ptr result =std::move(*found);
	result->mParent=nullptr;
	mChildren.erase(found);
	return result;
}

void SceneNode::update(sf::Time dt)
{
    updateCurrent(dt);
    updateChildren(dt);
}
void SceneNode::updateCurrent(sf::Time dt)
{

}
void SceneNode::updateChildren(sf::Time dt)
{
    for(auto it=mChildren.begin();it!=mChildren.end();++it)
    {
        (*it)->update(dt);
    }
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Apply transform of current node
	states.transform *= getTransform();

	// Draw node and children with changed transform
	drawCurrent(target, states);
	drawChildren(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget&, sf::RenderStates) const
{
	// Do nothing by default
}

void SceneNode::drawChildren(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(auto it=mChildren.begin();it!=mChildren.end();++it)
    {
        (*it)->draw(target,states);
    }
}
