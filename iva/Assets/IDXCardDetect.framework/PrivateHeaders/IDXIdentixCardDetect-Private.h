//
//  IDXIdentixCardDetect-Private.h
//  IDXCardDetect
//
//  Created by Michael DiNicola on 9/8/16.
//  Copyright © 2016 MorphoTrust. All rights reserved.
//

#import <IDXCardDetect/IDXIdentixCardDetect.h>

#define _MIN_FOCUS      50
#define _MIN_EXPOSURE   30
#define _MAX_GLARE      2000

@interface IDXCardDetect()

+ (BOOL) checkCorners:(CGPoint *)corners withImage:(UIImage *)currentFrame;

/*!
 @brief Card detection call supporting algorithm flags
 
 @discussion Flags allow caller to specify the mode of operation for card segmentation.  See details below for uiFlags
 
 @param <b>(UIImage*) image</b> specifies the input image
 
 @param <b>(unsigned int) uiFlags</b> indicates algorithm operation mode
 uiFlags < = 0 will give original every-other-frame Gray-H-Gray-H.... functionality
 uiFlags   = 1 will give Gray functionality
 uiFlags   = 2 will give H functionality
 uiFlags   = 3 (1+2) will give Gray AND H functionality, returning the result with the best overall quality score
 
 @param <b>(detectCardCompletionBlock)</b> specifies the handler to callback when processing is complete
 */
+ (void)detectCard:(UIImage *)image withAlgoFlags:(unsigned int)uiFlags documentType:(DocumentType)documentType completed:(detectCardCompletionBlock)completionBlock;

+ (float)calcFocus:(UIImage *)image;
+ (struct IDXQuality)calcQualityFromPixels:(char*)pPixels
                                ofWidth:(int)nWidth
                               ofHeight:(int)nHeight
                          ofBytesPerPix:(int)nBytesPerPixel;

+ (struct IDXQuality)calcQualityGradient:(UIImage *)image;

//JRM 2016-06-09 : alternate implementation of Vincent's glare heatmap - should be faster
//but might give slightly different results
+ (UIImage*) QuickGlareHeatmap:(UIImage*)image
               withTargetWidth:(int)nTargetW
                     andHeight:(int)nTargetH
                      oriented:(UIImageOrientation)imgOrientation
                     withAlpha:(unsigned char)ucAlpha;

//JRM 2016-06-13 : attempting to get around some of the conversion slowdown

+ (UIImage *)QuickGlareHeatmapFromCMSampleBuffer:(CMSampleBufferRef)sampleBuffer
                                 withTargetWidth:(int)nTargetW
                                       andHeight:(int)nTargetH
                                        oriented:(UIImageOrientation)imgOrientation
                                       withAlpha:(unsigned char)ucAlpha;

+ (UIImage*) QuickGlareHeatmapFromCMSampleBuffer:(CMSampleBufferRef)sampleBuffer
                                        oriented:(UIImageOrientation)imgOrientation
                                       withAlpha:(unsigned char)ucAlpha
                                      getHotspot:(CGPoint*) ptHotspot
                                     getStrength:(float*)fHotspot
                                   withThreshold:(double)glareThreshold;

//JRM 2016-06-23 : return location of brightest hotspot on card
+ (UIImage*) QuickGlareHeatmap:(UIImage*)image withTargetWidth:(int)nTargetW andHeight:(int)nTargetH oriented:(UIImageOrientation)imgOrientation withAlpha:(unsigned char)ucAlpha getHotspot:(CGPoint*) ptHotspot getStrength:(float*)fHotspot withThreshold:(double)glareThreshold;

/*!
 * @discussion This function applies bilateral filtering to the input image. The filtering reduces unwanted noise while keeping sharp edges to improve the selfie to DL matching quality. It is normally slower than other image smoothing filters, such as the Gaussian filter.
 @param image Color or grayscale image declared as a UIImage type.
 @param size The size of the filter. A larger size will result in stronger smoothing and take longer time to process. The size value must be a positive integer. It is recommended not to exceed a size greater than 15.
 @param sigmaColor Filter sigma in the color space. A larger value means that farther colors within the pixel neighborhood will be mixed together, resulting in larger areas of semi-equal color. This value must be a positive integer. There is no provided value range because the value is very specific to the image size and application type.
 @param sigmaSpace Filter sigma in the coordinate space. A larger value means that farther pixels will influence each other as long as their colors are close enough. This value must be a positive integer. There is no provided value range because the value is very specific to the image size and application type.
 @return The filtered image.
 */
+ (UIImage *)bilateralFilter:(UIImage *)image filterSize:(int)size sigmaColor:(float)sigmaColor sigmaSpace:(float)sigmaSpace;

+(void) saveBufferToSandbox:(unsigned char*)pBuffer withWidth:(int)w withHeight:(int)h withBytePerPixel:(int)Bpp withBGROrder:(bool)bBGROrder withName:(NSString*)strName;

//#ifdef _USE_IDXCardMetrics
+ (void) calcESFMetrics:(UIImage*)image withFaceRect:(CGRect*)face returnESF:(float*) pESF returnFakeID:(float*) pFakeID;
//#endif  //_USE_IDXCardMetrics

+ (void) calcESFMetricsOnFullImage:(UIImage*)image returnESF:(float*) pESF returnFakeID:(float*)pFakeID withDPI:(int*)pKnownDPI;

@end
