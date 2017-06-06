//
//  WAGGameDelegateProtocol.h
//  WagawinSDKLibrary
//
//  Created by Benjamin Baumann on 20/12/2016.
//  Copyright © 2017 Wagawin. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  The WagawinGameDelegate handles and receives callbacks which are generated when an ad was shown
 */
@protocol WagawinGameDelegate <NSObject>
@optional

/**
 *  onAdComplete
 *  The ad was displayed successfully
 *
 *  Fraud Protection
 *  gameId: you can use this Id to verify with our backend that the game was not played more than once
 *  please contact our team to get more information on this topic support@wagawin.com
 */
-(void)onAdComplete:(NSString*)gameId;

/**
 *  onAdError
 *  shit happens
 */
-(void)onAdError;

/**
 *  onAdCancelled
 *  The ad display was cancelled
 */
-(void)onAdCancelled;
@end


@interface WAGGameDelegateProtocol : NSObject

@end
