#include "TouchScene.hpp"

USING_NS_CC;

Scene* TouchScene::createScene()
{
	auto scene = Scene::create();
	auto layer = TouchScene::create();
	scene->addChild(layer);

	return scene;
}

bool TouchScene::init()
{
	if ( !Layer::init() )
	{
		return false;
	}

	auto sprite = Sprite::create("white.png");
	sprite->setAnchorPoint(Vec2(0.5f, 0.5f));
	sprite->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
		 Director::getInstance()->getVisibleSize().height / 2));
	this->addChild(sprite, 0);

	// Add a "touch" event listener to our sprite
	auto clickListener = EventListenerMouse::create();
	clickListener->onMouseDown = [this, sprite](Event* event) -> bool {
		
		EventMouse* mouseEvent = dynamic_cast<EventMouse*>(event);
			
		cocos2d::Size size = event->getCurrentTarget()->getContentSize();
		cocos2d::Point origin = event->getCurrentTarget()->getPosition();
	
		auto clickLoc = convertToWorldSpace(mouseEvent->getLocation());
		clickLoc.y = cocos2d::Director::getInstance()->getVisibleSize().height - clickLoc.y;

		auto clickRect = DrawNode::create();
		
		Color4F green(0, 1, 0, 1);
		clickRect->drawRect(clickLoc, clickLoc + cocos2d::Vec2(10, 10), green);
		this->addChild(clickRect);
		
		auto bounds = sprite->getBoundingBox();

		if (bounds.containsPoint(clickLoc)){
			ccMessageBox("Touched", "Touched");
		}
		return true;
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(clickListener, this);

	return true;
}
