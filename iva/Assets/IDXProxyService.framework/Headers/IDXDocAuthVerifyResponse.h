//
//  IDXDocAuthVerifyResponse.h
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

@interface IDXDocAuthVerifyResponse : NSObject {
	
}

/*!
 * @brief Information pertaining specifically to the document.
 */
@property (nonatomic, strong, readonly) NSDictionary *folioDocument;
/*!
 * @brief Whether tests passed, failed, or were indeterminate. If no test fails then the status will be passed.
 */
@property (nonatomic, strong, readonly) NSString *status;
/*!
 * @brief Tests performed on the document including scanning for a watermark.
 */
@property (nonatomic, strong, readonly) NSDictionary *tests;
/*!
 * @brief Personal information extracted from the document.
 */
@property (nonatomic, strong, readonly) NSDictionary *folioPerson;
/*!
 * @brief Measurement of how long the request took.
 */
@property (nonatomic, strong, readonly) NSString *networkingTimeInterval;
/*!
 * @brief Response in JSON format.
 */
@property (nonatomic, strong, readonly) NSDictionary *responseJSON;

@end


