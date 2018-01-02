//
//  NSTRBackScanner.m
//  IVA-IOS-SDK
//
//  Created by kevin on 12/28/17.
//

#import "NSTRBackScanner.h"
#import <confirm_sdk/confirm_sdk.h>

@interface NSTRBackScanner ()

@property (nonatomic, retain) NSArray *someArray;
@property (nonatomic, strong) ConfirmCapture* confirmCapture;

@end

@implementation NSTRBackScanner

- (id)init {
    if(self = [super init]) {
        ConfirmCapture.captureSession;
    }

    return self;
}
@end
