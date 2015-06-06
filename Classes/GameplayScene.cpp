#include "GameplayScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameplayScene::createScene(){
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameplayScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameplayScene::init(){
    //////////////////////////////
    // 1. super init first
    if(!Layer::init()){
        return false;
    }
    // Get screen dimensions and points
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    // load scene file from Cocos Studio
    auto rootNode = CSLoader::createNode("GameplayScene.csb");
    rootNode->setContentSize(visibleSize);
    ui:: Helper :: doLayout(rootNode);
    addChild(rootNode);
    
    // Get touch events
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(GameplayScene::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(GameplayScene::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(GameplayScene::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    /*// Get multi touch events
    auto touchesListener = EventListenerTouchAllAtOnce::create();
    touchesListener->onTouchesBegan = CC_CALLBACK_2(GameplayScene::onTouchesBegan, this);
    touchesListener->onTouchesMoved = CC_CALLBACK_2(GameplayScene::onTouchesMoved, this);
    touchesListener->onTouchesEnded = CC_CALLBACK_2(GameplayScene::onTouchesEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchesListener, this);*/
    
    return true;
}

// Single touch methods
bool GameplayScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event){
    CCLOG("onTouchBegan x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
    
    return true;
}

void GameplayScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event){
     CCLOG("onTouchMoved x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
}

void GameplayScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event){
    CCLOG("onTouchEnded x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
}

/*//Multi touches methods
void GameplayScene::onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event){
    CCLOG("MULTI TOUCH BEGAN");
}

void GameplayScene::onTouchesMoved(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event){
    CCLOG("MULTI TOUCHES HAVE MOVED");
}

void GameplayScene::onTouchesEnded(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event){
    CCLOG("MULTI TOUCHES HAVE ENDED");
}*/