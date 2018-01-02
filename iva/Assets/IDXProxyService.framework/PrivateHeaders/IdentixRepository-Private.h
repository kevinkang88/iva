//
//  IdentixRepository-Private.h
//  IDXProxyService
//
//  Created by Michael DiNicola on 11/14/16.
//  Copyright © 2016 Morphotrust. All rights reserved.
//

#import <IDXProxyService/IdentixRepository.h>

@interface IdentixRepository()

- (void)postWithUrl:(NSString *)url withRootUrl:(NSString *)rootUrl andBody:(NSString *)body constructingBodyWithBlock:(void (^)(id<IDXMultipartFormData>))formData onSuccess:(void (^)(id))success onError:(void (^)(NSError *))error;

@end
