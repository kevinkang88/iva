//
//  IDXCameraRollHelper.h
//  IDXImage
//
//  Created by Michael Callaghan on 1/26/16.
//  Copyright © 2016 MorphoTrust. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@interface IDXCameraRollHelper : NSObject

+ (IDXCameraRollHelper *)getInstance;

- (BOOL)startSavingCameraData;
- (BOOL)appendCameraData:(CMSampleBufferRef)sampleBuffer;
- (BOOL)stopSavingCameraData;
- (void)saveImageToCameraRoll:(UIImage *)image imageDescription:(NSString *)imageDescription;

@end
