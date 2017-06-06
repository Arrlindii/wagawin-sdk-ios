//
//  WAGSdkDelegateProtocol.h
//  WagawinSDKLibrary
//
//  Created by Benjamin Baumann on 20/12/2016.
//  Copyright © 2016 Wagawin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WAGAdLoadErrorEnum.h"

/**
 *  The WagawinSDKDelegate receives and handles general SDK callback methods
 */
@protocol WagawinSDKDelegate <NSObject>
@optional
/**
 *  onInitializeFailed
 *  This method gets called when there was a problem with the SDK intialization.
 *
 *  param reason provides information about the reason why the initialization failed (e.g. publisher app key not valid)
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
 *  The zone for which the loading was successful
 */
-(void)onAdLoadSuccess: (NSString*) zone;


/**
 *  onAdLoadFailed
 *  It failed to download an Ad
 */
-(void)onAdLoadFailed:(WAGAdLoadError)error forZone:(NSString*)zone;

@end


@interface WAGSdkDelegateProtocol : NSObject

@end
