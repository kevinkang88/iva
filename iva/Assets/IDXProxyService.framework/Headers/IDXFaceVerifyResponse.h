//
//  IDXFaceVerifyResponse.h
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

@interface IDXFaceVerifyResponse : NSObject {

}

/*!
 * @brief Each match attempted is regarded as a transaction and assigned a unique identifier. That unique identifier is assigned to the value of this property. This property is read-only and will only be set in this framework after a match between two faces has been attempted.
 */
@property (nonatomic, strong, readonly) NSString *tcn;

/*!
 * @brief The value of this property will be set to the status of the match. A successful match will set the value to “Successful”, however the match score will be the true indicator of how successful a match is. This property is read-only and will only be set in this framework after a match between two faces has been attempted.
 */
@property (nonatomic, strong, readonly) NSString *status;

/*!
 * @brief The match score represents the chance of the match being a false match. This is called the False Accept Rate. The score is minus the log base 10 of the expected false accept rate. A simple way to think of this is to look at the score as the number of zeros in a 1 in X chance of being a false match. So, if you get a score of 5, that record has a 1 in 100,000 chance of being the wrong person (there are 5 zeros in 100,000). If you get a score of 3, that record has a 1 in 1,000 chance of being the wrong person. If you get a score of 10, that record has a 1 in 10,000,000,000 chance of being the wrong person.
 */
@property (nonatomic, readonly) float score;

/*!
 * @brief The value of this property is the amount of time taken to compare two faces and determine a match score. It is represented in the format: Hours:Minutes:Seconds:Milliseconds
 */
@property (nonatomic, strong, readonly)NSString *networkingTimeInterval;

@end
