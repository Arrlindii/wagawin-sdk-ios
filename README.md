# wagawin-sdk-ios

WagawinSDK for iOS

[![Version](https://img.shields.io/cocoapods/v/WagawinSDK.svg?style=flat)](http://cocoapods.org/pods/WagawinSDK)
[![License](https://img.shields.io/cocoapods/l/WagawinSDK.svg?style=flat)](http://cocoapods.org/pods/WagawinSDK)
[![Platform](https://img.shields.io/cocoapods/p/WagawinSDK.svg?style=flat)](http://cocoapods.org/pods/WagawinSDK)

## Requirements
The SDK supports iOS 8.0+

### Register your Application
In order to use the Wagawin SDK you have to complete the following steps:
* Create your account at the Wagawin [Admin Center](https://de.wagawin.com/admin).
* Create your app.
* Create your zone and copy the id for that zone.
* Go to your app, there you can find your Wagawin App ID which you will need to use in the integration code.


## Installation

### CocoaPods

WagawinSDK is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod "WagawinSDK" , '~> 3.0.262'
```

### IMPORTANT:  Submitting your App to the Appstore (IDFA Advertising Identifier)

When you submit your app to the Appstore, you are asked if you use the IDFA (Advertising Identifier). The Wagawin SDK uses the IDFA to identify the user and to deliver appropriate Ads, **therefore you have to select YES.**

The following things also have to be checked:

- your app uses the IDFA for serving ads
- your app respects "Limit Ad Tracking setting in iOS"


**If you do not respect these points, the Appstore may reject your app.**


## Usage

### Initialization
To import the WagawinSDK module, you need to add the following import statement:

```swift
import WagawinSDK
```

To initialize the WagawinSDK in your app, you have to call the static initialize function with following parameters:

```swift
do {
    try WAGAdSDK.initialize(appId: "<YOUR APP ID>", environment: WAGEnvironment.sandbox)
} catch WAGSDKError.noAppId {
    print("appId seems to be empty")
} catch {
    print(error)
}
```

For testing, please set the environment parameter to:
```swift
WAGEnvironment.sandbox
```
When you are done with testing and you want to release your app, please set the environment to:
```swift
WAGEnvironment.production
```

### Loading and showing ads
Before you can show an ad to the user, you have to load it. Please be aware that a loaded ad is only valid for some time.
The time an ad is valid is not a fixed value but you should preload/cache ads for no more than a few minutes. 

### Interstitial Placements
You can create an Interstitial Ad using the following code:
```swift
let ad = WAGInterstitialAd(delegate: self)
do {
    try ad.load(zone: "<YOUR INTERSTITIAL ZONE ID>")
} catch WAGSDKError.noZoneId {
     print("zoneId seems to be empty")
} catch WAGAdLoadError.adLoading{
    print("ad already loading")
} catch WAGSDKError.sdkNotInitialized{
    print("WagawinSDK not initialized, call initialize function on WagawinSDK first")
} catch {
    print("ad load call failed")
}
```

You have to provide a delegate that implements the following functions:
```swift
func adLoaded(ad: WAGInterstitialAd) {
    //ad loaded. you can now show it to the user
    do {
        try ad.present(withRootViewController: self)
    } catch {
        print("error presenting interstitial ad ", error)
    }
}

func adFailedToLoad(ad: WAGInterstitialAd) {
    print("failed to load ad")
}
    
func adClosed(ad: WAGInterstitialAd) {
    print("interstitial ad closed")
}
```

Once you reach the point where you want to display the Interstitial Ad, you can check if it's available.
```swift
interstitialAd.isAvailable()
```

### In Feed Placements
You can create an In Feed Ad using the following code:
```swift
let ad = WAGInfeedAdView(frame: CGRect(x: 0, y: 0, width: self.adContainer.frame.width, height: self.adContainer.frame.height), delegate: self)
self.adContainer.addSubview(ad)
let viewsDict = ["view": ad]
self.adContainer.addConstraints(NSLayoutConstraint.constraints(withVisualFormat: "V:|-0-[view]-0-|", options: [NSLayoutFormatOptions.alignAllCenterY], metrics: nil, views: viewsDict))
self.adContainer.addConstraints(NSLayoutConstraint.constraints(withVisualFormat: "H:|-0-[view]-0-|", options: [NSLayoutFormatOptions.alignAllCenterX], metrics: nil, views: viewsDict))
do {
    try ad.load(zone: "<YOUR IN FEED ZONE ID>")
} catch WAGSDKError.noZoneId {
      print("zoneId seems to be empty")
 } catch WAGAdLoadError.adLoading{
    print("ad already loading")
} catch WAGSDKError.sdkNotInitialized{
    print("WagawinSDK not initialized, call initialize function on WagawinSDK first")
} catch {
    print("ad load call failed")
}
```

Like with the Interstitial ads, you have to provide a delegate:
```swift
func adLoaded(ad: WAGInfeedAdView) {
    //ad loaded. you can now show it to the user
    do {
        try ad.showAd()
    } catch {
        print(error)
    }
}

func adFailedToLoad(ad: WAGInfeedAdView) {
    print("failed to load ad")
}

func adClosed(ad: WAGInfeedAdView) {
    ad.removeFromSuperview()
    print("removed ad because it closed")
}
```

Once you reach the point where you want to display the In Feed Ad, you can check if it's available.
```swift
infeedAd.isAvailable()
```
## Going into Production

Once you have confirmed that the SDK works and you decided to publish your app, you need to switch to production mode. Just switch from passing `Environment.sandbox` to `Environment.production` in the initialize call.

NOTE: If your App hasn't been verified yet, you will receive no ads when you are in `PRODUCTION`-mode. You can check your status in the [Admin Center](https://de.wagawin.com/admin).

## Author

Wagawin GmbH, publisher@wagawin.com

## License

Copyright 2018, Wagawin GmbH, all rights reserved

## Changelog
[changelog]: https://github.com/Wagawin/wagawin-sdk-ios/blob/master/Changelog.md
