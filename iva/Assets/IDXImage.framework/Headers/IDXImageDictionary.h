//
//  IDXImageDictionary.h
//  IDXImage
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
#import <UIKit/UIKit.h>

@interface IDXImageDictionary : NSObject

/// @brief Save the CGImageRef as a PNG file to the App document folder for given file name.
/// @param imageRef CGImageRef of image.
/// @param name Filename of image.
+(BOOL)saveImageAsPNG:(CGImageRef)imageRef fileName:(NSString *)name;

/// @brief Load image file from the App document folder with given file name.
/// @param name Filename of image.
+(UIImage *)loadImageWithFileName:(NSString *)name;

/// @brief Delete files from the App document folder.
/// @discussion [IDXImagingHelper deleteImageFromNSDocumentDictorywithFileName:@"*" extension:"png"] - deletes all files with extension png.
/// [IDXImagingHelper deleteImageFromNSDocumentDictorywithFileName:@"*" extension:"*"] - deletes all files.
/// [IDXImagingHelper deleteImageFromNSDocumentDictorywithFileName:@"file1" extension:"png"] - deletes the file file1.png.
/// @param name Filename of image.
/// @param extension Filename extension.
+(void)deleteImageWithFileName:(NSString *)fileName fileExtension:(NSString *)extension;

@end
