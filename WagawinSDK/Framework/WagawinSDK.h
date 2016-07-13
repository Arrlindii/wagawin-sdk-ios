//
//  WagawinSDK.h
//  WagawinSDK
//
//  Created by Wagawin GmbH on 08/12/15.
//  Copyright © 2015 Wagawin GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WAGSDKOptions.h"

/**
 WAGEnvironment
 The enum declares in which mode the SDK runs. WAGEnvironmentSandbox is for testing, WAGEnvironmentProduction is for the productive version
 */
typedef enum WAGEnvironment : NSUInteger {
    WAGEnvironmentSandbox = 0,
    WAGEnvironmentProduction = 1
}WAGEnvironment;

/**
 *  The WagawinSDKDelegate receives and handles general SDK callback methods
 */
@protocol WagawinSDKDelegate <NSObject>
@optional
/**
 *  onInitializeFailed
 *  This method gets called when there was a problem with the SDK intialization.
 *
 *  @param reason provides information about the reason why the initialization failed (e.g. publisher app key not valid)
 */
-(void)onInitializeFailed:(NSString*)reason;

/**
 *  onInitializeSuccess
 *  The initialization was successful, the SDK can now download ads
 */
-(void)onInitializeSuccess;

/**
 *  onAdLoadSuccess
 *  The SDK successfully downloaded an ad which is now ready for display
 */
-(void)onAdLoadSuccess;
@end


/**
 *  The WagawinSDKGameCallbackDelegate handles and receives callbacks which are generated when an ad was shown
 */
@protocol WagawinSDKGameCallbackDelegate <NSObject>
@optional

/**
 *  onAdComplete
 *  The ad was displayed successfully
 */
-(void)onAdComplete;

/**
 *  onAdCancelled
 *  The ad display was cancelled
 */
-(void)onAdCancelled;
@end


@interface WagawinSDK : NSObject

/**
 *  Basic initializing of SDK
 *
 *  @param options Create a WAGSDKOptions object and set the values
 */
+(void)initWithOptions:(WAGSDKOptions*)options;


/**
*  Basic initializing of SDK with WagawinSDKDelegate
*
*  @param appId       The app Id which is provided by Wagawin. You can find it in the admin panel
*  @param delegate    The delegate object which handles callbacks of the WagawinSDKDelegate protocol
*  @param environment Environment variable which defines Sandbox or Production mode
*/
+(void)initWithAppId:(NSString*)appId andDelegate:(id)delegate inEnvironment:(WAGEnvironment)environment;


/**
 *  Display the game ontop of the view controller with the WagawinSDKGameCallbackDelegate
 *
 *  @param viewController The view controller which should display the Ad (should always be the topmost viewcontroller, otherwise the display may fail)
 *  @param delegate       The delegate object which handles callbacks of the WagawinSDKGameCallbackDelegate protocol
 */
+(void)showAdWithViewController:(UIViewController*)viewController andDelegate:(id)delegate;


/**
 *  Display the game ontop of the view controller with completion and cancel block (only one of them is called)
 *
 *  @param viewController  The view controller which should display the Ad (should always be the topmost viewcontroller, otherwise the display may fail)
 *  @param completionBlock will be called when the ad was shown successfully (equivalent to the onAdComplete callback method)
 *  @param cancelBlock     will be called when the ad was cancelled (equivalent to the onAdCancelled callback method)
 */
+(void)showAdGameWithViewController:(UIViewController*)viewController completionBlock:(void (^)(void))completionBlock cancelBlock:(void (^)(void))cancelBlock;


/***
 *  Check if a game is ready for presenting
 *
 *  @return YES if an ad is ready to be presented, NO if there is no ad ready
 */
+(BOOL)isAdAvailable;




@end
