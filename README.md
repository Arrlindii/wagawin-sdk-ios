# wagawin-sdk-ios
WagawinSDK for iOS

[![Version](https://img.shields.io/cocoapods/v/WagawinSDK.svg?style=flat)](http://cocoapods.org/pods/WagawinSDK)
[![License](https://img.shields.io/cocoapods/l/WagawinSDK.svg?style=flat)](http://cocoapods.org/pods/WagawinSDK)
[![Platform](https://img.shields.io/cocoapods/p/WagawinSDK.svg?style=flat)](http://cocoapods.org/pods/WagawinSDK)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements
The Sdk supports iOS 7.1+ and XCode 7.3+

## Installation

WagawinSDK is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod "WagawinSDK" , '~> 1.3.4'
```

Alternatively you can download the files manually from the [releases page][releases] and import them into your project by hand.

The footprint of your final app will increase by ~1 MB

[releases]: https://github.com/Wagawin/wagawin-sdk-ios/releases

## Integration

If not already done you have to add the following linker flag to the Build Settings
```objc
-ObjC
```


Link your target under Build Phases with the following libraries
```objc
SystemConfiguration.framework
CoreTelephony.framework
libWagawinSDKLibrary.a
```


To enable the downloading of Ad media from different sources you have to add the following code to you Info.plist
```xml
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
</dict>
```



####**Important:  Submitting your App to the Appstore (IDFA Advertising Identifier)**

When you submit your app to the Appstore you are asked if you use the IDFA (Advertising Identifier). The Wagawin SDK uses the IDFA to identify the user and to serve appropriate Ads, **therefore you have to select YES**

The following things also have to be checked:

- your app uses the IDFA for serving ads
- your app respects "Limit Ad Tracking setting in iOS"

Wagawin currently does not use the IDFA to track the install of the app it is included.

**If you do not respect these points your app may be rejected by the Appstore.**


## Usage

### Initialization
To import the Wagawin Library you need to set the following import statement.

```objc
#import "WagawinSDK.h"
```


To initialize your app with the Wagawin Ad network you have to call the initWithAppId method. You can optionally pass a delegate to receive callbacks from inside the SDK. You can get your App Key from the Wagawin Admin Panel.
```objc
id wagawinSdkDelegate = self;
 [WagawinSDK initWithAppId:@"<YOUR APP KEY>" andDelegate:wagawinSdkDelegate inEnvironment:WAGEnvironmentSandbox];
```

For testing please set the environment variable to 
```objc
  WAGEnvironmentSandbox
```
When your are done with testing and you want to release your app please set the environment to
```objc
  WAGEnvironmentProduction
```



### Displaying an Ad

Once you reached the point where you want to display the ad you can check if it's available
```objc
  BOOL adAvailable = [WagawinSDK isAdAvailable];
```

If an Ad is availabe you can display the ad with the following methods:
```objc
  if (adAvailable) {
     [WagawinSDK showAdGameWithViewController:self completionBlock:^{
            //this block will be called when Wagawin Sdk has finished displaying the Ad
     } cancelBlock:^{
 
     }];
}
```

or

```objc
//if you do not want to use the block interface for game callback handling 
//you can use the WagawinSDKGameCallbackDelegate which is passed when you start a game with
id gameCallbackDelegate = self;
UIViewController* viewControllerForPresenting = self;
 
[WagawinSDK showAdWithViewController:viewControllerForPresenting andDelegate:gameCallbackDelegate];
```

### Delegate Methods

The Wagawin SDK provides two delegate protocols which can be used by your App. The first is called WagawinSDKDelegate, which is passed when initializing the app to determine the SDK status.
```objc
id wagawinSdkDelegate = self;
[WagawinSDK initWithAppId:@"<YOUR APP KEY>" andDelegate:wagawinSdkDelegate inEnvironment:WAGEnvironmentSandbox];

//onInitializeFailed is called when a problem with the Wagawin Sdk initialization occurred
-(void)onInitializeFailed:(NSString*)reason
 
//onInitializeSuccess is called when the Wagawin Sdk has successfully initialized with the Wagawin backend
-(void)onInitializeSuccess;
 
//onAdLoadSuccess will be called when an ad was successfully downloaded and is ready to be displayed
-(void)onAdLoadSuccess;
```


The second one is the GameCallbackDelegate, which is passed when displaying an Ad to receive messages when the Ad display is finished
```objc
[WagawinSDK showAdWithViewController:viewControllerForPresenting andDelegate:gameCallbackDelegate];

//onAdComplete is called then the Wagawin Sdk has finished displaying the ad
-(void)onAdComplete;
 
//onAdCancelled is called when an ad was cancelled by the user (not implemented yet)
-(void)onAdCancelled;
 
```

##Going into Production

Once you have confirmed that the SDK works and you have decided to publish your App, you need to switch to Production mode. Just switch from passing `WAGEnvironmentSandbox` to `WAGEnvironmentProduction` in the init call, i.e. `[WagawinSDK initWithAppId:@"<YOUR APP KEY>" andDelegate:wagawinSdkDelegate inEnvironment:WAGEnvironmentProduction];`

NOTE: If your App hasn't been verified yet, you will recieve no ads when you are in `PRODUCTION`-mode. You can check your status in the [Admin Panel](https://wap-admin.wagawin.de)


## Author

Wagawin GmbH, publisher@wagawin.com

## License

Copyright 2016, Wagawin GmbH, all rights reserved

## Changelog
[changelog.md][changelog]
[changelog]: https://github.com/Wagawin/wagawin-sdk-ios/blob/master/Changelog.md
