#include "GraphicsScene.hpp"

USING_NS_CC;

Scene* GraphicsScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GraphicsScene::create();
	scene->addChild(layer);

	return scene;
}

bool GraphicsScene::init()
{
	if ( !Layer::init() )
	{
		return false;
	}

	auto sprite = Sprite::create("decepticon.png");
	sprite->setPosition(getContentSize().width / 2 - sprite->getContentSize().width / 2, getContentSize().height / 2 - sprite->getContentSize().height / 2);
	sprite->setAnchorPoint(Vec2(0, 0));
	
	this->addChild(sprite, 0);

	return true;
}
