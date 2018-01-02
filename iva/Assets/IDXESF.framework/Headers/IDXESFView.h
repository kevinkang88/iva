//
//  IDXESFView.h
//  IDXESF
//
//  Created by clayton on 6/9/15.
//  Copyright (c) 2015 MorphoTrust. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IDXESFAuthentication.h"
#import "IDXESFPayload.h"
#import <IDXCardDetect/IDXIdentixCardDetect.h>

typedef NS_ENUM(NSInteger, IDXVideoResolution) {
    IDXVideoResolutionIgnore,
    IDXVideoResolutionHigh,
    IDXVideoResolutionMedium
};

/*!
 @typedef IDXESFViewStyle
 
 @brief  Available styles for IDXESFView.
 
 @discussion Available styles for IDXESFView
 
 @field IDXESFViewStyleNone    None.
 @field IDXESFViewStyleGuide   Show user instructions & card placement template.
 @field IDXESFViewStyleGuideFade  Show user instructions & card placement template. Fading animation.
 @field IDXESFViewStyleGuideOnly  Show the card placement template.
 
 */

typedef NS_ENUM(NSInteger, IDXESFViewStyle) {
    /*! @brief None. */
    IDXESFViewStyleNone,
    
    /*! @brief Show user instructions & card placement template. */
    IDXESFViewStyleGuide,
    
    /*! @brief Show user instructions & card placement template. Fading animation. */
    IDXESFViewStyleGuideFade,
    
    /*! @brief Show the card placement template. */
    IDXESFViewStyleGuideOnly
};


/*!
 @typedef IDXESFProgressStyle
 
 @brief  Available styles for ESFProgress.
 
 @discussion Available styles for ESFProgress.
 
 @constant IDXESFProgressStyleNone    IDXESFProgressStyleNone.
 @constant IDXESFProgressStyleCircle  IDXESFProgressStyleCircle.
 */
typedef NS_ENUM(NSUInteger, IDXESFProgressStyle) {
    IDXESFProgressStyleNone,
    IDXESFProgressStyleCircle,
    IDXESFProgressStyleSpinner
};

/*!
 @typedef IDXESFScanCompleteImageStyle
 
 @brief  Available styles for ESFScanCompleteImage.
 
 @discussion Available styles for ESFScanCompleteImage.
 
 @constant IDXESFScanCompleteImageStyleNone    IDXESFScanCompleteImageStyleNone.
 @constant IDXESFScanCompleteImageStyleDefault   IDXESFScanCompleteImageStyleDefault.
 @constant IDXESFScanCompleteImageStyleCustom  IDXESFScanCompleteImageStyleCustom.
 */
typedef NS_ENUM(NSUInteger, IDXESFScanCompleteImageStyle) {
    IDXESFScanCompleteImageStyleNone,
    IDXESFScanCompleteImageStyleDefault,
    IDXESFScanCompleteImageStyleCustom
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
typedef NS_OPTIONS(NSUInteger, IDXESFScanArtifact) {
    IDXESFScanArtifactNone           = 0,
    IDXESFScanArtifactCardImage		= 1 << 0,
    IDXESFScanArtifactESFPayload     = 1 << 1,
    IDXESFScanArtifactCardPortrait   = 1 << 2
};

/*!
 ##ESF Delegate functions
 
 */

/*!
 @protocol IDXESFViewDelegate
 
 @brief The IDXESFViewDelegate protocol
 
 */
@protocol IDXESFViewDelegate <NSObject>

@required
/*!
 @brief Implement this delegate method to get the result of the ESF detection process.
 
 @param success Specified <b>YES</b> if successful, <b>NO</b> if failed.
 
 @param payLoad Payload to be passed to delegate as <b>IDXESFPayload</b>.
 
 @param dlImage Drivers license image to be passed to delegate as UIImage. This is cropped as best as possible to show only the card and no background information, as well as oriented right-side up.
 
 @param portrait License portrait to be passed to delegate as UIImage.
 
 */
- (void)detectCompleted:(BOOL)success payloadData:(IDXESFPayload *)payLoad dlImage:(UIImage *)dlImage portrait:(UIImage *)portrait;

@optional
/*!
 @brief Implement this delegate method to get SDK errors.
 
 @param message Message to be passed to delegate as NSString.
 
 */
- (void)detectError:(NSString *)message;

@end

@interface IDXESFView : UIView

@property (nonatomic, weak) id<IDXESFViewDelegate> delegate;

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
@property (nonatomic) DocumentType documentType;

/*!
 @brief Start detection process.
 
 @discussion Use this method to start the process of detecting a watermark. The parameter <b>maxDurationInSeconds</b> specifies in integers the amount of time in seconds you will scan for a watermark before timing out. Upon successful completion of scan, the <b>detectCompleted:payloadData:dlImage:portrait:</b> delegate method will be called. On failure, the <b>detectError:</b> delegate method will be called.
 
 @param maxDurationInSeconds Specify in integers the amount of time in seconds you will scan for a watermark before timing out.
 
 */
-(void)startDetect:(int)maxDurationInSeconds;

/*!
 @brief Forcibly stops the detection process.
 
 @discussion Use this method to stop the process of detecing a watermark, generally added to a UIViewController's <b>viewDidDisappear:</b> method.
 
 */
-(void)stopDetect;

@end
