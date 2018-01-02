//
//  IDXESFView.h
//  IDXESF
//
//  Created by clayton on 6/9/15.
//  Copyright (c) 2015 MorphoTrust. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IDXESFAuthentication_Debug.h"
#import "IDXESFPayload_Debug.h"
#import <IDXProxyService/IDXProxyService.h>

/*!
 @typedef IDXESFViewStyle
 
 @brief  Available styles for IDXESFView.
 
 @discussion Available styles for IDXESFView
 
 @field IDXESFViewStyleNone    None.
 @field IDXESFViewStyleGuide   Show user instructions & card placement template.
 @field IDXESFViewStyleGuideFade  Show user instructions & card placement template. Fading animation.
 @field IDXESFViewStyleGuideOnly  Show the card placement template.
 
 */
typedef NS_ENUM(NSInteger, IDXESFViewStyleD) {
    /*! @brief None. */
    IDXESFViewStyleNoneD,
    
    /*! @brief Show user instructions & card placement template. */
    IDXESFViewStyleGuideD,
    
    /*! @brief Show user instructions & card placement template. Fading animation. */
    IDXESFViewStyleGuideFadeD,
    
    /*! @brief Show the card placement template. */
    IDXESFViewStyleGuideOnlyD
};


/*!
 @typedef IDXESFProgressStyle
 
 @brief  Available styles for ESFProgress.
 
 @discussion Available styles for ESFProgress.
 
 @constant IDXESFProgressStyleNone    IDXESFProgressStyleNone.
 @constant IDXESFProgressStyleCircle  IDXESFProgressStyleCircle.
 */
typedef NS_ENUM(NSUInteger, IDXESFProgressStyleD) {
	IDXESFProgressStyleNoneD,
	IDXESFProgressStyleCircleD
};

/*!
 @typedef IDXESFScanCompleteImageStyle
 
 @brief  Available styles for ESFScanCompleteImage.
 
 @discussion Available styles for ESFScanCompleteImage.
 
 @constant IDXESFScanCompleteImageStyleNone    IDXESFScanCompleteImageStyleNone.
 @constant IDXESFScanCompleteImageStyleDefault   IDXESFScanCompleteImageStyleDefault.
 @constant IDXESFScanCompleteImageStyleCustom  IDXESFScanCompleteImageStyleCustom.
 */
typedef NS_ENUM(NSUInteger, IDXESFScanCompleteImageStyleD) {
	IDXESFScanCompleteImageStyleNoneD,
	IDXESFScanCompleteImageStyleDefaultD,
	IDXESFScanCompleteImageStyleCustomD
};

/*!
 @typedef IDXESFScanArtifact
 
 @brief  Available options for ESFScanArtifact.
 
 @discussion Available options for ESFScanArtifact.
 
 @constant IDXESFScanArtifactNone    IDXESFScanArtifactNone.
 @constant IDXESFScanArtifactCardImage   IDXESFScanArtifactCardImage.
 @constant IDXESFScanArtifactESFPayload   IDXESFScanArtifactESFPayload.
 @constant IDXESFScanArtifactCardPortrait   IDXESFScanArtifactCardPortrait.
 */
typedef NS_OPTIONS(NSUInteger, IDXESFScanArtifactD) {
    IDXESFScanArtifactNoneD           = 0,
    IDXESFScanArtifactCardImageD		= 1 << 0,
    IDXESFScanArtifactESFPayloadD     = 1 << 1,
    IDXESFScanArtifactCardPortraitD   = 1 << 2
};

/*!
    ##ESF Delegate functions
 
 */

/*!
 @protocol IDXESFViewDelegate_Debug
 
 @brief The IDXESFViewDelegate_Debug protocol
 
 */
@protocol IDXESFViewDelegate_Debug <NSObject>

@required
/*!
 @brief Implement this delegate to get the result of the ESF detection process.
 
 @param success Specified <b>YES</b> if successful, <b>NO</b> if failed.
 
 @param payLoad Payload to be passed to delegate as <b>IDXESFPayload_Debug</b>.
 
 @param dlImage Drivers license image to be passed to delegate as UIImage.
 
 @param portrait License portrait to be passed to delegate as UIImage.
 
 */
- (void)detectCompleted:(BOOL)success payloadData:(IDXESFPayload_Debug *)payLoad dlImage:(UIImage *)dlImage portrait:(UIImage *)portrait;

@optional
/*!
 @brief Implement this delegate to get SDK errors.
 
 @param message Message to be passed to delegate as NSString.
 
 */
- (void)detectError:(NSString *)message;

@end

