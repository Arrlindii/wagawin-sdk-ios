//
//  WAGViewController.m
//  WagawinSDK
//
//  Created by Benjamin Baumann on 06/22/2016.
//  Copyright (c) 2016 Benjamin Baumann. All rights reserved.
//

#import "WAGViewController.h"
#import "WagawinSDK.h"

@interface WAGViewController ()<WagawinSDKDelegate,WagawinSDKGameCallbackDelegate>

@end

@implementation WAGViewController{
    
    UIButton* playAdButton;
    
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    
    
    /**
     * BASIC INITIALIZATION OF SDK
     * INIT WITH METHOD AND PARAMETERS
     */
    // Do any additional setup after loading the view, typically from a nib.
    [WagawinSDK initWithAppId:@"<# your app id#>" andDelegate:self inEnvironment:WAGEnvironmentSandbox];
    
    
    
    /** 
     *  BASIC INITIALIZATION OF THE SDK
     *  INIT WITH OPTIONS OBJECT
     */
    //create object and set values
//    WAGSDKOptions* options = [WAGSDKOptions new];
//    options.appId = @"<# your app id#>";
//    options.delegate = self;
//    options.environment = WAGEnvironmentSandbox;
//    [WagawinSDK initWithOptions:options];

    
    [self createPlayButton];
}

-(void)createPlayButton{
    playAdButton = [[UIButton alloc] initWithFrame:CGRectMake(self.view.frame.size.width/2, self.view.frame.size.height/2, 200, 100)];
    [self.view addSubview:playAdButton];
    [playAdButton setTitle:@"Play ad" forState:UIControlStateNormal];
    [playAdButton setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    
    if (![WagawinSDK isAdAvailable]) {
        playAdButton.hidden = YES;
    }
    
    [playAdButton addTarget:self action:@selector(playAd) forControlEvents:UIControlEventTouchUpInside];
}

-(void)playAd{
    [WagawinSDK showAdWithViewController:self andDelegate:self];
    
/*   Presentation without delegate but with Blocks
    
    [WagawinSDK showAdGameWithViewController:self completionBlock:^{
        
    } cancelBlock:^{
        
    }];
 */
    
}

//delegate callbacks
-(void)onInitializeFailed:(NSString*)reason{
    

}
-(void)onInitializeSuccess{

}

-(void)onAdLoadSuccess{
    playAdButton.hidden = NO;
    
}

-(void)onAdLoadFailed:(NSString*)reason{

}

-(void)onAdComplete{
    playAdButton.hidden = YES;
}

-(void)onAdCancelled{
    playAdButton.hidden = YES;
}



@end
