//
//  IDXImage.h
//  IDXProxyService
//
//  MTUSA MTUSA MTUSA MTUSA - MorphoTrust USA - MTUSA MTUSA MTUSA MTUSA
//  COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL
//
//  Copyright: 2017 by MorphoTrust USA, LLC. All rights reserved.
//  License: In accordance with MorphoTrust USA’s license agreement.
//  Code Classifaction: COMMERCIAL
//
//  Classification Person: Chris Poole
//  Classification Reason: Software not specific to any U.S. Government Entity
//  Classification Date: 2017
//
//  COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL
//  MTUSA MTUSA MTUSA MTUSA - MorphoTrust USA - MTUSA MTUSA MTUSA MTUSA

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface IDXImage : NSObject

/*!
 * @brief The image property should be an image of a face. This property is read-only and its value can only be set using the initializer described above. After an IDXImage object is initialized, this property’s value can be accessed.
 */
@property (nonatomic, strong, readonly) UIImage *image;

/*!
 * @brief The compressionQuality property is a value on a scale from 0.0 to 1.0. This value will determine the quality of the image after it is compressed. In order to expedite matching in the Identix service, images are compressed before they are sent. A higher value for this property is representative of a higher quality image following compression. Conversely, a lower value for this property represents a lower quality image following compression. This property is read-only and its value can only be set using the initializer described above. After an IDXImage object is initialized, this property’s value can be accessed.
 */
@property (nonatomic, readonly) CGFloat compressionQuality;

/*!
 * @discussion Any IDXImage object must be initialized here.
   @param image The image property should be an image of a face. This property is read-only and its value can only be set using the initializer described above. After an IDXImage object is initialized, this property’s value can be accessed.
   @param compressionQuality The compressionQuality property is a value on a scale from 0.0 to 1.0. This value will determine the quality of the image after it is compressed. In order to expedite matching in the Identix service, images are compressed before they are sent. A higher value for this property is representative of a higher quality image following compression. Conversely, a lower value for this property represents a lower quality image following compression. This property is read-only and its value can only be set using the initializer described above. After an IDXImage object is initialized, this property’s value can be accessed.
 */
- (id)initWithImage:(UIImage *)image andCompressionQuality:(CGFloat)compressionQuality;

@end
