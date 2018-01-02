//
//  ConfirmCaptureTypes.h
//  confirm-sdk
//
//  Created by roy on 9/16/16.
//  Copyright © 2016 Confirm.io. All rights reserved.
//

typedef enum {
	ConfirmModeDefault,
	ConfirmModeBackAuth,
} ConfirmMode;

typedef enum {
	ConfirmCaptureFront,
	ConfirmCaptureBack,
	ConfirmCaptureSelfie,
	ConfirmCaptureGeneric,
	ConfirmCapturePassport,
} ConfirmCaptureSide;

typedef enum {
	ConfirmOrientationUnknown,
	ConfirmOrientationLandscape,
	ConfirmOrientationPortrait
} ConfirmOrientation;

typedef enum {
	ConfirmDocumentDriversLicense,
	ConfirmDocumentPassport,
	ConfirmDocumentIDCard,
} ConfirmDocumentType;

typedef void (^ConfirmVCCompletion)(BOOL cancelled);

@protocol ConfirmVCProtocol <NSObject>

@optional

- (void)willRotate:(UIDeviceOrientation)orientation;
- (void)didRotate:(UIDeviceOrientation)orientation;

@end

