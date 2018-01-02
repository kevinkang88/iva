//
//  IDXESFAuthentication.h
//  IDXESF
//
//  Created by clayton on 6/9/15.
//  Copyright (c) 2015 MorphoTrust. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IDXESFPayload.h"
#import "IDXESFStatesEnum.h"

/*!
 @class IDXESFAuthentication
 
 @brief The IDXESFAuthentication class
 
 @discussion    The IDXESFAuthentication class
 
 @superclass SuperClass: NSObject 
 
 */
@interface IDXESFAuthentication : NSObject

/*!
 @brief Block for use with <b>decodeImage</b> methods.
 
 @param payload Payload returned upon completion of image decoding.
 
 @param error Error returned (nil if successful).
 */
typedef void (^decodeCompletionBlock)(IDXESFPayload *payload, NSError *error);

/*!
 @brief Perform image decoding.
 
 @discussion Use this method to perform image decoding by inputting a single image; returns a Payload if found. The parameter <b>image</b> should be cropped as best as possible and oriented right-side up. If no <b>primaryRect</b> is available, use the <b>decodeImage:completed:</b> class method.
 
 @param image Single image to be decoded.
 
 @param primaryRect Rect in which image can be found, if available.
 
 @param completionBlock See <b>decodeCompletionBlock</b>.
 
 */
-(void)decodeImage:(UIImage *)image withPrimary:(CGRect)primaryRect completed:(decodeCompletionBlock)completionBlock;



/*!
 @brief Perform image decoding.
 
 @discussion Use this method to perform image decoding by inputting a single image; returns a Payload if found. The parameter <b>image</b> should be cropped as best as possible and oriented right-side up. This variant allows for disabling use of sliding window search for Primary and Secondary for speed reasons.  If <b>bSlidingWindow</b> is disabled, the function may return a Primary detection from the <b>primaryRect</b> but will never return a validated Primary-Secondary pair.  For this usage, you must store the results from multiple video frames and combine Primary and Secondary via something like <b>decodePrimary:andSecondary:primaryOnFace</b>
 
 @param image Single image to be decoded.
 
 @param primaryRect Rect in which image can be found, if available.
 
 @param bSlidingWindow BOOL to indicate if we want to allow sliding window search for Primary and Secondary
 
 @param completionBlock See <b>decodeCompletionBlock</b>.
 
 */
-(void)decodeImage:(UIImage *)image withPrimary:(CGRect)primaryRect useSlidingWindow:(BOOL)bSlidingWindow completed:(decodeCompletionBlock)completionBlock;


/*!
 @brief Perform image decoding.
 
 @discussion Use this method to perform image decoding by inputting a single image; returns a Payload if found. The parameter <b>image</b> should be cropped as best as possible and oriented right-side up. If a discrete <b>primaryRect</b> is available, use the <b>decodeImage:withPrimary:completed:</b> instance method.
 
 @param image Single image to be decoded.
 
 @param completionBlock See <b>decodeCompletionBlock</b>.
 
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


/*!
 @brief Attempt to jointly decode raw Primary and Secondary ESF data
 
 @discussion Use this method if you have an NSDictionary of data for Primary and Secondary ESF that were potentially detected on different frames of a video capture session and you would like to try to decode them jointly and perform all the appropriate consistency checks between them.
 
 @param dictPrimary is an <b>NSDictionary</b> holding the results of detecting a Primary ESF, as per the return of the DMIDMarcReader function - (NSDictionary*) readImageBufferRect
 
 @param dictSecondary is an <b>NSDictionary</b> holding the results of detecting a Secondary ESF, as per the return of the DMIDMarcReader function - (NSDictionary*) readImageBufferRect
 
 @param bPrimaryOnFace is a <b>BOOL</b> used to set the flag in the generated IDXESFPayload that indicates if this dictPrimary came from the decoding of a Primary ESF detected exactly on top of a portrait face.  This flag can be used to warn about possible face spoofing (when false)
 
 @return Returned <b>IDXESFPayload*</b> is an object created with the result of the attempted joint decoding of the provided Primary and Secondary ESF data.  If all is successful, the object's internal <b>valid</b> property will be TRUE.  If <b>nil</b> is returned there was an internal error.  One possible cause is if the internal static instance of <b>DMAAMVAReader</b> is not yet initialized.  However, if <b>DMIDMarcReader -readImageBufferRect</b> has already been called, that instance should be valid.
 */
+(IDXESFPayload*)decodePrimary:(NSDictionary*)dictPrimary andSecondary:(NSDictionary*)dictSecondary primaryOnFace:(BOOL)bPrimaryOnFace;

@end
