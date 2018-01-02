//
//  BackAuthModel.h
//  confirm-sdk
//
//  Created by roy on 6/28/17.
//  Copyright © 2017 Confirm.io. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
	BackAuthDocUninitialized,
	BackAuthDocPass,
	BackAuthDocFail,
	BackAuthDocUnknown,
	BackAuthDocError,
} BackAuthDocStatus;

typedef enum {
	BackAuthRecUninitialized,
	BackAuthRecAccept,
	BackAuthRecReject,
	BackAuthRecReview,
} BackAuthRecStatus;

@interface BackAuthModel : NSObject

@property (readonly)		BOOL 				valid;
@property (readonly)		BOOL 				barcode2dExtracted;
@property (readonly)		BackAuthDocStatus	docStatus;
@property (readonly)		BackAuthRecStatus	recommendation;

+ (instancetype)model;
+ (instancetype)modelWithResponse:(NSDictionary*)responseObject;

@end
