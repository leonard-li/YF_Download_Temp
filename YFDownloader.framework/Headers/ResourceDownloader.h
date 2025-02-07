//
//  ResourceDownloader.h
//  YFDownloader
//
//  Created by leonard.li on 1/23/25.
//

#import <Foundation/Foundation.h>
#import <YFDownloader/NetworkUtil.h>
#import <YFDownloader/ResFileManager.h>
#import <YFDownloader/IdUtil.h>
#import <YFDownloader/CdnUtils.h>
#import <YFDownloader/DownloaderError.h>
#import <YFDownloader/TaskResponse.h>
#import <YFDownloader/DownloadConfig.h>
#import <YFDownloader/DownloaderListener.h>

NS_ASSUME_NONNULL_BEGIN

@interface ResourceDownloader : NSObject

+ (instancetype)sharedInstance;

- (void)initSdkWithContext:(id)context
             downloadConfig:(DownloadConfig *)downloadConfig
                  listener:(id<DownloaderListener>)listener;

- (void)createTask:(NSString *)resourcePath
           cdnUrls:(NSArray<Cdn *> *)cdnUrls
         outputDir:(NSString *)outputDir;

- (int)deleteTasksByIds:(NSArray<NSString *> *)taskIds;
- (int)deleteTaskById:(NSString *)taskId;
- (int)deleteTasksByResourcePaths:(NSArray<NSString *> *)resourcePaths;
- (int)deleteTasksByResourcePath:(NSString *)resourcePath;

@end

NS_ASSUME_NONNULL_END
