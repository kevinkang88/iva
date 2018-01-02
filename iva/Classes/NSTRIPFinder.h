//
//  NSTRIPFinder.h
//  IVA-IOS-SDK
//
//  Created by kevin on 11/30/17.
//  Copyright © 2017 yooniverse. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <PromiseKit/PromiseKit.h>

@interface NSTRIPFinder: NSObject

+(AnyPromise *)getPublicIP;

@end
