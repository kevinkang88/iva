//
//  IDXService.h
//  IDXProxyService
//
//  MTUSA MTUSA MTUSA MTUSA - MorphoTrust USA - MTUSA MTUSA MTUSA MTUSA
//  COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL
//
//  Copyright: 2017 by MorphoTrust USA, LLC. All rights reserved.
//  License: In accordance with MorphoTrust USA’s license agreement.
//  Code Classifaction: COMMERCIAL
//
//  Classification Person: Clayton Gragg
//  Classification Reason: Software not specific to any U.S. Government Entity
//  Classification Date: 2017
//
//  COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL
//  MTUSA MTUSA MTUSA MTUSA - MorphoTrust USA - MTUSA MTUSA MTUSA MTUSA

#import <Foundation/Foundation.h>

#import "IDXDocAuthVerifyResponse.h"
#import "IDXFaceVerifyResponse.h"
#import "IDXImage.h"

@interface IDXService : NSObject

/*!
 * @discussion This initializer must be used to create an instance of an IDXService object.
   @param apiKey A key provided by MorphoTrust. This key will enable access to the Identix service in order to perform biometric facial matching and driver license document authentication.
   @param url The Identix service URL provided to you by MorphoTrust.
 */
- (id)initWithAPIKey:(NSString *)apiKey identixURL:(NSString *)url;

/*!
 * @discussion This function is used to match two faces. For instance, this function can be used to compare a selfie with the portrait extracted from a driver license.
   @param faceImage1 An instance of IDXImage that contains the image of a face and the desired compression quality.
   @param faceImage2 An instance of IDXImage that contains the image of a face and the desired compression quality.
   @param success A block that if executed will return an IDXFaceVerifyResponse object called success. This success object will include the match score among other values.
   @param error A block that if executed will return an NSError object called error.
 */
- (void)faceVerify:(IDXImage *)faceImage1 andImage:(IDXImage *)faceImage2 onSuccess:(void (^)(IDXFaceVerifyResponse *))success onError:(void (^)(NSError *))error;

/*!
 * @discussion This function is used to authenticate and extract information from a driver license.
 @param cardFrontImage An instance of IDXImage that contains the image of a driver license and the desired compression quality.
 @param cardBackImage An instance of IDXImage that contains the image of the back of a driver license and the desired compression quality.
 @param signature An enhanced signature returned from the IDXESF framework. May be nil.
 @param success A block that if executed will return an IDXDocAuthVerifyResponse object called success. This success object will include the status and response in JSON format among other values.
 @param error A block that if executed will return an NSError object called error.
 */
- (void)docAuthVerify:(IDXImage *)cardFrontImage backImage:(IDXImage *)cardBackImage withSignature:(NSData *)signature onSuccess:(void (^)(IDXDocAuthVerifyResponse *))success onError:(void (^)(NSError *))error;

@end


