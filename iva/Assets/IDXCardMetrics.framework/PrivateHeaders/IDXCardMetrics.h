//
//  IDXCardMetrics.h
//  IDXCardMetrics
//
//  MTUSA MTUSA MTUSA MTUSA - MorphoTrust USA - MTUSA MTUSA MTUSA MTUSA
//  COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL
//
//  Copyright: 2017 by MorphoTrust USA, LLC. All rights reserved.
//  License: In accordance with MorphoTrust USA’s license agreement.
//  Code Classifaction: COMMERCIAL
//
//  Classification Person: Joseph Mayer
//  Classification Reason: Software not specific to any U.S. Government Entity
//  Classification Date: 2017
//
//  COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL - COMMERCIAL
//  MTUSA MTUSA MTUSA MTUSA - MorphoTrust USA - MTUSA MTUSA MTUSA MTUSA

#import <UIKit/UIKit.h>

//! Project version number for IDXCardMetrics.
FOUNDATION_EXPORT double IDXCardMetricsVersionNumber;

//! Project version string for IDXCardMetrics.
FOUNDATION_EXPORT const unsigned char IDXCardMetricsVersionString[];


// *******************************************************************
// **
// ** ESF Metric  (requires accurate DPI estimate)
// **
// *******************************************************************

//
//Evaluates the ESF signal strength prediction and FakeID prediction metrics given a raw image buffer (3 channel RGB only?)
//and eye positions representing the main portrait image within a DL card
//If the DPI is not specified (pKnownDPI=NULL) the intereye distance will be assumed to be a known
//fixed physcial size (1/4" ?) and DPI will be estimated from that measurement
//Returns a score indicating detection of ESF-feature-like data.
//  0 = none detected, 10,000 (or more) indicates significant ESF feature-like characteristics detected
//  Scores may extend up to 20,000 or more.  More feedback is required to link the significance
//  of the raw score to the likelihood of detection of an actual ESF.
//
//NOTE : Currently the secondary ROI (used for FakeID prediction) is hard coded to
//       be relative to the portrait image of a specific state (CA?)
//
FOUNDATION_EXPORT float EvalESFFromBufferWithEyes(unsigned char *pImage,  //[IN]  input image buffer bytes
                                                        int nWidth,             //[IN]  width of input image
                                                        int nHeight,            //[IN]  height of input image
                                                        int nChannels,          //[IN]  color channels of input image
                                                        int *pKnownDPI,         //[IN,Optional] DPI if known, otherwise pass NULL and we estimate based on Eyes
                                                        int lx, int ly,         //[IN]  left eye coordinates of main portrait image
                                                        int rx, int ry,         //[IN]  right eye coordinates of main portrait image
                                                        float *pIDFake,         //[OUT,Optional] return prediction of fake ID based on inconsistent ESF signal
                                                        UIImage **ppMask,       //[OUT,Optional] return mask of ESF like feature locations
                                                        UIImage **ppOverlay);   //[OUT,Optional] return overlay of ppMask on input image

//
//Accept a UIImage directly, extract buffer and call "EvalESFFromBufferWithEyes"
//NOTE: The UIImage must consist of a CGImage internally (internal CIImage not currently supported)
//
FOUNDATION_EXPORT float EvalESFFromUIImageWithEyes(UIImage *pImage,        //[IN]  input image in UIImage format
                                                         int *pKnownDPI,         //[IN,Optional] DPI if known, otherwise pass NULL and we estimate based on Eyes
                                                         int lx, int ly,         //[IN]  left eye coordinates of main portrait image
                                                         int rx, int ry,         //[IN]  right eye coordinates of main portrait image
                                                         float *pIDFake,         //[OUT,Optional] return prediction of fake ID based on inconsistent ESF signal
                                                         UIImage **ppMask,       //[OUT,Optional] return mask of ESF like feature locations
                                                         UIImage **ppOverlay);   //[OUT,Optional] return overlay of ppMask on input image



