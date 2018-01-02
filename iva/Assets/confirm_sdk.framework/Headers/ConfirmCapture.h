//
//  ConfirmCapture.h
//  confirm-sdk
//
//  Created by roy on 4/7/16.
//  Copyright © 2016 Confirm.io. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <confirm_sdk/ConfirmCaptureTypes.h>

@class ConfirmPayload, ConfirmCapture;
@protocol CustomViewDelegate;	// deprecated

typedef UIImage* (^ConfirmImageRotateCallback)(void);

@protocol ConfirmCaptureDelegate <NSObject>

- (void)ConfirmCaptureDidComplete:(ConfirmPayload*)payload;
- (void)ConfirmCaptureDidCancel;

@optional

- (BOOL)ConfirmCapture:(ConfirmCapture*)session willPresentVC:(ConfirmCaptureSide)side;
- (UIViewController*)ConfirmCaptureCustomVC:(ConfirmCapture*)session;
- (BOOL)ConfirmCaptureWillComplete:(ConfirmCapture*)session;
- (void)ConfirmCaptureWillCancel;

- (BOOL)ConfirmCapture:(ConfirmCapture*)session willPresentInstructions:(ConfirmCaptureSide)side __attribute__((deprecated("SDK never presents instructions - it's either custom, or none")));
- (UIView<CustomViewDelegate>*)ConfirmCapture:(ConfirmCapture*)session customInstructions:(ConfirmCaptureSide)side __attribute__((deprecated("Use ConfirmCapture:getInstructionsVC:")));

- (UIViewController<ConfirmVCProtocol>*)ConfirmCapture:(ConfirmCapture*)session
									 getInstructionsVC:(ConfirmCaptureSide)side;

- (UIViewController<ConfirmVCProtocol>*)ConfirmCapture:(ConfirmCapture*)session
									 getVerificationVC:(ConfirmCaptureSide)side
												 image:(UIImage*)image;

- (UIViewController<ConfirmVCProtocol>*)ConfirmCapture:(ConfirmCapture*)session
									 getVerificationVC:(ConfirmCaptureSide)side
												 image:(UIImage*)image
												  hint:(ConfirmOrientation)orientation
										   rotateBlock:(ConfirmImageRotateCallback)rotateBlock;


@end

@interface ConfirmCapture : NSObject

@property (nonatomic, assign)		id<ConfirmCaptureDelegate>	delegate;

@property (nonatomic, assign)		ConfirmMode					mode;				// set immediately after calling constructor
@property (nonatomic, assign) 		ConfirmDocumentType 		documentType;		// default ConfirmDocumentDriversLicense
@property (nonatomic, retain) 		NSString* 					issuingCountryCode;	// default USA

@property (nonatomic, assign)		BOOL						enableFrontScan;	// default YES
@property (nonatomic, assign)		BOOL						enableBackScan;		// default YES
@property (nonatomic, assign)		BOOL						enablePassportScan;	// default NO

@property (nonatomic, assign)		BOOL						enableFacialMatch;	// default NO
@property (nonatomic, assign)		BOOL						enableFaceSkip;		// default NO

@property (nonatomic, assign)		BOOL						enableGenericScan;	// default NO

@property (nonatomic, assign)		BOOL						enableAutoConfirmation;		// default YES
@property (nonatomic, assign)		BOOL						enableManualConfirmation;	// default YES

@property (nonatomic, copy)			UIImage*					(^getOverlayImageBlock)(ConfirmCaptureSide side, ConfirmOrientation orientation);	// default nil - fits within target rect

@property (nonatomic, assign)		id<CustomViewDelegate>		customViewDelegate __attribute__((deprecated("use ConfirmCapture:getInstructionsVC: and ConfirmCapture:getVerificationVC:image:")));;


// preferred constructors
+ (ConfirmCapture*)captureSession;
+ (ConfirmCapture*)captureSessionWithPayload:(ConfirmPayload*)payload;


- (void)presentInParentVC:(UIViewController*)parentVC;
- (void)presentInParentVC:(UIViewController*)parentVC 
				inSubview:(UIView*)subView;
- (void)presentInNavigation:(UINavigationController*)userNav;
- (void)presentInNavigation:(UINavigationController*)userNav
				  topUserVC:(UIViewController*)topUserVC;

- (void)cancelCustomVC;
- (void)advanceCustomVC;

- (void)cancelInstructions;
- (void)advanceInstructions;

- (void)cancelVerification;
- (void)advanceVerification;


// for aspect ratio ID detection
- (void)setDocumentSize:(CGSize)docSize;	// default (3.375, 2.125)

// deletes cached images, etc. (called by dealloc)
- (void)cleanup;


@end
