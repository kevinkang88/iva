//
//  IDXService-Private.h
//  IDXProxyService
//
//  Created by Michael Callaghan on 2/11/16.
//  Copyright © 2016 Morphotrust. All rights reserved.
//

#import <IDXProxyService/IDXService.h>

@interface IDXService()

typedef NS_ENUM(NSInteger, DocAuthStrategy) {
    DocAuthStrategyDeep
};

@property (nonatomic, strong) NSString *identixURL;
@property (nonatomic, strong) NSString *identixAPIKey;
@property (nonatomic) BOOL allowInvalidCertificates;

/*!
 * @discussion This function is used to authenticate and extract information from a driver license.
 @param cardFrontImage An instance of IDXImage that contains the image of the front of a driver license and the desired compression quality.
 @param cardBackImage An instance of IDXImage that contains the image of the back of a driver license and the desired compression quality.
 @param strategy The strategy of the document authentication to use. Deep uses MorphoTrust's document authentication capability.
 @param success A block that if executed will return a IDXDocAuthVerifyResponse object called success. This success object will include the status and response in JSON format among other values.
 @param error A block that if executed will return an NSError object called error.
 */
- (void)docAuthVerify:(IDXImage *)cardFrontImage backImage:(IDXImage *)cardBackImage ofDocumentType:(NSString *)documentType onSuccess:(void (^)(IDXDocAuthVerifyResponse *))success onError:(void (^)(NSError *))error;

@end
