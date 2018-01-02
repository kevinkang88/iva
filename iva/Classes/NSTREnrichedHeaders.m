//
//  NSTREnrichedHeaders.m
//  IVA-IOS-SDK
//
//  Created by kevin on 11/30/17.
//  Copyright © 2017 yooniverse. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSTREnrichedHeaders.h"

@implementation NSTREnrichedHeaders

- (id)initWithProvider:(AllowedProviders *)serviceProvider andEncryptedPayload:(NSData *)payload  {
    if(self = [super init]) {
        self.provider = [[NSNumber alloc] initWithInt:serviceProvider];
        self.encryptedPayload = payload;
    };
    
    return self;
};
@end
