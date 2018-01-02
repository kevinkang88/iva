//
//  NSTRNeustarIVA.m
//  IVA-IOS-SDK
//
//  Created by kevin on 11/29/17.
//  Copyright © 2017 yooniverse. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSTRNeustarIVA.h"

@implementation NSTRNeustarIVA

- (id)init {
    return [self initWithDeviceId:nil];
}

- (id)initWithDeviceId:(NSString *)deviceId {
    if((self = [super init])) {
        if(deviceId == nil) deviceId = @"dummyId";
        self.deviceId = deviceId;
        self.applicationId = @"https://fraud.neustar.com";
        self.requestId = 0;
    }

    [OHHTTPStubs stubRequestsPassingTest:^BOOL(NSURLRequest *request) {
        return [request.URL.absoluteString isEqualToString:@"getcarrierinfo.com"];
    } withStubResponse:^OHHTTPStubsResponse*(NSURLRequest *request) {
        NSDictionary* response = @{@"transid":@"58958709", @"errorcode":@"0", @"response":@[@{@"result":@[@{@"element":@"4270",@"errorcode":@"0", @"value":@"{\"links\":{\"carrierUrl\":\"https://snap.mobile.att.net\"},\"data\":{\"nonce\":\"abcd123\",\"sessionID\":\"jVo2a3dfASzF4A2q21FV4Hs32jrB\",\"clientID\":\"e4k6z3a90fe3yn4\"}}" }]}]};
        return [OHHTTPStubsResponse responseWithJSONObject:response statusCode:200 headers:@{@"Content-Type":@"application/json"}];
    }];
    
    return self;
}

- (NSData *)serializeRequestBody:(NSNumber *)requestId withNonce:(NSString *)nonce withDeviceId:(NSString *)deviceId {
    NSDictionary<NSString *, id>* dict = @{@"request-id": requestId,
        @"action": @"identity",
        @"nonce": nonce,
        @"device-id": deviceId,
        @"application-id": [self applicationId]};
    NSArray *json = @[dict];
    
    NSData* jsonData = [NSJSONSerialization dataWithJSONObject:json options:nil error:nil];
    return jsonData;
}

- (AnyPromise *) getCarrier:(NSString *)ipAddr {
    return [AnyPromise promiseWithAdapterBlock:^(PMKAdapter  _Nonnull adapter) {
        AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
        NSDictionary *params = @{@"client_id": @123456};
        [manager POST:@"getcarrierinfo.com" parameters:params success:^(NSURLSessionDataTask * _Nonnull task, id  _Nonnull responseObject) {
            NSLog(@"JSON: %@", responseObject);
            NSError* error;
            adapter(responseObject, error);
        } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
            NSLog(@"Error: %@", error);
            adapter(nil, error);
        }];
    }];
}

- (AnyPromise *) headerEnrichmentRequest:(NSString *)authKey withCarrierUrl:(NSString *)url {
    return [AnyPromise promiseWithAdapterBlock:^(PMKAdapter  _Nonnull adapter) {
        AFHTTPRequestOperationManager *manager = [AFHTTPRequestOperationManager manager];
        manager.requestSerializer = [AFJSONRequestSerializer serializer];
        manager.responseSerializer.acceptableContentTypes = [NSSet setWithObject:@"text/plain"];
        [manager.requestSerializer setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
        NSArray *params = @[@{@"request-id": @0,
                                @"action": @"identity",
                                @"nonce": authKey,
                                @"device-id": @1234,
                                @"application-id": [self applicationId]}];
        [manager POST:url parameters:params success:^(AFHTTPRequestOperation * _Nonnull operation, id  _Nonnull responseObject) {
            NSError* error;
            adapter(responseObject, error);
        } failure:^(AFHTTPRequestOperation * _Nullable operation, NSError * _Nonnull error) {
            adapter(nil, error);
        }];
    }];
};


- (void) startWithCompletion:(void(^)(NSTREnrichedHeaders *header, NSError *error))completionBlock {
    [NSTRIPFinder getPublicIP].then(^(NSString *ipAddr){
        return [self getCarrier:ipAddr];
    }).then(^(NSDictionary *jsonObject){
        NSLog(@"%@", jsonObject);
        NSString* response = [[[[[jsonObject valueForKey:@"response"] objectAtIndex:0] valueForKey:@"result"] objectAtIndex:0] valueForKey:@"value"];
        NSError *jsonError;
        NSData *objectData = [response dataUsingEncoding:NSUTF8StringEncoding];
        NSDictionary *json = [NSJSONSerialization JSONObjectWithData:objectData
                                                                options:NSJSONReadingMutableContainers
                                                                  error:&jsonError];
        
        NSString* authKey = [[json valueForKey:@"data"] valueForKey:@"nonce"];
        NSString* url =  [[json valueForKey:@"links"] valueForKey:@"carrierUrl"];
        
        return [self headerEnrichmentRequest:authKey withCarrierUrl:url];
    }).then(^(NSArray *response){
        NSData *payload = [[response[0] valueForKey:@"data"] dataUsingEncoding:NSUTF8StringEncoding];
        NSTREnrichedHeaders *header = [[NSTREnrichedHeaders alloc] initWithProvider:ATT andEncryptedPayload:payload];
        NSError* error;
        completionBlock(header, error);
    }).catch(^(NSError *error){
        NSLog(@"Error: %@", error);
        completionBlock(nil, error);
    });
}

@end
