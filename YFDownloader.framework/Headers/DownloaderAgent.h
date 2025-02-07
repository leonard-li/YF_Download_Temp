//
//  DownloaderAgent.h
//  YFDownloader
//
//  Created by leonard.li on 1/23/25.
//

#import <Foundation/Foundation.h>
#import <YFDownloader/ResourceDownloader.h>
#import <YFDownloader/DownloadConfig.h>
#import <YFDownloader/DownloaderListener.h>
#import <YFDownloader/ResFileManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface DownloaderAgent : NSObject

/**
 * 初始化SDK并启动下载任务
 * @param config 下载相关配置信息
 * @param listener 下载相关监听回调
 */
+ (void)initSDKWithConfig:(DownloadConfig *)config
              listener:(id<DownloaderListener>)listener;

/**
 * 创建待下载的资源任务
 * @param resourcePath 待下载的资源相对路径
 * @param cdnUrls cdn域名列表
 * @param outputDir 资源下载后存储完整文件路径
 */
+ (void)createDownloadTaskWithResourcePath:(NSString *)resourcePath
                                  cdnUrls:(NSArray<Cdn *> *)cdnUrls
                                outputDir:(NSString *)outputDir;

/**
 * 创建待下载的资源任务
 * 不设置outputDir，使用游戏默认根目录: 游戏默认缓存根目录/GameResourse/
 * @param resourcePath
 * @param cdnUrls
 */
+ (void)createDownloadTaskWithResourcePath:(NSString *)resourcePath
                                  cdnUrls:(NSArray<Cdn *> *)cdnUrls;

/**
 * 根据任务id删除任务 用于资源相对路径下载失败使用 responseCode = 404 的情况
 * @param taskId
 * @return
 */
+ (int)deleteTaskById:(NSString *)taskId;

/**
 * 根据资源相对路径删除任务 用于资源相对路径下载失败使用 responseCode = 404 的情况
 * @param resourcePath
 * @return
 */
+ (int)deleteTasksByResourcePath:(NSString *)resourcePath;

@end

NS_ASSUME_NONNULL_END
