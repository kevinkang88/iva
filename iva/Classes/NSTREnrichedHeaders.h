//
//  NSTREnrichedHeaders.h
//  IVA-IOS-SDK
//
//  Created by kevin on 11/30/17.
//  Copyright © 2017 yooniverse. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum
{
    ATT = 1,
    VERIZON = 2,
    SPRINT = 3
} AllowedProviders;

@interface NSTREnrichedHeaders : NSObject

- (id)initWithProvider:(AllowedProviders *)provider andEncryptedPayload:(NSData *)payload;

@property(nonatomic, retain) NSNumber* provider;
@property(nonatomic, retain) NSData* encryptedPayload;



@end
