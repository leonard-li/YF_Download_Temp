//
//  DownloaderError.h
//  YFDownloader
//
//  Created by leonard.li on 1/23/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DownloaderError : NSObject

// 错误码常量
extern const NSInteger HTTP_ERROR;
extern const NSInteger SIZE_ZERO;
extern const NSInteger INVALID_URL;
extern const NSInteger INVALID_PATH;
extern const NSInteger HTTP_TIMEOUT;
extern const NSInteger IO_ERROR;
extern const NSInteger HOST_ERROR;
extern const NSInteger SLL_ERROR;
extern const NSInteger RENAME_FAIL;
extern const NSInteger SOCKET_ERROR;
extern const NSInteger CONNET_ERROR;
extern const NSInteger CDN_GROUP_ERROR;
extern const NSInteger MAX_RETRY_ERROR;
extern const NSInteger CDN_MAX_ERROR;
extern const NSInteger NET_ERROR;

@property (nonatomic, assign) NSInteger responseCode; // 下载错误 http状态码
@property (nonatomic, strong) NSString *cdn;           // 当前下载的cdn地址
@property (nonatomic, assign) NSInteger code;          // SDK错误码
@property (nonatomic, strong) NSString *msg;           // SDK 回调信息描述

- (instancetype)initWithResponseCode:(NSInteger)responseCode cdn:(NSString *)cdn code:(NSInteger)code msg:(NSString *)msg;
- (NSString *)description;

@end

NS_ASSUME_NONNULL_END
