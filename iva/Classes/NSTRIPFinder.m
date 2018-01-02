//
//  NSTRIPFinder.m
//  IVA-IOS-SDK
//
//  Created by kevin on 11/30/17.
//  Copyright © 2017 yooniverse. All rights reserved.
//
#import "NSTRIPFinder.h"

@implementation NSTRIPFinder

+(AnyPromise *)getPublicIP {
    return [AnyPromise promiseWithAdapterBlock:^(PMKAdapter  _Nonnull adapter) {
        NSURL *url = [NSURL URLWithString:@"http://checkip.dyndns.org"];
        NSURLRequest *request = [NSURLRequest requestWithURL:url];
        [[[NSURLSession sharedSession]dataTaskWithRequest:request completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
            
            NSString *html = [[NSString alloc]initWithData:data encoding:NSUTF8StringEncoding];
            NSCharacterSet *numbers = [NSCharacterSet characterSetWithCharactersInString:@"0123456789."];
            NSString *ipAddr = [[html componentsSeparatedByCharactersInSet:numbers.invertedSet]componentsJoinedByString:@""];
            adapter(ipAddr,error);
        }]resume];
    }];
}

@end
