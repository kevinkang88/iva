//
//  SimilityBeacon.h
//  SimilityBeacon
//
//  Created by Anupam on 10/16/15.
//  Copyright © 2015 Simility. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <CoreTelephony/CTCarrier.h>

@interface SimilityContext : NSObject
@property (nonatomic, nonnull) NSString* customerId;
@property (nonatomic, nullable) NSString* sessionId;
@property (nonatomic, nullable) NSString* userId;
@property (nonatomic, nullable) NSDictionary* metadata;
@property (nonatomic, nullable) NSString* zone;
@property (nonatomic, nullable) NSString* requestEndpoint;
@property (nonatomic, nullable) NSString* eventTypes;
@property (nonatomic, nullable) NSString* transactionSubCustomerId;
@property (nonatomic, nullable) NSString* transactionInfo;
@property (nonatomic, nullable) NSMutableArray* transactionEntries;
- (void) addTransactionEntry:(NSString * _Nonnull) entity id:(NSString * _Nonnull) id fields:(NSDictionary * _Nullable) fields;
@end

@interface SimilityScript : NSObject
/*!
 @brief Simility API. It will collect signals in background and send it to server.
 @discussion
 Example Usage:
 @code
 SimilityContext *similityContext = [[SimilityContext alloc] init];
 [similityContext setCustomerId:@"prudentcompany"];
 [SimilityScript execute:similityContext];
 @endcode
 Your application should link following frameworks/libs - Foundation, UIKit, CoreTelephony, Security and CommonCrypto. Also add AdSupport if your application displays advertisements.
 @see http://developer.simility.com/ for more information.
 @param similityContext
 required, Please refer developer docs for detailed example.
 */
+ (void) execute:(SimilityContext * _Nonnull) similityContext;
@end

@interface SimilityBeacon : NSObject

/*!
 @brief Simility API. It will collect signals in background and send it to server.
 @discussion
 Example Usage:
 @code
 SimilityContext *similityContext = [[SimilityContext alloc] init];
 [similityContext setCustomerId:@"prudentcompany"];
 [SimilityBeacon initBeacon:similityContext];
 @endcode
 Your application should link following frameworks/libs - Foundation, UIKit, CoreTelephony, Security and CommonCrypto. Also add AdSupport if your application displays advertisements.
 @see http://developer.simility.com/ for more information.
 @param similityContext
 required, Please refer developer docs for detailed example.
 */
+ (void) initBeacon:(SimilityContext * _Nonnull) similityContext;

/*!
 @brief Simility API. It will collect signals in background and send it to server.
 @discussion
 Example Usage:
 @code
 [SimilityBeacon initBeacon:@"prudentcompany" sessionId:@"cae1234567"];
 @endcode
 Your application should link following frameworks/libs - Foundation, UIKit, CoreTelephony, Security and CommonCrypto. Also add AdSupport if your application displays advertisements.
 @see http://developer.simility.com/ for more information.
 @param customerId
 required, The assigned unique id issued to the customer.
 @param sessionId
 optional, The session Id of the transaction. This can be whatever internal identification number you use in your organization.
 */
+ (void) initBeacon:(NSString * _Nonnull) customerId sessionId:(NSString * _Nullable) sessionId;

/*!
 @brief Simility API. It will collect signals in background and send it to server.
 @discussion
 Example Usage:
 @code
 [SimilityBeacon initBeacon:@"prudentcompany" sessionId:@"cae1234567" userId:@"user1"];
 @endcode
 Your application should link following frameworks/libs - Foundation, UIKit, CoreTelephony, Security and CommonCrypto. Also add AdSupport if your application displays advertisements.
 @see http://developer.simility.com/ for more information.
 @param customerId
 required, The assigned unique id issued to the customer.
 @param sessionId
 optional, The session Id of the transaction. This can be whatever internal identification number you use in your organization.
 @param userId
 optional, The user Id of current user. This can be whatever internal identification you use in your organization.
 */
+ (void) initBeacon:(NSString * _Nonnull) customerId sessionId:(NSString * _Nullable) sessionId userId:(NSString * _Nullable) userId;

/*!
 @brief Simility API. It will collect signals in background and send it to server.
 @discussion
 Example Usage:
 @code
    NSDictionary *metadata = @{@"orderId" : @"order_no_8765456"};
    [SimilityBeacon initBeacon:@"prudentcompany" sessionId:@"cae1234567" userId:@"user1" metadata:metadata];
 @endcode
 Your application should link following frameworks/libs - Foundation, UIKit, CoreTelephony, Security and CommonCrypto. Also add AdSupport if your application displays advertisements.
 @see http://developer.simility.com/ for more information.
 @param customerId
        required, The assigned unique id issued to the customer.
 @param sessionId
        optional, The session Id of the transaction. This can be whatever internal identification number you use in your organization.
 @param userId
        optional, The user Id of current user. This can be whatever internal identification you use in your organization.
 @param metadata
        optional, <key, value>  entry of NSDictionary must be of type <string, string>. It can be used to specify additional information like category, location etc.
 */
