//
//  IDXImagingHelper-Private.h
//  IDXImage
//
//  Created by Michael Callaghan on 1/25/16.
//  Copyright © 2016 MorphoTrust. All rights reserved.
//

#import <IDXImage/IDXImagingHelper.h>

@interface IDXImagingHelper()

+ (UIImage *)makeUIImageFromCMSampleBuffer:(CMSampleBufferRef)sampleBuffer withPosition:(AVCaptureDevicePosition)position rawImage:(UIImage * __autoreleasing *)rawImage;

@end

