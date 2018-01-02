//
//  IDXVideoHelper.h
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

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <AVFoundation/AVFoundation.h>

/// @brief Callback delegate for receiving the captured output.
@protocol IDXVideoHelperDelegate <NSObject>

@optional
/// @brief Implement this delegate method to get the buffer frames after you startVideoCapture.
-(void)getLastSampleBuffer:(CMSampleBufferRef)lastCMSampleBufferRef faceRect:(CGRect)face faceYawAngle:(CGFloat)yawAngle faceRollAngle:(CGFloat)rollAngle barcodeData:(NSString *)data;
/// @brief Implement this delegate method to get the results of takeStillPicture.
-(void)getNewStillImage:(UIImage *)stillImage;

@end

//interface for Video Imaging Utility class
@interface IDXVideoHelper : NSObject

/// @brief IDXVideoHelperDelegate property
@property (nonatomic, weak) id<IDXVideoHelperDelegate> delegate;
/// @brief AVCaptureVideoPreviewLayer property
@property (nonatomic, strong) AVCaptureVideoPreviewLayer *previewLayer;
/// @brief AVCaptureSession property
@property (nonatomic, strong) AVCaptureSession *session;
/// @brief AVCaptureDevice property
@property (nonatomic, strong) AVCaptureDevice *device;

/// @brief Turns on/off the box around the face showing face is in center.
@property (nonatomic) BOOL showCenterBox;
/// @brief Turns on/off the box around the face in the previewlayer.
@property (nonatomic) BOOL showFaceBoundingBox;
/// @brief Turns on/off the box around a barcode (PDF 417, QR code, etc) in the previewlayer.
@property (nonatomic) BOOL showBarcodeBoundingBox;
/// @brief Used for centering the head and reduction of image distortion on selfies.
@property (nonatomic) CGFloat minHeadSize;
/// @brief Used for centering the head and reduction of image distortion on selfies.
@property (nonatomic) CGFloat maxHeadSize;
/// @brief Used to set flash mode (Automatic, On, Off).
@property (nonatomic) AVCaptureFlashMode flashMode;
/// @brief Calls the AVCaptureFocusModeAutoFocus.
@property (nonatomic) AVCaptureAutoFocusRangeRestriction autoFocusRange;

//AVMetaObjectType Support --- Default: Face and PDF417 are enabled
/// @brief Enable/disable face finding support in video.
@property (nonatomic) BOOL faceFindSupport;
/// @brief Enable/disable PDF417 barcode reading support in video.
@property (nonatomic) BOOL pdf417Support;
/// @brief Enable/disable QR Code barcode reading support in video.
@property (nonatomic) BOOL qrCodeSupport;

/// @brief Card detection threshold.
@property (nonatomic) double cardDetectionThreshold;

/// @brief Bool indicates whether card rect detection should be attempted.
@property (nonatomic) BOOL shouldDetectCardRect;

/// @brief Clear stored card rectangle data.
-(void)clearCardRectData;

/// @brief init function to setup the Video session.
/// @discussion avLayerVideoGravity can either be: AVLayerVideoGravityResizeAspectFill or AVLayerVideoGravityResizeAspect. ESF must use AVLayerVideoGravityResizeAspect. Typical pixelformats: kCVPixelFormatType_420YpCbCr8BiPlanarFullRange - HC ESF & kCVPixelFormatType_32BGRA - Image processing.
- (id)initWithAVCaptureSessionPreset:(NSString *)avPreset devicePosition:(AVCaptureDevicePosition) position previewVideoGravity:(NSString *) avLayerVideoGravity pixelFormat:(int)pixelFormat;

//Instance Methods
/// @brief Start the video camera, output is sent to the getLastSampleBuffer delegate.
-(void)startVideoCapture;
/// @brief Stop the video camera.
-(void)stopVideoCapture;
/// @brief Toggle the camera device in use (Front/Back).
-(void)toggleCameraWithAnimation:(BOOL)animate;
/// @brief Takes a still image, output is sent to the getNewStillImage delegate (startVideoCapture must be called first).
-(void)takeStillPicture;
/// @brief Call the AVCaptureFocusModeAutoFocus.
-(void)autoFocusCamera;
/// @brief Call the AVCaptureFocusMode and set it to continuous.
-(void)autoFocusContinuousCamera;
/// @brief Return a UIView that shows the live video preview, set size equal to how big on the screen you want the video.
-(UIView *)getPreviewView:(CGRect)viewSize withCenterBox:(BOOL)showBox;
/// @brief Call this method to reset the detected barcode data, needed for iOS 8.
-(void)clearBarcodeData;
/// @brief Call this method to reset the face detection data, needed for iOS 8.
-(void)clearFaceData;

/// @brief (Property Setter Overload) used for centering the head and reduction of image distortion on selfies.
-(void)setMinHeadSize:(CGFloat)minHeadSize maxHeadSize:(CGFloat)maxHeadSize;
/// @brief Turn on LED as a torch with brightness level 0.1 - 1.0.
-(void)enableTorchWithLevel:(float)brightness;
/// @brief Turn off the LED torch.
-(void)disableTorch;

@end