//
//Evaluates the ESF signal strength prediction and FakeID prediction metrics given a raw image buffer  (3 channel RGB only?)
//and one or more ROI rectangles.  Note that FakeID evaluation requires 2 (or more) input ROIs
//If the DPI is not specified (pKnownDPI=NULL) the input image will be assumed to be a segmented card image
//and the size of the card will be assumed to be the standard  "ID-1" size and shape (85.60 × 53.98 mm , 3.370 × 2.125 in)
//and the DPI will be calculated from the image dims and assumed physical size.
//Returns a score indicating detection of ESF-feature-like data.
//  0 = none detected, 10,000 (or more) indicates significant ESF feature-like characteristics detected
//  Scores may extend up to 20,000 or more.  More feedback is required to link the significance
//  of the raw score to the likelihood of detection of an actual ESF.
//
FOUNDATION_EXPORT float EvalESFFromBufferWithRects(unsigned char *pImage,     //[IN]  input image buffer bytes
                                                         int nWidth,                //[IN]  width of input image
                                                         int nHeight,               //[IN]  height of input image
                                                         int nChannels,             //[IN]  color channels of input image
                                                         int *pKnownDPI,            //[IN,Optional] DPI if known, otherwise pass NULL and we estimate
                                                         CGRect *pROIs,             //[IN]  pointer to one or more CGRects definine the ROIs to evaluate
                                                         int nROIs,                 //[IN]  count of ROIs pointed at by pROIs
                                                         float *pIDFake,            //[OUT,Optional] return prediction of fake ID based on inconsistent ESF signal
                                                         UIImage **ppMask,          //[OUT,Optional] return mask of ESF like feature locations
                                                         UIImage **ppOverlay);      //[OUT,Optional] return overlay of ppMask on input image

//
//Accepts a UIImage directly, extracts buffer and calls "EvalESFFromBufferWithRects
//NOTE: The UIImage must consist of a CGImage internally (internal CIImage not currently supported)
//
FOUNDATION_EXPORT float EvalESFFromUIImageWithRects(UIImage *pImage,     //[IN] input image in UIImage format (CGImage ONLY)
                                                         int *pKnownDPI,       //[IN,Optional] DPI if known, otherwise pass NULL and we estimate
                                                         CGRect *pROIs,        //[IN] pointer to one or more CGRects definine the ROIs to evaluate
                                                         int nROIs,            //[IN] count of ROIs pointed at by pROIs
                                                         float *pIDFake,       //[OUT,Optional] return prediction of fake ID based on inconsistent ESF signal
                                                         UIImage **ppMask,     //[OUT,Optional] return mask of ESF like feature locations
                                                         UIImage **ppOverlay); //[OUT,Optional] return overlay of ppMask on input image


// *******************************************************************
// **
// ** Glare Metric (does not require accurate DPI estimate)
// **
// *******************************************************************

//
//Takes raw image buffer, 1 (gray) or 3 (RGB color) channels and determines if glare is present in the image
//Optionally returns a UIImage that is a mask indicating where Glare was detected
//Mask is binary valued (0,0,0) for pixels with no glare, (255,255,255) for pixel with glare.  Alpha is unused.
//Optionally returns a UIImage that overlays the mask on the input image
//Overlay is RGB, alpha is unused.
//Function returns a value related to how much glare was detected in the image. 0 = no glare, 10000 = completely glare covered
//
FOUNDATION_EXPORT float EvalGlareFromBuffer(  unsigned char *pImage,  //[IN] input image buffer to process
                                                    int nWidth,             //[IN] img buffer width
                                                    int nHeight,            //[IN] img buffer height
                                                    int nChannels,          //[IN] img buffer depth 1 or 3 bytes per pixel
                                                    float fWorkingScale,    //[IN] working scale, less than 1 to downsample
                                                    UIImage **ppMask,       //[OUT, optional] glare mask
                                                    UIImage **ppOverlay);   //[OUT, optional] glare overlaid on input image



//
//Accepts a UIImage direcly, extracts buffer and calls "EvalGlareFromBuffer"
//NOTE: The UIImage must consist of a CGImage internally (internal CIImage not currently supported)
//
FOUNDATION_EXPORT float EvalGlareFromUIImage(UIImage *imageIn,           //[IN] image to process
                                                   float fWorkingScale,        //[IN] working scale, less than one to downsample
                                                   UIImage **ppMask,           //[OUT,optional] request glare mask
                                                   UIImage **ppOverlay);       //[OUT,optional] request glare overlaid on input image





//JRM 2016-06-08 : this will build a custom heatmap
//  currently only 0/1 for Noglare/Glare will map to clear/red
//  but may eventually add dual threshold and get clear/yellow/red
//  allow user to select the alpha level of the overlay pixels
FOUNDATION_EXPORT UIImage * HeatmapImageFromBuffer(unsigned char *pBytes,
                                                         int nWidth,
                                                         int nHeight,
                                                         int nChannels,
                                                         float fDisplayScale,
                                                         UIImageOrientation imgOrient,
                                                         unsigned char ucAlpha);



