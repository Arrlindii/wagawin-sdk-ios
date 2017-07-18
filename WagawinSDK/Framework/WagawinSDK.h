//
//  WagawinSDK.h
//  WagawinSDKLibrary
//
//  Created by Benjamin Baumann on 16/12/2016.
//  Copyright © 2016 Wagawin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WAGOptions.h"
#import "WAGSdkDelegateProtocol.h"
#import "WAGGameDelegateProtocol.h"
#import "WAGAdLoadErrorEnum.h"
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "WAGGenderEnum.h"
#import "WAGEnvironmentEnum.h"

@interface WagawinSDK : NSObject

//init with options
+(void)initWithOptions:(WAGOptions *)options;

//load ad with zone
+(void)loadAdWithZone:(NSString*)zone;

//show ad with zone
+(void)showAdWithZone:(NSString*)zone andViewController:(UIViewController*)viewController andDelegate:(id)delegate;

//is ad available for zone
+(BOOL)isAdAvailableForZone:(NSString*)zone;

//set location
+(void)setLocation:(CLLocation*)loc;

+(void)loadAdWithZone:(NSString*)zone andType:(NSString*)gameType;
@end
