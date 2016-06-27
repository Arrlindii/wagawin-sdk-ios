//
//  WagawinSDK.h
//  WagawinSDK
//
//  Created by Benjamin Baumann on 08/12/15.
//  Copyright © 2015 Benjamin Baumann. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@protocol WagawinSDKDelegate <NSObject>

typedef enum WAGEnvironment : NSUInteger {
    WAGEnvironmentSandbox = 0,
    WAGEnvironmentProduction = 1
}WAGEnvironment;

@optional
-(void)onInitializeFailed:(NSString*)reason;
-(void)onInitializeSuccess;
-(void)onAdLoadSuccess;
@end

@protocol WagawinSDKGameCallbackDelegate <NSObject>

@optional
-(void)onAdComplete;
-(void)onAdCancelled;
@end


@interface WagawinSDK : NSObject

/**
 *  Basic initializing of SDK with WagawinSDKDelegate
 */
+(void)initWithAppId:(NSString*)appId andDelegate:(id)delegate inEnvironment:(WAGEnvironment)environment;

/**
 *  Display the game ontop of the view controller with the WagawinSDKGameCallbackDelegate
 */
+(void)showAdWithViewController:(UIViewController*)viewController andDelegate:(id)delegate;

/**
 *  Display the game ontop of the view controller with completion and cancel block (only one of them is called)
 */
+(void)showAdGameWithViewController:(UIViewController*)viewController completionBlock:(void (^)(void))completionBlock cancelBlock:(void (^)(void))cancelBlock;

/**
 *  Check if a game is ready for presenting
 */
+(BOOL)isAdAvailable;

@end
