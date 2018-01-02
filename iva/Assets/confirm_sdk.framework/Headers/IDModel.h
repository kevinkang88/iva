//
//  IDModel.h
//  AIDD Demo App
//
//  Created by David Thor on 8/19/15.
//  Copyright (c) 2015 AIDD. All rights reserved.
//

#import <Foundation/Foundation.h>
#define IDMODEL


@class IdentityModel;
@class FacialMatchResponse;

// appID field possibilities
extern NSString* const kFullAuthAppID;
extern NSString* const kBackAuthAppID;
extern NSString* const kFacialAuthAppID;
extern const float kUnknownFacialScore;

@interface IDModel : NSObject

@property (readonly) BOOL isPending;
@property (readonly) BOOL isUnknown;
@property (readonly) BOOL isComplete;
@property (readonly) BOOL didPass;
@property (readonly) BOOL didFail;
@property (readonly) BOOL didError;

@property (readonly) BOOL hasDocumentStatus;
@property (readonly) BOOL hasPII;

@property (nonatomic, retain, readonly) NSString *		documentType;
@property (nonatomic, retain, readonly) NSString *		appID;
@property (nonatomic, retain, readonly) NSString *		guid;
@property (nonatomic, retain, readonly) NSString* 		recommendation;
@property (nonatomic, retain, readonly) NSDate*	 		submittedOn;
@property (nonatomic, retain, readonly) NSDate* 		updatedOn;
@property (nonatomic, retain, readonly) NSDate* 		processingCompletedOn;

@property (nonatomic, retain, readonly) NSArray*		alerts;
@property (readonly)					float			facialScore;	// kUnknownFacialScore if not detected
// v2 properties
@property (nonatomic, retain, readonly) NSString* 		fullName;
@property (nonatomic, retain, readonly) NSString* 		firstName;
@property (nonatomic, retain, readonly) NSString* 		middleName;
@property (nonatomic, retain, readonly) NSString* 		lastName;
@property (nonatomic, retain, readonly) NSString* 		suffix;

@property (nonatomic, retain, readonly) NSString* 		address1;
@property (nonatomic, retain, readonly) NSString* 		address2;
@property (nonatomic, retain, readonly) NSString* 		city;
@property (nonatomic, retain, readonly) NSString* 		state;
@property (nonatomic, retain, readonly) NSString* 		zip;

@property (nonatomic, retain, readonly) NSDate*			dob;
@property (readonly)					NSInteger		age;
@property (nonatomic, retain, readonly) NSString*		documentNumber;
@property (nonatomic, retain, readonly) NSString*		issuer;
@property (nonatomic, retain, readonly) NSDate*			dateIssued;
@property (nonatomic, retain, readonly) NSDate*			dateExpires;

@property (nonatomic, retain, readonly) NSString*		gender;
@property (nonatomic, retain, readonly)	NSString*		weight;
@property (nonatomic, retain, readonly) NSString*		height;

// deprecated
@property (nonatomic, retain, readonly) IdentityModel*	identity 			__attribute__((deprecated("please use IDModel properties")));
@property (nonatomic, retain, readonly) FacialMatchResponse* facialResponse	__attribute__((deprecated("please use IDModel properties")));

+ (instancetype)model;
+ (instancetype)modelWithResponse:(NSDictionary*)responseObject;

@end
