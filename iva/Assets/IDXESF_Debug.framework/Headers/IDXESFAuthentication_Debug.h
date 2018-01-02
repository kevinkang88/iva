//
//  IDXESFAuthentication.h
//  IDXESF
//
//  Created by clayton on 6/9/15.
//  Copyright (c) 2015 MorphoTrust. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IDXESFPayload_Debug.h"
#import "IDXESFStatesEnum_Debug.h"
#import <IDXProxyService/IDXProxyService.h>

/*!
 @class IDXESFAuthentication_Debug
 
 @brief The IDXESFAuthentication_Debug class
 
 @discussion    The IDXESFAuthentication_Debug class
 
 @superclass SuperClass: NSObject
 
 */
@interface IDXESFAuthentication_Debug : NSObject

/*!
 @brief Block for use with <b>decodeImage</b> methods.
 
 @param payload Payload returned upon completion of image decoding.
 
 @param error Error returned (nil if successful).
 */
typedef void (^decodeCompletionBlockD)(IDXESFPayload_Debug *payload, NSError *error);

/*!
 @brief Perform image decoding.
 
 @discussion Use this method to perform image decoding by inputting a single image; returns a Payload if found. The parameter <b>image</b> should be cropped as best as possible and oriented right-side up. If no <b>primaryRect</b> is available, use the <b>decodeImage:completed:</b> class method.
 
 @param image Single image to be decoded.
 
 @param primaryRect Rect in which image can be found, if available.
 
 @param completionBlock See <b>decodeCompletionBlock</b>.
 
 */
-(void)decodeImage:(UIImage *)image withPrimary:(CGRect)primaryRect completed:(decodeCompletionBlock)completionBlock;
/*!
 * @brief WARNING: Please avoid using this class function. Though it exists in the actual IDXESF framework, it should be avoided here because the 'debug' properties of this class should be set in order to return a populated IDXESFPayload object. Please use the instance version of this function.
 */
+(void)decodeImage:(UIImage *)image completed:(decodeCompletionBlock)completionBlock;

/*!
 @brief Check for ESF.
 
 @discussion Takes in a <b>state</b> and <b>issue date</b> and returns <b>YES</b> if the document should contain a ESF, <b>NO</b> if not.
 
 @param state State of document
 
 @param date Issue date of document
 
 @param error Error to be passed by reference (nil if successful).
 
 */
-(BOOL)documentContainsESF:(ESFStates)state issueDate:(NSDate *)date errorInfo:(NSError **)error;

/*!
 @brief Check for ESF.
 
 @discussion Takes in a <b>state</b> and <b>issue date</b> and returns <b>YES</b> if the document should contain a ESF, <b>NO</b> if not.
 
 @param state State of document
 
 @param date Issue date of document
 
 @param error Error to be passed by reference (nil if successful).
 
 */
+(BOOL)documentContainsESF:(ESFStates)state issueDate:(NSDate *)date errorInfo:(NSError **)error;

/*!
 @brief Check for ESF.
 
 @discussion Takes in a <b>state</b> and <b>date components</b> and returns <b>YES</b> if the document should contain a ESF, <b>NO</b> if not.
 
 @param state State of document
 
 @param day Issue day of document
 
 @param month Issue month of document
 
 @param year Issue year of document
 
 @param error Error to be passed by reference (nil if successful).
 
 */
-(BOOL)documentContainsESF:(ESFStates)state issueDay:(int)day issueMonth:(int)month issueYear:(int)year errorInfo:(NSError **)error;

/*!
 @brief Check for ESF.
 
 @discussion Takes in a <b>state</b> and <b>date components</b> and returns <b>YES</b> if the document should contain a ESF, <b>NO</b> if not.
 
 @param state State of document
 
 @param day Issue day of document
 
 @param month Issue month of document
 
 @param year Issue year of document
 
 @param error Error to be passed by reference (nil if successful).
 
 */
+(BOOL)documentContainsESF:(ESFStates)state issueDay:(int)day issueMonth:(int)month issueYear:(int)year errorInfo:(NSError **)error;

//These properties are specific for debugging with this framework. These will not be available in the non-debuggable version of this framework.
    //Used to return values from the Identix service
/*!
 * @brief A key provided by MorphoTrust. This key will enable access to the Identix service in order to perform biometric facial matching and driver license document authentication.
 */
@property (nonatomic, strong) NSString *apiKey;
/*!
 * @brief The Identix service URL provided to you by MorphoTrust.
 */
@property (nonatomic, strong) NSString *identixURL;
/*!
 * @brief The compressionQuality property is a value on a scale from 0.0 to 1.0. This value will determine the quality of the image after it is compressed. In order to expedite matching in the Identix service, images are compressed before they are sent. A higher value for this property is representative of a higher quality image following compression. Conversely, a lower value for this property represents a lower quality image following compression.
 */
@property (nonatomic) CGFloat frontCompressionQuality;
/*!
 * @brief An image of the front of a driver license. By default, this property is initialized but not assigned an actual image.
 */
@property (nonatomic, strong) UIImage *driverLicenseFront;
/*!
 * @brief An image of a portrait in a driver license. By default, this property is initialized but not assigned an actual image.
 */
@property (nonatomic, strong) UIImage *driverLicensePortrait;
/*!
 * @brief A toggle for calling the document authentication endpoint of the Identix service. If this value is no, then IDXESFPayload object with hard-coded values will be returned in the detectCompleted delegate function. If this value is set to yes, then the Identix service's document authentication will be used and a partial IDXESFPayload object will be returned in the detectCompleted delegate function.
 */
@property (nonatomic) BOOL callIdentixService;

    //Used to return hard-coded values
/*!
 * @brief Boolean for determining if the primary watermark is found. This is used for controlling the output of the hardcoded values of the payload. By default this value is false.
 */
@property (nonatomic) BOOL foundPrimary;
/*!
 * @brief Boolean for determining if the secondary watermark is found. This is used for controlling the output of the hardcoded values of the payload. By default this value is false.
 */
@property (nonatomic) BOOL foundSecondary;
/*!
 * @brief Boolean for determining if the license is valid. Even if both watermarks are found, the license could be invalid. This is used for controlling the output of the hardcoded values of the payload. By default this value is false.
 */
@property (nonatomic) BOOL validLicense;

@end