+ (void) initBeacon:(NSString * _Nonnull) customerId sessionId:(NSString * _Nullable) sessionId userId:(NSString * _Nullable) userId metadata:(NSDictionary *_Nullable) metadata;


/*!
 @brief Simility API. It will collect signals in background and send it to specified requestEndpoint.
 @discussion
 Example Usage:
 @code
    NSDictionary *metadata = @{@"orderId" : @"order_no_8765456"};
    [SimilityBeacon initBeacon:@"prudentcompany" sessionId:@"cae1234567" userId:@"user1" metadata:metadata requestEndpoint:@"https://yourdomain.com/path"];
 @endcode
 Your application should link following frameworks/libs - Foundation, UIKit, CoreTelephony, Security and CommonCrypto. Also add AdSupport if your application displays advertisements.
 @see http://developer.simility.com/ for more information.
 @param customerId
    required, The assigned unique id issued to the customer.
 @param sessionId
    optional, The session Id of the transaction. This can be whatever internal identification number you use in your organization.
 @param userId
    optional, The user Id of current user. This can be whatever internal identification you use in your organization.
 @param metadata
    optional, <key, value>  entry of NSDictionary must be of type <string, string>. It can be used to specify additional information like category, location etc.
 @param requestEndpoint
    optional, Complete URL string where HTTP GET request will be sent.
 */
+ (void) initBeacon:(NSString * _Nonnull) customerId sessionId:(NSString * _Nullable) sessionId userId:(NSString * _Nullable) userId metadata:(NSDictionary *_Nullable) metadata requestEndpoint:(NSString * _Nullable) requestEndpoint;


/*!
 @brief Simility API. It will collect signals in background and send it to server.
 @discussion
 Example Usage:
 @code
    NSDictionary *metadata = @{@"orderId" : @"order_no_8765456"};
    [SimilityBeacon initBeacon:@"prudentcompany" sessionId:@"cae1234567" userId:@"user1" metadata:metadata transactionInfo:@"[{\"id\":\"1001\",\"entity\":\"orders\",\"fields\":{\"buyer_email\":\"example@example.com\"}}]"];
 @endcode
 Your application should link following frameworks/libs - Foundation, UIKit, CoreTelephony, Security and CommonCrypto. Also add AdSupport if your application displays advertisements.
 @see http://developer.simility.com/ for more information.
 @param customerId
    required, The assigned unique id issued to the customer.
 @param sessionId
    optional, The session Id of the transaction. This can be whatever internal identification number you use in your organization.
 @param userId
    optional, The user Id of current user. This can be whatever internal identification you use in your organization.
 @param metadata
    optional, <key, value>  entry of NSDictionary must be of type <string, string>. It can be used to specify additional information like category, location etc.
 @param transactionInfo
    optional, If you are sending transaction data. You can specify string of JSONObject which follows format as described at http://developer.simility.com/#service-upload-post
 */
+ (void)initBeacon:(NSString * _Nonnull) customerId sessionId:(NSString * _Nullable) sessionId userId:(NSString * _Nullable) userId metadata:(NSDictionary * _Nullable) metadata transactionInfo:(NSString * _Nullable)transactionInfo;


/*!
 @brief Simility API. It will collect signals in background and send it to specified requestEndpoint.
 @discussion
 Example Usage:
 @code
    NSDictionary *metadata = @{@"orderId" : @"order_no_8765456"};
    [SimilityBeacon initBeacon:@"prudentcompany" sessionId:@"cae1234567" userId:@"user1" metadata:metadata transactionInfo:@"[{\"id\":\"1001\",\"entity\":\"orders\",\"fields\":{\"buyer_email\":\"example@example.com\"}}]" requestEndpoint:@"https://yourdomain.com/path"];
 @endcode
 Your application should link following frameworks/libs - Foundation, UIKit, CoreTelephony, Security and CommonCrypto. Also add AdSupport if your application displays advertisements.
 @see http://developer.simility.com/ for more information.
 @param customerId
    required, The assigned unique id issued to the customer.
 @param sessionId
    optional, The session Id of the transaction. This can be whatever internal identification number you use in your organization.
 @param userId
    optional, The user Id of current user. This can be whatever internal identification you use in your organization.
 @param metadata
    optional, <key, value>  entry of NSDictionary must be of type <string, string>. It can be used to specify additional information like category, location etc.
 @param transactionInfo
    optional, If you are sending transaction data. You can specify string of JSONObject which follows format as described at http://developer.simility.com/#service-upload-post
 @param requestEndpoint
    optional, Complete URL string where HTTP GET request will be sent.
 */
