//
//  WAGSDKOptions.h
//  WagawinSDKLibrary
//
//  Created by Benjamin Baumann on 11/07/16.
//  Copyright © 2016 Wagawin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WAGSDKOptions : NSObject


/**
 *  The app Id which is provided by Wagawin. You can find it in the admin panel
 */
@property (atomic, strong) NSString* appId;

/**
 *  Defines if there is a close button in the introduction screens of the games
 */
@property (nonatomic,assign) BOOL introSkippable;

/**
 *  Defines if there is a close button during the games
 */
@property (nonatomic,assign) BOOL gamesSkippable;


/**
 *  The delegate object which handles callbacks of the WagawinSDKDelegate protocol
 */
@property (nonatomic,assign) id delegate;

/**
 *
 *  WAGEnvironment
 *  The enum declares in which mode the SDK runs. WAGEnvironmentSandbox is for testing, WAGEnvironmentProduction is for the productive version
 *      WAGEnvironmentSandbox = 0,
 *      WAGEnvironmentProduction = 1
 */
@property (nonatomic,assign) int environment;

@end


