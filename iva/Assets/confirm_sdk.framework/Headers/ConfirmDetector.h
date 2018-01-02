//
//  ConfirmDetector.h
//  confirm-sdk
//
//  Created by roy on 6/13/17.
//  Copyright © 2017 Confirm.io. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <confirm_sdk/ConfirmDetectorTypes.h>

@class ConfirmPayload;

@protocol ConfirmDetectorDelegate <NSObject>

// unlike ConfirmCaptureDelegate::captureComplete:,
//	detectionComplete: is called for each side or begin/continue/endDetection call

- (void)detectionComplete:(ConfirmPayload*)payload;

// if endDetection: is called, before detectionComplete: has been, detectionFailed will be called
- (void)detectionFailed;

@optional

- (void)detectionStatus:(ConfirmDetectionStatus*)status;

@end

@interface ConfirmDetector : NSObject

@property (nonatomic, assign) id<ConfirmDetectorDelegate> delegate;
@property (nonatomic, assign) ConfirmMode mode;

@property (nonatomic, assign) ConfirmDocumentType documentType;	// default ConfirmDocumentDriversLicense
@property (nonatomic, retain) NSString* issuingCountryCode;		// default USA

@property (nonatomic, assign) CGSize targetSize;			// default (3.375 x 2.125) - ignored if targetRect provided
@property (nonatomic, assign) float minimumTargetArea;		// default 0.60 - ignored if targetRect provided
@property (nonatomic, assign) NSInteger numberStableFrames;	// default 1 - if using ConfirmDetector for video, how many consecutive aligned frames before 'complete'

// preferred constructors
+ (ConfirmDetector*)detectorSession;	// will create payload
+ (ConfirmDetector*)detectorSessionWithPayload:(ConfirmPayload*)payload;	// pass in payload previously created

// beginDetection:withTarget:
// • side - determines where in the payload to put the detected image
// • targetRect - determines when detectionComplete is called - and defines the ConfirmDetectionStatus content
//			    - pass in CGRectZero for 'best guess'

- (void)beginDetection:(ConfirmCaptureSide)side withTarget:(CGRect)targetRect;

// continueDetection:
// • image - video frame or still image to be investigated
// returns YES if initiated detection
// returns NO if skipped frame due to current processing

- (BOOL)continueDetection:(UIImage*)image;

// endDetection
- (void)endDetection;

@end
