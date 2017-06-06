//
//  WAGOptions.h
//  WagawinSDKLibrary
//
//  Created by Benjamin Baumann on 16/12/2016.
//  Copyright © 2016 Wagawin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WAGGenderEnum.h"

@interface WAGOptions : NSObject

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
 *  Set Targeting Criteria
 */
@property (nonatomic, assign) WAGGender gender;

@property (nonatomic, strong) NSString* keywords;

@property (nonatomic, assign) NSInteger maxAge;

@property (nonatomic, assign) NSInteger minAge;

@property (nonatomic, assign) NSInteger age;

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
