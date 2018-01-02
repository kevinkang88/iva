//
//  NSTRNeustarIVA.h
//  IVA-IOS-SDK
//
//  Created by kevin on 11/29/17.
//  Copyright © 2017 yooniverse. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AFNetworking/AFNetworking.h>
#import <PromiseKit/PromiseKit.h> 
#import <CoreTelephony/CTCarrier.h>
#import "NSTRIPFinder.h"
#import <OHHTTPStubs/OHHTTPStubs.h>
#import <OHHTTPStubs/OHHTTPStubsResponse+JSON.h>
#import "NSTREnrichedHeaders.h"

@interface NSTRNeustarIVA : NSObject

- (id)initWithDeviceId:(NSString *)deviceId;
- (AnyPromise *) getCarrier:(NSString *)ipAddr;
- (void) startWithCompletion:(void(^)(NSTREnrichedHeaders *header, NSError *error))completionBlock;

@property(nonatomic, retain) NSString* deviceId;
@property(nonatomic, retain) NSString* applicationId;
@property(nonatomic, retain) NSNumber* requestId;
       
@end

