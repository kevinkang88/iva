#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "NSTRBackScanner.h"
#import "NSTRDeviceFingerprint.h"
#import "NSTREnrichedHeaders.h"
#import "NSTRIPFinder.h"
#import "NSTRNeustarIVA.h"
#import "SimilityBeacon.h"

FOUNDATION_EXPORT double ivaVersionNumber;
FOUNDATION_EXPORT const unsigned char ivaVersionString[];

