//
//  IDXImagingHelper.h
//  IDXImage
//
//  MTUSA MTUSA MTUSA MTUSA - MorphoTrust USA - MTUSA MTUSA MTUSA MTUSA
//  COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL
//
//  Copyright: 2017 by MorphoTrust USA, LLC. All rights reserved.
//  License: In accordance with MorphoTrust USA’s license agreement.
//  Code Classifaction: COMMERCIAL
//
//  Classification Person: Daniel Poder
//  Classification Reason: Software not specific to any U.S. Government Entity
//  Classification Date: 2017
//
//  COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL
//  MTUSA MTUSA MTUSA MTUSA - MorphoTrust USA - MTUSA MTUSA MTUSA MTUSA

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <AVFoundation/AVFoundation.h>
#import "IDXFaceFeatures.h"

//interface for Video Imaging Utility class
@interface IDXImagingHelper : NSObject

/// @brief Convert a color into an image of that color
+(UIImage *)imageFromColor:(UIColor *)color;

/// @brief Used to convert a CMSampleBuffer to UIImage.  The device orientation is accounted for in correctly orienting the CGImageRef behind the UIImage output.
+(UIImage *)makeUIImageFromCMSampleBuffer:(CMSampleBufferRef)sampleBuffer withPosition:(AVCaptureDevicePosition)position;

/// @brief Return a UIImage from a known data format Grayscale.
/// @discussion [IDXImagingHelper makeUIImageFromGrayScaleData:data withWidth:imageWidth height:imageheight bytesPerRow:imageWidth];
+(UIImage *) makeUIImageFromGrayScaleData:(unsigned char *)data withWidth:(int)width height:(int)height bytesPerRow:(int)bytesPerRow;

/// @brief Return a UIImage from a known data format RGB.
/// @discussion [IDXImagingHelper makeUIImageFromRGBData:data withWidth:imageWidth height:imageheight bytesPerRow:imageWidth];
+(UIImage *) makeUIImageFromRGBData:(unsigned char *)data withWidth:(int)width height:(int)height bytesPerRow:(int)bytesPerRow;

/// @brief Return a UIImage from a known data format BGRA.
/// @discussion [IDXImagingHelper makeUImageFromData:data withWidth:imageWidth height:imageheight bytesPerRow:imageWidth];
+(UIImage *) makeUIImageFromBGRAData:(unsigned char *)data withWidth:(int)width height:(int)height bytesPerRow:(int)bytesPerRow;

/// @brief Return a UIImage from a known data format RGBA.
/// @discussion [IDXImagingHelper makeUImageFromData:data withWidth:imageWidth height:imageheight bytesPerRow:imageWidth];
+(UIImage *) makeUIImageFromRGBAData:(unsigned char *)data withWidth:(int)width height:(int)height bytesPerRow:(int)bytesPerRow;

/// @brief Return a UIImage from a known data format BGRA, caller must free the returned unsigned char*.
/// @discussion [IDXImagingHelper makeUImageFromData:data withWidth:imageWidth height:imageheight bytesPerRow:imageWidth];
+(unsigned char *) convertBGRAtoRGB:(unsigned char *)data withWidth:(int)width height:(int)height bytesPerRow:(int)bytesPerRow;

@end

@interface UIImage (IDXImagingHelper)

/// @brief Return 0-100 scale of focus for the given image.
-(int)calculateFocus;
/// @brief Return 0-100 scale of focus for the given image.
-(int)calculateFocusScore: (int)step
                     skip: (int)skip
              edgePercent: (int)edgePercent; // new image gradient based method

/// @brief Return a brightness  Range 0-255 (0 black, 255 white).
-(int)calculateBrightness;
/// @brief Return a brightness  Range 0-255 (0 black, 255 white).
-(int)calculateBrightness:(CGRect)rect;
/// @brief Return a brightness  Range 0-255 (0 black, 255 white).
-(int)calculateBrightness:(int)clrs edgePercentSkip:(int)percent;


