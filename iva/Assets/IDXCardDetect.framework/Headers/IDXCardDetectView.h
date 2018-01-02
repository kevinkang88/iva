//
//  IDXCardDetectView.h
//  IDXCardDetect
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

//Card Detect Delegate functions
@protocol IDXCardDetectDelegate <NSObject>

@required
/*!
 * @discussion This delegate protocol is fired when the ESF detection process is completed (either by time out or successful detection of ESF data). This delegate function is required.
 @param image The payload object that contains the parsed ESF data.
 */
-(void)detectCompleted:(UIImage *)image;

@optional
/*!
 * @discussion This delegate protocol is fired when the library encounters an error attempting to decode the ESF. This delegate function is optional.
 @param message A string description of an error that took place during attempted detection.
 */
-(void)detectError:(NSString *)message;

@end

//SDK interface
@interface IDXCardDetectView : UIView

/*!
 * @brief In order for IDXCardDetectDelegate functions to work properly in the client app, this property must be set to self.
 */
@property (nonatomic, weak) id<IDXCardDetectDelegate> delegate;

/*!
 * @brief When saveEnergy is set to True the library will stop the video camera after each ESF detection.  This conserves battery life on the phone.  The drawback is that each time the video camera is started there is a focus adjustment which can make rapid scanning of ESFs slower. Default value is True.
 */
@property (nonatomic) BOOL saveEnergy;

/*!
 * @discussion This function starts the video feed (using the rear camera) and displays the video feed. The function searches the video frames for the presense of a ESF.  Once detected, the ESF data is parsed to the MorphoTrust specifications for US Driver’s Licenses.  The parsed data is returned using the delegate callback detectCompleted.
     @param maxDurationInSeconds Indicates how long to analyze the video frames for an ESF/ESF before timing out.
 */
-(void)startDetect:(int)maxDurationInSeconds;

/*!
 * @discussion This function forcibly stops the detection method.
 */
-(void)stopDetect;

@end

