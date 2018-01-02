//
//  IDXFaceVerifyResponse-Private.h
//  IDXProxyService
//
//  Created by Chris Poole on 1/26/16.
//  Copyright © 2016 Morphotrust. All rights reserved.
//

#import <IDXProxyService/IDXFaceVerifyResponse.h>

@interface IDXFaceVerifyResponse()

@property (nonatomic, strong) NSDictionary *responseJSON;

- (id)initWithData:(NSDictionary *)data andTimeInterval:(NSString *)timeInterval;

- (void)setStatus:(NSString *)status;

@end
