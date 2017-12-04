# wagawin-sdk-ios

WagawinSDK for iOS

[![Version](https://img.shields.io/cocoapods/v/WagawinSDK.svg?style=flat)](http://cocoapods.org/pods/WagawinSDK)
[![License](https://img.shields.io/cocoapods/l/WagawinSDK.svg?style=flat)](http://cocoapods.org/pods/WagawinSDK)
[![Platform](https://img.shields.io/cocoapods/p/WagawinSDK.svg?style=flat)](http://cocoapods.org/pods/WagawinSDK)

## Requirements
The SDK supports iOS 8.0+ and XCode 7.3+

To integrate the SDK and to receive Ads you have to register at our [Admin Center](https://admin.wagawin.com). You will get your AppId adn ZoneId there, which is needed to initialize the SDK.

## Installation

### CocoaPods

WagawinSDK is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod "WagawinSDK" , '~> 2.0.4'
```

Normally you should have to configure building and linking when using CocoaPods. If you run into problems please read the next section.

### Manually

Alternatively, you can download the files manually from the [releases page][releases] and import them into your project by hand.

[releases]: https://github.com/Wagawin/wagawin-sdk-ios/releases

If not already done, you have to add the following linker flag to the Build Settings:
```objc
-ObjC
```

Link your target under *Build Phases* with the following libraries:
```objc
SystemConfiguration.framework
CoreTelephony.framework
libWagawinSDKLibrary.a
```

NOTE: With certain frameworks you may get linker errors. To get rid of the errors you have to add the $(inherited) linker flag and set the "Build active architecture only" flag to NO in the Build Settings

### IMPORTANT:  Allow non secure connections

The App Transport Security system of Apple is a default setting that requires apps to make network connections only over secure connections (SSL) for iOS9+. We are trying to make all of our demand partners compliant as soon as possible. Meanwhile, developers who want to release apps that support iOS9+, will need to disable ATS in order to ensure that Wagawin continues to give them the best possible campaigns:
Info.plist:
```xml
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
</dict>
```
Developers can also edit the plist directly by adding NSAppTransportSecurity key of dictionary type with a dictionary element of NSAllowsArbitraryLoads of boolean type set to Yes.

### IMPORTANT:  Submitting your App to the Appstore (IDFA Advertising Identifier)

When you submit your app to the Appstore, you are asked if you use the IDFA (Advertising Identifier). The Wagawin SDK uses the IDFA to identify the user and to deliver appropriate Ads, **therefore you have to select YES.**

The following things also have to be checked:

- your app uses the IDFA for serving ads
- your app respects "Limit Ad Tracking setting in iOS"

Wagawin currently does not use the IDFA to track the install of the app it is included.

**If you do not respect these points, the Appstore may reject your app.**


## Usage

### Initialization
To import the Wagawin Library, you need to add the following import statement:

```objc
#import "WagawinSDK.h"
```

To initialize the Wagawin in your app, you have to create a WAGOptions object and set the following parameters:

```objc
WAGOptions* options = [WAGOptions new];
options.appId = @"<YOUR APP KEY>";

//set the delegate that receives callbacks here
options.delegate = self;

//set user data
options.age = 20;
options.gender = WAGMale; //or WAGFemale;
options.keywords = @"add comma separated keywords here";

//set the environment your app uses
options.environment = WAGEnvironmentSandbox;

//you can also set the location of you user if you know it. This works also after the SDK was initialized
[WagawinSDK setLocation:[[CLLocation alloc] initWithLatitude:-56.6462520 longitude:-36.6462520]];

//after configuring the SDK you can initialize with this call
[WagawinSDK initWithOptions:options];
```

For testing, please set the environment variable to:
```objc
WAGEnvironmentSandbox
```
When you are done with testing and you want to release your app, please set the environment to:
```objc
WAGEnvironmentProduction
```

### Loading an Ad
You can load ads by calling the following methods (with the zone hash key you can find in the Admin Center):

```objc
//load ads with this call. You can specify for which zone you want to load an ad. You can configure your zones in the admin panel. You can load ads for multiple zones.
[WagawinSDK loadAdWithZone:@"<YOUR ZONE ID 1>"];
[WagawinSDK loadAdWithZone:@"<YOUR ZONE ID 2>"];

```

You should load an ad at least 20 seconds before you want to display it.


### Displaying an ad

Once you reached the point where you want to display an ad, you can check if it's available:
```objc
BOOL adAvailable = [WagawinSDK isAdAvailableForZone:@"<YOUR ZONE ID>"];
```

If an Ad is available for the zone, you can display the ad with the following method:
```objc
// You have to pass a view controller which is used to present the ad. Also you should pass a delegate which implements the WagawinGameDelegate Protocol to determine when the game has ended.
if (adAvailable) {
  [WagawinSDK showAdWithZone:@"<YOUR ZONE ID>" andViewController:self andDelegate:self];
}
```

### Delegate Methods

The Wagawin SDK provides two delegate protocols, which can be used by your App. The first is called WagawinSDKDelegate, which is passed when initializing the app to determine the SDK status:
```objc
id wagawinSdkDelegate = self;
[WagawinSDK initWithAppId:@"<YOUR APP KEY>" andDelegate:wagawinSdkDelegate inEnvironment:WAGEnvironmentSandbox];

//onInitializeFailed is called when a problem with the Wagawin Sdk initialization occurred
-(void)onInitializeFailed:(NSString*)reason

//onInitializeSuccess is called when the Wagawin Sdk has successfully initialized with the Wagawin backend
-(void)onInitializeSuccess;

//onAdLoadSuccess will be called when an ad was successfully downloaded and is ready to be displayed
-(void)onAdLoadSuccess:(NSString*)zone;

//onAdLoadFailed is called when the download for an Ad for a specific zone failed
-(void)onAdLoadFailed:(WAGAdLoadError)error forZone:(NSString*)zone;

```


The second one is the WagawinGameDelegate, which is passed when displaying an ad to receive messages after the ad has been shown:
```objc
[WagawinSDK showAdWithZone:@"<YOUR ZONE ID>" andViewController:self andDelegate:self];

//onAdComplete:(NSString*)gameId; is called then the Wagawin Sdk has finished displaying the ad. The game Id is a unique id for every played game which can be used for fraud protection. Please contact us if you want to know more about this topic.
-(void)onAdComplete:(NSString*)gameId;

//onAdCancelled is called when an ad was cancelled by the user (not implemented yet)
-(void)onAdCancelled;

//onAdError is called when an error happens in the SDK an the app returns without showing the game correctly
-(void)onAdError;
```

## Going into Production

Once you have confirmed that the SDK works and you decided to publish your app, you need to switch to production mode. Just switch from passing `WAGEnvironmentSandbox` to `WAGEnvironmentProduction` in the init call, i.e. `[WagawinSDK initWithAppId:@"<YOUR APP KEY>" andDelegate:wagawinSdkDelegate inEnvironment:WAGEnvironmentProduction];`

NOTE: If your App hasn't been verified yet, you will receive no ads when you are in `PRODUCTION`-mode. You can check your status in the Admin Center.

NOTE: If your app uses its own sound or music, you must ensure that it doesn't play during an Wagawin ad. To do this, you use the callbacks provided by the GameCallbackDelegate protocol to stop your audio when the ad starts and resume your audio when the ad finishes.

NOTE: To support WagawinSDK your app must support at least one portrait and one landscape orientation. Otherwise it may lead to crashes. Your ViewControllers however dont need to support multiple interface orientations.

## Author

Wagawin GmbH, publisher@wagawin.com

## License

Copyright 2017, Wagawin GmbH, all rights reserved

## Changelog
[changelog]: https://github.com/Wagawin/wagawin-sdk-ios/blob/master/Changelog.md
