//
//  ConfirmDetectorTypes.h
//  confirm-sdk
//
//  Copyright © 2017 Confirm.io. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <confirm_sdk/ConfirmCaptureTypes.h>

@interface ConfirmDetectionStatus : NSObject

@property (readonly)	BOOL topEdgeDetected;
@property (readonly)	BOOL leftEdgeDetected;
@property (readonly)	BOOL bottomEdgeDetected;
@property (readonly)	BOOL rightEdgeDetected;

@property (readonly)	BOOL tooFarAway;
@property (readonly)	BOOL tooClose;

@property (readonly)	CGRect detectedRect;	// in the coordinate space of the image passed in

@property (readonly)	ConfirmCaptureSide side;

@end
