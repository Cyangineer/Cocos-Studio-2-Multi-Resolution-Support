#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainScene::createScene(){
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init(){
    //////////////////////////////
    // 1. super init first
    if(!Layer::init()){
        return false;
    }
    
    // loads scene file from Cocos Studio and resizes the assets
    auto rootNode = CSLoader :: createNode ("MainScene.csb");
    auto size = Director :: getInstance () -> getVisibleSize ();
    rootNode-> setContentSize (size);
    ui :: Helper :: doLayout (rootNode);
    addChild (rootNode);
    
    // Get single touch events
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(MainScene::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(MainScene::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(MainScene::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    /*// Get multi touch events
    auto touchesListener = EventListenerTouchAllAtOnce::create();
    touchesListener->onTouchesBegan = CC_CALLBACK_2(MainScene::onTouchesBegan, this);
    touchesListener->onTouchesMoved = CC_CALLBACK_2(MainScene::onTouchesMoved, this);
    touchesListener->onTouchesEnded = CC_CALLBACK_2(MainScene::onTouchesEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchesListener, this);*/
    
    return true;
}

// Single touch methods
bool MainScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event){
    CCLOG("onTouchBegan x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
    return true;
}

void MainScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event){
    CCLOG("onTouchMoved x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
}

void MainScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event){
    CCLOG("onTouchEnded x = %f, y = %f", touch->getLocation().x, touch->getLocation().y);
}

/*//Multi touches methods
void MainScene::onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event){
    CCLOG("MULTI TOUCH BEGAN");
}

void MainScene::onTouchesMoved(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event){
    CCLOG("MULTI TOUCHES HAVE MOVED");
}

void MainScene::onTouchesEnded(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *event){
    CCLOG("MULTI TOUCHES HAVE ENDED");
}*/
