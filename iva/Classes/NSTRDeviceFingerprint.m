//
//  NSTRDeviceFingerprint.m
//  IVA-IOS-SDK
//
//  Created by kevin on 12/14/17.
//

#import <Foundation/Foundation.h>
#import "NSTRDeviceFingerprint.h"

@implementation NSTRDeviceFingerprint

- (id)init {
    if(self = [super init]) {
        self.context = [[SimilityContext alloc] init];
        [self.context setCustomerId:@"neustarpoc"];
        [self.context setSessionId:@"ky6svk96e5a4a3f57e83f234gsvf"];
        [self.context setUserId:@"87839ed9-6e5a-4fc4-a3f5-7e837607660b"];
        [self.context setEventTypes:@"login"];
        [self.context setZone:@"us"];
    }
    
    return self;
}

- (void) start {
    [SimilityScript execute: self.context];
}

- (AnyPromise *) getDeviceProfileWithSessionId:(NSString *)sessionId {
    return [AnyPromise promiseWithAdapterBlock:^(PMKAdapter  _Nonnull adapter) {
        AFHTTPRequestOperationManager *manager = [AFHTTPRequestOperationManager manager];
        manager.requestSerializer = [AFJSONRequestSerializer serializer];
        
    }];
}

@end
