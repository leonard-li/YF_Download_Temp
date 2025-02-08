//
//  ResourceDownloadTask.h
//  YFDownloader
//
//  Created by leonard.li on 1/23/25.
//

#import <Foundation/Foundation.h>
#import <YFDownloader/CdnUtils.h>

NS_ASSUME_NONNULL_BEGIN

@interface ResourceDownloadTask : NSObject

@property (nonatomic, assign) int taskId; // 数据库自增 ID
@property (nonatomic, copy) NSString *uniqueTaskId; // 唯一标识任务
@property (nonatomic, copy) NSString *resourcePath; // 资源的本地路径标识
@property (nonatomic, strong) NSArray<Cdn *> *cdnUrls; // 下载的目标 CDN 列表
@property (nonatomic, copy) NSString *outputDir; // 文件下载根目录
@property (nonatomic, copy) NSString *status; // 任务状态
@property (nonatomic, assign) int retryCount; // 重试次数
@property (nonatomic, assign) NSTimeInterval nextRetryTime; // 下一次重试的时间戳
@property (nonatomic, assign) int cdnCount; // 单 CDN 下载累计次数
@property (nonatomic, copy) NSString *loadCdn; // 当前下载中的 CDN
@property (nonatomic, assign) int isFirst; // 是否是首次任务下载 0:首次；1:非首次；默认1非首次

- (instancetype)initWithTaskId:(NSString *)taskId
                  resourcePath:(NSString *)resourcePath
                      cdnUrls:(NSArray<Cdn *> *)cdnUrls
                    outputDir:(NSString *)outputDir;

- (void)calculateNextRetryTime:(NSTimeInterval)retryInterval;

@end

NS_ASSUME_NONNULL_END