/*!
 @class ESFView_Debug
 
 @brief The ESFView_Debug class
 
 @discussion    The ESFView_Debug class
 
 @superclass SuperClass: UIView
 
 @coclass    Coclass: IDXESFViewDelegate_Debug
 
 */
@interface IDXESFView_Debug : UIView

@property (nonatomic, weak) id<IDXESFViewDelegate_Debug> delegate;

/*! @brief Determines if the video is shut off when detection is stopped. */
@property (nonatomic) BOOL saveEnergy;

/*! @brief Default is true. Disable for when camera is stationary. Best left enabled when using Card Detect. */
@property (nonatomic) BOOL autoFocusContinuousEnabled;

/*! @brief Shows checkmark showing scan completed, even if no watermark detected. */
@property (nonatomic) BOOL alwaysShowCheckmarkOnCompletion;
@property (nonatomic) IDXESFViewStyle style;
@property (nonatomic) BOOL flipCardTextEnabled;
@property (nonatomic) IDXESFProgressStyle progressStyle;
@property (nonatomic, strong) UIColor *progressOnColor;
@property (nonatomic, strong) UIColor *progressOffColor;
@property (nonatomic) IDXESFScanCompleteImageStyle scanCompleteImageStyle;
@property (nonatomic, strong) UIImage *scanCompleteImage;
@property (nonatomic) IDXESFScanArtifact scanArtifactOptions;

/*! @brief Enable/Disable Card Detection. */
@property (nonatomic) BOOL cardDetectEnabled __attribute((deprecated(("Use IDXESFScanArtifactCardImage."))));

/*!
 ##Identix Properties
 
 Properties specific to debugging using the Identix service's document authentication. These properties are not included in the non-debuggable version of this framework. Used to return values from the Identix service
 
 */

/*! @brief A key provided by MorphoTrust. This key will enable access to the Identix service in order to perform biometric facial matching and driver license document authentication. */
@property (nonatomic, strong) NSString *apiKey;

/*! @brief The Identix service URL provided to you by MorphoTrust. */
@property (nonatomic, strong) NSString *identixURL;

/*! @brief The compressionQuality property is a value on a scale from 0.0 to 1.0. This value will determine the quality of the image after it is compressed. In order to expedite matching in the Identix service, images are compressed before they are sent. A higher value for this property is representative of a higher quality image following compression. Conversely, a lower value for this property represents a lower quality image following compression. */
@property (nonatomic) CGFloat frontCompressionQuality;

/*! @brief An image of the front of a driver license. By default, this property is initialized but not assigned an actual image. */
@property (nonatomic, strong) UIImage *driverLicenseFront;

/*! @brief An image of a portrait in a driver license. By default, this property is initialized but not assigned an actual image. */
@property (nonatomic, strong) UIImage *driverLicensePortrait;

/*! @brief A toggle for calling the document authentication endpoint of the Identix service. If this value is no, then IDXESFPayload object with hard-coded values will be returned in the detectCompleted delegate function. If this value is set to yes, then the Identix service's document authentication will be used and a partial IDXESFPayload object will be returned in the detectCompleted delegate function. */
@property (nonatomic) BOOL callIdentixService;

    //Used to return hard-coded values
/*! @brief Boolean for determining if the primary watermark is found. This is used for controlling the output of the hardcoded values of the payload. By default this value is false. */
@property (nonatomic) BOOL foundPrimary;

/*! @brief Boolean for determining if the secondary watermark is found. This is used for controlling the output of the hardcoded values of the payload. By default this value is false. */
@property (nonatomic) BOOL foundSecondary;

/*! @brief Boolean for determining if the license is valid. Even if both watermarks are found, the license could be invalid. This is used for controlling the output of the hardcoded values of the payload. By default this value is false. */
@property (nonatomic) BOOL validLicense;

/*!
 @brief Start detection process.
 
 @discussion Use this method to start the process of detecing a watermark. The parameter <b>maxDurationInSeconds</b> specifies in integers the amount of time in seconds you will scan for a watermark before timing out. Upon successful completion of scan, the <b>detectCompleted:payloadData:dlImage:portrait:</b> delegate method will be called. On failure, the <b>detectError:</b> delegate method will be called.
 
 @param maxDurationInSeconds Specify in integers the amount of time in seconds you will scan for a watermark before timing out.
 
 */
-(void)startDetect:(int)maxDurationInSeconds;

/*!
 @brief Forcibly stops the detection process.
 
 @discussion Use this method to stop the process of detecing a watermark, generally added to a UIViewController's <b>viewDidDisappear:</b> method.
 
 */
-(void)stopDetect;

@end
