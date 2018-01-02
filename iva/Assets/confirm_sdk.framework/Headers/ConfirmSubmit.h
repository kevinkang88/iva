//
//  ConfirmSubmit.h
//  confirm-sdk
//
//  Created by roy on 1/20/16.
//  Copyright © 2016 confirm.io. All rights reserved.
//

#import <Foundation/Foundation.h>

#define CONFIRM_SUBMIT

@class IDModel;
@class FacialMatchResponse;
@class ConfirmSession;
@class ConfirmPayload;


typedef enum {
	ConfirmSubmitUploadProgress,
	ConfirmSubmitDownloadProgress,
	ConfirmSubmitSelfieProgress,
} ConfirmSubmitProgressType;

typedef enum {
	ConfirmSubmitStateInitializing,
	ConfirmSubmitStateUploading,
	ConfirmSubmitStateReceivedGuid,
	ConfirmSubmitStateProcessing,
	ConfirmSubmitStateGettingResults,
	ConfirmSubmitStateCancelling,
	ConfirmSubmitStateCancelled,
	ConfirmSubmitStateCompleted
} ConfirmSubmitState;

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const kConfirmSubmitErrorDomain;
NS_ENUM(NSInteger)
{
	kConfirmSubmitErrorNoAPIKey			= -4000,
	kConfirmSubmitErrorBadAPIKey		= -4001,
	kConfirmSubmitErrorHTTPErrKey		= -4002,
	kConfirmSubmitErrorCancelled		= -4003,
	kConfirmSubmitErrorBadParameters	= -4004,
};

FOUNDATION_EXPORT NSString * const kStatusInfoTitleKey;			// value: NSString*
FOUNDATION_EXPORT NSString * const kStatusInfoMessageKey;		// value: NSString*
FOUNDATION_EXPORT NSString * const kStatusInfoGuidKey;			// value: NSString*

FOUNDATION_EXPORT NSString * const kSupportedCountryCodeKey;		// value: NSString*
FOUNDATION_EXPORT NSString * const kSupportedCountryNameKey;		// value: NSString*

FOUNDATION_EXPORT NSString * const kWebhookSerializerFirstNameKey;	// value: NSString*
FOUNDATION_EXPORT NSString * const kWebhookSerializerMiddleNameKey;	// value: NSString*
FOUNDATION_EXPORT NSString * const kWebhookSerializerLastNameKey;	// value: NSString*
FOUNDATION_EXPORT NSString * const kWebhookSerializerFullNameKey;	// value: NSString*

FOUNDATION_EXPORT NSString * const kWebhookSerializerAddress1Key;	// value: NSString*
FOUNDATION_EXPORT NSString * const kWebhookSerializerAddress2Key;	// value: NSString*
FOUNDATION_EXPORT NSString * const kWebhookSerializerCityKey;		// value: NSString*
FOUNDATION_EXPORT NSString * const kWebhookSerializerStateKey;		// value: NSString*
FOUNDATION_EXPORT NSString * const kWebhookSerializerZipKey;		// value: NSString*

FOUNDATION_EXPORT NSString * const kWebhookSerializerGenderKey;		// value: NSString*
FOUNDATION_EXPORT NSString * const kWebhookSerializerWeightKey;		// value: NSString*
FOUNDATION_EXPORT NSString * const kWebhookSerializerHeightKey;		// value: NSString*
	
FOUNDATION_EXPORT NSString * const kWebhookSerializerDocStatusKey;		// value: NSString*

FOUNDATION_EXPORT NSString * const kWebhookSerializerDOBKey;		// value: NSDate*

FOUNDATION_EXPORT NSString * const kWebhookSerializerDocumentNumberKey;	// value: NSString*
FOUNDATION_EXPORT NSString * const kWebhookSerializerDateIssuedKey;		// value: NSDate*
FOUNDATION_EXPORT NSString * const kWebhookSerializerDateExpiresKey;	// value: NSDate*

NS_ASSUME_NONNULL_END

typedef void (^ConfirmSubmitSessionCallback)(ConfirmSession* _Nonnull submitSession);
typedef void (^ConfirmSubmitStatusCallback)(NSDictionary* _Nonnull info, ConfirmSubmitState state);
typedef void (^ConfirmSubmitProgressCallback)(NSProgress* _Nonnull progress, ConfirmSubmitProgressType progressType);
typedef void (^ConfirmSubmitResultCallback)(IDModel* _Nullable validatedID);
typedef void (^ConfirmSubmitPayloadResultCallback)(IDModel * _Nullable validatedID);	// facial response now in IDModel
#if (API_VERSION == 1)	// deprecated in API_VERSION >= 2
typedef void (^ConfirmSubmitFacialResultCallback)(FacialMatchResponse * _Nonnull facialResponse, NSError* _Nullable facialError);
#endif
typedef void (^ConfirmSubmitErrorCallback)(NSError* _Nonnull error, NSString* _Nullable guid);

typedef NSString* 		_Nonnull (^ConfirmSubmitWebhookGetURL)(NSString* _Nonnull guid);
typedef void			(^ConfirmSubmitWebhookConfigCall)(NSMutableURLRequest* _Nonnull request);
typedef NSDictionary* 	_Nonnull (^ConfirmSubmitWebhookSerializer)(NSDictionary* _Nonnull jsonIN);

@interface ConfirmSubmit : NSObject

@property (nonatomic, retain)	NSString* _Nonnull							apiKey;
@property (nonatomic, assign)	float										facialMatchThreshold;

@property (nonatomic, copy)	ConfirmSubmitWebhookGetURL _Nullable		webhookGetURL;			// pii server (optional if no pii, required if server avail)
@property (nonatomic, copy)	ConfirmSubmitWebhookConfigCall _Nullable	webhookConfig;			// pii server (optional)
@property (nonatomic, copy)	ConfirmSubmitWebhookSerializer _Nullable	webhookSerializer;		// pii server (optional)


#if (API_VERSION == 1)	// deprecated in API_VERSION >= 2
@property (nonatomic, copy)		ConfirmSubmitFacialResultCallback _Nullable	facialResultCallback;
#endif

+ (ConfirmSubmit* _Nonnull)singleton;

- (void)submitIDCapturePayload:(ConfirmPayload* _Nonnull )payload
				  onSubmission:(_Nullable ConfirmSubmitSessionCallback)sessionBlock
					  onStatus:(_Nullable ConfirmSubmitStatusCallback)statusBlock
					onProgress:(_Nullable ConfirmSubmitProgressCallback)progressBlock
					 onSuccess:(_Nonnull ConfirmSubmitPayloadResultCallback)successBlock
					   onError:(_Nonnull ConfirmSubmitErrorCallback)errorBlock;

+ (void)cleanup;

// MorphoTrust

- (void)setMorphoTrustAPIKey:(NSString* _Nonnull)apiKey andURL:(NSString* _Nonnull)url;
- (void)setMorphoTrustESFKey:(NSString* _Nonnull)esfKey;

@end
	
@interface ConfirmSubmit(Network)

- (void)getSupportedCountries:(void(^_Nonnull)(NSArray<NSDictionary*>*_Nonnull countries, NSError* _Nullable error))completion;

@end
