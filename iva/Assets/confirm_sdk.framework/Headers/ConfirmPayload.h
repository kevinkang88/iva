//
//  ConfirmPayload.h
//  confirm-sdk
//
//  Created by roy on 4/21/16.
//  Copyright © 2016 Confirm.io. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^ConfirmPayloadFetchImage)(UIImage* image );

@interface ConfirmPayload : NSObject

@property (nonatomic, readonly) UIImage*	licenseCroppedImage;	// will block thread until completion
@property (nonatomic, readonly) UIImage*	passportCroppedImage; 	// will block thread until completion
@property (nonatomic, readonly) UIImage*	idCroppedImage;			// either licenseCroppedImage or passportCroppedImage, whichever applicable
@property (nonatomic, readonly) UIImage*	selfieCroppedImage; 	// will block thread until completion

@property (nonatomic, readonly) UIImage*	frontImage; 
@property (nonatomic, readonly) UIImage*	backImage; 
@property (nonatomic, readonly) UIImage*	selfieImage; 
@property (nonatomic, readonly) UIImage*	passportImage; 

@property (nonatomic, readonly) BOOL			hasFront;
@property (nonatomic, readonly) BOOL			hasBack;
@property (nonatomic, readonly) BOOL			hasSelfie;
@property (nonatomic, readonly) BOOL			esfValid;
@property (nonatomic, readonly) NSDictionary*	esfMeta;

@property (nonatomic, readonly) NSString*	frontImagePath; 
@property (nonatomic, readonly) NSString*	backImagePath; 
@property (nonatomic, readonly) NSString*	selfieImagePath; 
@property (nonatomic, readonly) NSString*	passportImagePath; 

// payload - constructor - normally not required to create at all -
//			 ConfirmCapture object will create for you -
//			 but if you need to have access to the images on the fly,
//				you can do:
//				ConfirmPayload* myPayload = ConfirmPayload.payload;
//				ConfirmCapture* mySession = [ConfirmCapture captureSessionWithPayload:myPayload];
//

+ (instancetype)payload;

- (void)fetchFrontImage:(ConfirmPayloadFetchImage)fetchBlock;
- (void)fetchBackImage:(ConfirmPayloadFetchImage)fetchBlock;
- (void)fetchSelfieImage:(ConfirmPayloadFetchImage)fetchBlock;

- (void)addGenericImage:(UIImage*)image atIndex:(NSUInteger)index;
- (void)fetchGenericImageAtIndex:(NSUInteger)index block:(ConfirmPayloadFetchImage)fetchBlock;

- (void)cleanup;

@end
