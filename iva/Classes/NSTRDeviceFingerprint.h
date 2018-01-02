//
//  NSTRDeviceFingerprint.h
//  IVA-IOS-SDK
//
//  Created by kevin on 12/14/17.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AFNetworking/AFNetworking.h>
#import <PromiseKit/PromiseKit.h>
#import "SimilityBeacon.h"

@interface NSTRDeviceFingerprint : NSObject

- (id)init;
- (void) start;

@property(nonatomic, retain) SimilityContext* context;

@end
