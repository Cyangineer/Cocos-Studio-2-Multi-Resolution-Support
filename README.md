# Cocos-Studio-2-Multi-Resolution-Support
I explained breifly about how to add multi resolution in your Cocos project here: http://discuss.cocos2d-x.org/t/multi-resolution-support-for-cocos-studio-2-problem-solved-d/21543

There are two places where you need to change your code and that's in the AppDelegate.cpp and your scene.cpp files.

In scene.cpp in scene::init() load the scene using this code:
```
// loads scene file from Cocos Studio and resizes the assets
    auto rootNode = CSLoader :: createNode ("MainScene.csb");
    auto size = Director :: getInstance () -> getVisibleSize ();
    rootNode-> setContentSize (size);
    ui :: Helper :: doLayout (rootNode);
    addChild (rootNode);
```
This aligns and resizes the assets relative to the the device size. I recommend you mainly use this for all the scenes you make in your game.

In the AppDelegate.ccp replace this code:
```
if(!glview){
        glview = GLViewImpl::createWithRect("CocosProject", Rect(0, 0, 640, 960));
        director->setOpenGLView(glview);
    }
    director->getOpenGLView()->setDesignResolutionSize( 640, 960, ResolutionPolicy::NO_BORDER );
```
With this code:
```
auto glview = director->getOpenGLView();
    // set design resolution to same resolution as what you published it in Cocos Studio and use FIXED_WIDTH for landscape & FIXED_HEIGHT for portrait
    glview->setDesignResolutionSize(960,640, ResolutionPolicy::FIXED_WIDTH);
```
When you set the x and y values make sure their the same as the design resolution you published in your Cocos Studio project.

# Android Devices

Whenever you make a new scene file you have to add it in the ```Android.mk``` located in ```ProjectName/proj.android/jni/Android.mk```

If your game is portrait and in the wrong orientation on your android device it might be that the orientation is set to "landscape" in the ```AndroidManifest.xml```. Just change this line ```android:screenOrientation="landscape"``` and you're good. It's located in ```ProjectName/proj.android/AndroidManifest.xml```
