//
//  WAGAdLoadErrorEnum.h
//  WagawinSDKLibrary
//
//  Created by Benjamin Baumann on 20/12/2016.
//  Copyright © 2016 Wagawin. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 WAGAdLoadError
 If the AdLoadFailed is called the reason will be a WAGAdLoadError
 */
typedef enum WAGAdLoadError : NSUInteger {
    WAGNoError = 0,
    WAGNoConnection = 1,
    WAGNoAdAvailable = 2,
    WAGNotInitialized = 3,
    WAGUnknownError = 4
}WAGAdLoadError;

@interface WAGAdLoadErrorEnum : NSObject

@end
