//
//  IdentityModel.h
//  AIDD Demo App
//
//  Created by David Thor on 8/19/15.
//  Copyright (c) 2015 AIDD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IdentityClassificationModel.h"
#import "IdentityIssuanceModel.h"
#import "IdentityBioModel.h"

@interface IdentityModel : NSObject

@property (nonatomic, retain, readonly) IdentityClassificationModel *classification	__attribute__((deprecated("please use IDModel properties")));
@property (nonatomic, retain, readonly) IdentityIssuanceModel *issuance				__attribute__((deprecated("please use IDModel properties")));
@property (nonatomic, retain, readonly) IdentityBioModel *bio						__attribute__((deprecated("please use IDModel properties")));

+ (instancetype)model;

@end
