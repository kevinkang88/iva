//
//  IDXIdentixCardDetect.h
//  IDXCardDetect
//
//  MTUSA MTUSA MTUSA MTUSA - MorphoTrust USA - MTUSA MTUSA MTUSA MTUSA
//  COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL
//
//  Copyright: 2017 by MorphoTrust USA, LLC. All rights reserved.
//  License: In accordance with MorphoTrust USA’s license agreement.
//  Code Classifaction: COMMERCIAL
//
//  Classification Person: Ted Wu
//  Classification Reason: Software not specific to any U.S. Government Entity
//  Classification Date: 2017
//
//  COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL
//  MTUSA MTUSA MTUSA MTUSA - MorphoTrust USA - MTUSA MTUSA MTUSA MTUSA

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreImage/CoreImage.h>
#import <ImageIO/ImageIO.h>

#import <CoreMedia/CoreMedia.h>

struct IDXQuality
{
    /// Boolean indicates whether the image has poor overall quality based on the values of focus, exposure, and color
    bool  poorQuality;
    /// The clarity/blurriness of the image
    float focus;
    /// The lighting/brightness of the image
    float exposure;
    /// The color density of the pixels of the image
    float color;
    /// Reserved for use in a future release
    float glare;
    /// Reserved for use in a future release
    float esf;
    /// Reserved for use in a future release
    float fakeid;
};

/*!
  @brief An enum to specify the document type
 */
typedef NS_ENUM(NSInteger, DocumentType) {
    /// License document type
    DocumentTypeLicense,
    /// Passport document type
    DocumentTypePassport
};


@interface IDXCardDetect : NSObject

typedef void (^detectCardCompletionBlock)(UIImage *cardImage, CGPoint *corners, float *score);

/*! 
 *  @brief Detects the card image on the input image.
 *  @discussion This method checks for the specified document type, license (ex: driver’s license or identification card) or passport.  Currently those are the only supported document types. For best results, the card should be placed on a dark background with minimal contrast.
 *  @param image The image to scan
 *  @param completionBlock The detectCardCompletionBlock to be called when the method completes
 */
+ (void)detectCard:(UIImage *)image completed:(detectCardCompletionBlock)completionBlock;

/*! 
 *  @brief Calculates the image quality of the input image. The quality measurements are the focus clarity, exposure, color density and glare.
 *  @param image The image on which quality is to be calculated
 *  @return An IDXQuality struct indicating the image quality
 */
+ (struct IDXQuality)calcQuality:(UIImage *)image;

@end