/// @brief Return an unsigned char *, caller must free the returned unsigned char*.
-(unsigned char *)makeDataArray;

/// @brief Determine whether UIImage is grayScale.
-(BOOL)isGrayScale;

/// @brief Convert UIImage to grayScale using CoreImage.
-(UIImage *)makeGrayScale;

/// @brief Convert a UIIMage to grayscale with a scale factor.
-(UIImage *)makeGrayScaleAndScale:(int)scalar;

/*!
 * @discussion This function takes as input a UIImage that has the face oriented in portrait format.
 @param accuracy The accuracy at which the client would like to detect a face inside of an image. There are only two available options- FaceDetectionAccuracyHigh and FaceDetectionAccuracyLow.
 @return A IDXFaceFeatures object containing the detected facial features.
 */
-(IDXFaceFeatures)getIDXFaceFeaturesWithAccuracy:(FaceDetectionAccuracy)accuracy;

/*!
 * @discussion This function takes as input a UIImage that has the face oriented in portrait format.
 @param accuracy The accuracy at which the client would like to detect a face inside of an image. There are only two available options- FaceDetectionAccuracyHigh and FaceDetectionAccuracyLow.
 @param withLogging By default logging is disabled.
 @return A IDXFaceFeatures object containing the detected facial features.
 */
-(IDXFaceFeatures)getIDXFaceFeaturesWithAccuracy:(FaceDetectionAccuracy)accuracy withLogging:(BOOL)verbose;

/// @brief Draw indicators on the face for eyes, and mouth.
-(UIImage *)drawFacialLocationsLeftEye:(CGPoint)leftEye rightEye:(CGPoint)rightEye mouth:(CGPoint)mouth faceBox:(CGRect)faceRect;

/// @brief  Draw text into a UIImage at specified location, font size, and color.
-(UIImage *)drawText:(NSString*) text  atPoint:(CGPoint) point atColor:(UIColor *) color fontSize:(int)size;

/// @brief Resize Image.
-(UIImage *)resizeToSize:(CGSize)newSize;

/*! @brief Crop Image (Scaled based on IMAGE coordinates of the actual image size)
 *  @discussion CGRect is assumed to be Image coordinates. Use 0 for PaddingPercent if you do not want to pad the crop box.  Use 75 if you are passing in a FaceRect bounds (from the iOS face finder) as this will properly crop the entire head.
 */
 -(UIImage *)cropImageAtCoordinates:(CGRect)rectOrig withPaddingPercent:(float)percent ;
 
 /*! @brief Return a cropped CGImage (Scaled based on screen coordinates to the actual image size).
  *  @discussion CGRect is assumed to be Screen coordinates use 0 for PaddingPercent if you do not want to pad the crop box.  Use 75 if you are passing in a FaceRect bounds (from the iOS face finder) as this will properly crop the entire head.
  */
 -(UIImage *)cropImageAtCoordinates:(CGRect)rectOrig withPaddingPercent:(float)percent viewSize:(CGSize)viewSize;
 
 /// @brief Return a rotated image based on the angle parameter (45, 90, etc...).
 -(UIImage *)rotatedByAngle:(CGFloat)angle;
 
 /// @brief Return an image with the contents of the rectangle
- (UIImage *)imageAtRect:(CGRect)rect;

/// @brief Return an image scaled proportionally to the specified minimum size
 - (UIImage *)imageByScalingProportionallyToMinimumSize:(CGSize)targetSize;

/// @brief Return an image scaled proportionally to the specified size
- (UIImage *)imageByScalingProportionallyToSize:(CGSize)targetSize;
/// @brief Return an image scaled to the specified size
- (UIImage *)imageByScalingToSize:(CGSize)targetSize;
/// @brief Return an image rotated by the specified number of radians
- (UIImage *)imageRotatedByRadians:(CGFloat)radians;
/// @brief Return an image rotated by the specified number of degrees
- (UIImage *)imageRotatedByDegrees:(CGFloat)degrees;
 
 @end
 
