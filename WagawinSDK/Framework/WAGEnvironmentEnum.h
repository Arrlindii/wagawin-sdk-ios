//
//  WAGEnvironment.h
//  WagawinSDKLibrary
//
//  Created by Benjamin Baumann on 24/04/2017.
//  Copyright © 2017 Wagawin. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum WAGEnvironment : NSUInteger {
    WAGEnvironmentSandbox = 0,
    WAGEnvironmentProduction = 1,
}WAGEnvironment;

@interface WAGEnvironmentEnum : NSObject

@end