+ (void)initBeacon:(NSString * _Nonnull) customerId sessionId:(NSString * _Nullable) sessionId userId:(NSString * _Nullable) userId metadata:(NSDictionary * _Nullable) metadata transactionInfo:(NSString * _Nullable)transactionInfo requestEndpoint:(NSString * _Nullable) requestEndpoint;


/*!
 @brief Simility API. It will collect signals in background and send it to server.
 @discussion
 Example Usage:
 @code
    NSDictionary *metadata = @{@"orderId" : @"order_no_8765456"};
    [SimilityBeacon initBeacon:@"prudentcompany" sessionId:@"cae1234567" userId:@"user1" metadata:metadata transactionSubCustomerId:@"customer1" transactionInfo:@"[{\"id\":\"1001\",\"entity\":\"orders\",\"fields\":{\"buyer_email\":\"example@example.com\"}}]"];
 @endcode
 Your application should link following frameworks/libs - Foundation, UIKit, CoreTelephony, Security and CommonCrypto. Also add AdSupport if your application displays advertisements.
 @see http://developer.simility.com/ for more information.
 @param customerId
    required, The assigned unique id issued to the customer.
 @param sessionId
    optional, The session Id of the transaction. This can be whatever internal identification number you use in your organization.
 @param userId
    optional, The user Id of current user. This can be whatever internal identification you use in your organization.
 @param metadata
    optional, <key, value>  entry of NSDictionary must be of type <string, string>. It can be used to specify additional information like category, location etc.
 @param transactionSubCustomerId
    optional, If you are sending transaction data. You can use this field to distinguish between transaction of your sub customers.
 @param transactionInfo
    optional, If you are sending transaction data. You can specify string of JSONObject which follows format as described at http://developer.simility.com/#service-upload-post
 */
+ (void) initBeacon:(NSString * _Nonnull) customerId sessionId:(NSString * _Nullable) sessionId userId:(NSString * _Nullable) userId metadata:(NSDictionary *   _Nullable) metadata transactionSubCustomerId:(NSString * _Nullable) transactionSubCustomerId transactionInfo:(NSString * _Nullable) transactionInfo;


/*!
 @brief Simility API. It will collect signals in background and send it to specified requestEndpoint.
 @discussion
 Example Usage:
 @code
    NSDictionary *metadata = @{@"orderId" : @"order_no_8765456"};
    [SimilityBeacon initBeacon:@"prudentcompany" sessionId:@"cae1234567" userId:@"user1" metadata:metadata transactionSubCustomerId:@"customer1" transactionInfo:@"[{\"id\":\"1001\",\"entity\":\"orders\",\"fields\":{\"buyer_email\":\"example@example.com\"}}]" requestEndpoint:@"https://yourdomain.com/path"];
 @endcode
 Your application should link following frameworks/libs - Foundation, UIKit, CoreTelephony, Security and CommonCrypto. Also add AdSupport if your application displays advertisements.
 @see http://developer.simility.com/ for more information.
 @param customerId
    required, The assigned unique id issued to the customer.
 @param sessionId
    optional, The session Id of the transaction. This can be whatever internal identification number you use in your organization.
 @param userId
    optional, The user Id of current user. This can be whatever internal identification you use in your organization.
 @param metadata
    optional, <key, value>  entry of NSDictionary must be of type <string, string>. It can be used to specify additional information like category, location etc.
 @param transactionSubCustomerId
    optional, If you are sending transaction data. You can use this field to distinguish between transaction of your sub customers.
 @param transactionInfo
    optional, If you are sending transaction data. You can specify string of JSONObject which follows format as described at http://developer.simility.com/#service-upload-post
 @param requestEndpoint
    optional, Complete URL string where HTTP GET request will be sent.
 */
+ (void) initBeacon:(NSString * _Nonnull) customerId sessionId:(NSString * _Nullable) sessionId userId:(NSString * _Nullable) userId metadata:(NSDictionary * _Nullable) metadata transactionSubCustomerId:(NSString * _Nullable) transactionSubCustomerId transactionInfo:(NSString * _Nullable) transactionInfo requestEndpoint:(NSString * _Nullable) requestEndpoint;

@end
