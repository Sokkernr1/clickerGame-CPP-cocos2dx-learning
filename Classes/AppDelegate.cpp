#include "AppDelegate.hpp"
#include "TouchScene.hpp"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() {
}

bool AppDelegate::applicationDidFinishLaunching() {
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if(!glview) {
		glview = GLViewImpl::createWithFullScreen("Clicker game");
		glview->setDesignResolutionSize(1280, 720, ResolutionPolicy::FIXED_WIDTH);
		director->setOpenGLView(glview);
	}
	
	auto scene = TouchScene::createScene();
	director->runWithScene(scene);

	return true;
}

void AppDelegate::applicationDidEnterBackground() {
}

void AppDelegate::applicationWillEnterForeground() {
}
