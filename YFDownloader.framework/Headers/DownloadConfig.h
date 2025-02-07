//
//  DownloadConfig.h
//  YFDownloader
//
//  Created by leonard.li on 1/23/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DownloadConfig : NSObject

@property (nonatomic, assign) NSInteger retryCount;         // 任务重试次数
@property (nonatomic, assign) NSInteger retryInterval;      // 任务重试时间间隔（单位：秒）
@property (nonatomic, assign) NSInteger connectTimeout;     // http连接超时时间（秒）不设置默认 15秒
@property (nonatomic, assign) NSInteger readTimeout;        // http读取操作超时时间 （秒）不设置默认 30秒

/**
 *  @brief 初始化配置
 *  @param retryCount 任务重试次数
 *  @param retryInterval 任务重试时间间隔（单位：秒）
 */
- (instancetype)initWithRetryCount:(NSInteger)retryCount retryInterval:(NSInteger)retryInterval;

- (NSString *)description;

@end

NS_ASSUME_NONNULL_END
