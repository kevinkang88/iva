//
//  IDXFaceFeatures.h
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

/*!
 * @brief These are the features of a face that have been detected in an image after calling the getIDXFaceFeaturesWithAccuracy function.
 */
typedef struct
{
    CGRect bounds;
    CGPoint leftEye;
    CGPoint rightEye;
    CGPoint mouth;
    float faceAngle;
    BOOL smile;
    BOOL leftEyeBlinking;
    BOOL rightEyeBlinking;
    int featureCount;
} IDXFaceFeatures;

/*!
 * @brief The accuracy at which the client would like to detect a face inside of an image. There are only two available options- FaceDetectionAccuracyHigh and FaceDetectionAccuracyLow.
 */
typedef NS_ENUM(NSInteger, FaceDetectionAccuracy) {
    FaceDetectionAccuracyLow,
    FaceDetectionAccuracyHigh
};
