//
//  YFDownloadHelper.h
//  YFDownloader
//
//  Created by leonard.li on 1/7/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol YFDownloadDelegate<NSObject>

@optional

/**
 *  @brief 下载开始
 *  @param path 待下载资源url地址除去域名的部分
 *  @note  无
 */
- (void)yfDownloadStart:(NSString *)path;

/**
 *  @brief 下载结束
 *  @param path 待下载资源url地址除去域名的部分
 *  @note  无
 */
- (void)yfDownloadEnd:(NSString *)path;

/**
 *  @brief 下载进度
 *  @param path 待下载资源url地址除去域名的部分
 *  @param CDN CDN地址
 *  @param progress  下载进度
 *  @note  无
 */
- (void)yfDownloading:(NSString *)path withCDN:(NSString *)CDN withProgress:(NSProgress * _Nonnull)progress;

/**
 *  @brief 下载成功
 *  @param path 待下载资源url地址除去域名的部分
 *  @param CDN CDN地址
 *  @param dir  保存到本地的沙盒路径
 *  @param retryCount  重试次数
 *  @note  无
 */
- (void)yfDownloadSuccess:(NSString *)path withCDN:(NSString *)CDN withDir:(NSString *)dir withRetry:(NSUInteger)retryCount;

/**
 *  @brief 下载失败
 *  @param path 待下载资源url地址除去域名的部分
 *  @param CDN CDN地址
 *  @param retryCount  重试次数
 *  @param error  错误信息
 *  @note  无
 */
- (void)yfDownloadFailed:(nullable NSString *)path withCDN:(nullable NSString *)CDN withRetry:(NSUInteger)retryCount withError:(nullable NSError*)error;

@end

@interface YFDownloadConfigSettings : NSObject

@property(nonatomic, assign) NSTimeInterval retryCount; // 重试次数

@property(nonatomic, assign) NSTimeInterval timeoutInterval; // 请求超时间隔(单位秒), 默认60秒

@property(nonatomic, assign) BOOL rewriteExistFile; // 下载相同path的文件是覆盖还是跳过, 默认NO=跳过

@property(nonatomic, strong) NSDictionary<NSString *, NSNumber *> *CDNConfig; // CDN配置信息, 以CDN为key, 重试次数为value, 例: @{@"cdn1":3, @"cdn2":2, @"cdn3":1}

@end

@interface YFDownloadHelper : NSObject

@property(nonatomic, weak) id<YFDownloadDelegate> delegate;

@property(nonatomic, readwrite, strong) YFDownloadConfigSettings *configSettings;

+ (YFDownloadHelper *)initWithSettings:(nullable YFDownloadConfigSettings *)configSettings
                          withDelegate:(nullable id<YFDownloadDelegate>) delegate;

/**
 *  @brief 下载
 *  @param path 待下载资源url地址除去域名的部分, 例如: 资源的完整下载路径为: https://www.baidu.com/img/PCtm_d9c8750bed0b3c7d089fa7d55720d6cf.png, 对应的path则为 img/PCtm_d9c8750bed0b3c7d089fa7d55720d6cf.png
 *  @param completion 完成回调
 */
+ (void)downloadWithPath:(NSString *)path completion:(dispatch_block_t)completion;
/**
 *  @brief 下载
 *  @param paths 待下载资源url地址除去域名的部分的集合, 例如: 资源的完整下载路径为: https://www.baidu.com/img/PCtm_d9c8750bed0b3c7d089fa7d55720d6cf.png, 对应的path则为 img/PCtm_d9c8750bed0b3c7d089fa7d55720d6cf.png
 *  @param completion 完成回调, successPaths: 下载成功的path集合, failPaths: 下载失败的path集合
 */
+ (void)downloadWithPaths:(NSArray<NSString *> *)paths completion:(void(^)(NSArray<NSString *> * _Nullable successPaths, NSArray<NSString *> * _Nullable failPaths))completion;

/**
 *  @brief 获取下载失败的path集合
 */
+ (NSArray<NSString *> *)getDownloadFailedPath;

/**
 *  @brief 根据资源url获取保存到沙盒的路径
 *  @param path 待下载资源url地址除去域名的部分, 例如: 资源的完整下载路径为: https://www.baidu.com/img/PCtm_d9c8750bed0b3c7d089fa7d55720d6cf.png, 对应的path则为 img/PCtm_d9c8750bed0b3c7d089fa7d55720d6cf.png
 */
+ (NSString *)getFilePath:(NSString *)path;

/**
 *  @brief 根据资源url删除沙盒中对应的文件
 *  @param path 待下载资源url地址除去域名的部分, 例如: 资源的完整下载路径为: https://www.baidu.com/img/PCtm_d9c8750bed0b3c7d089fa7d55720d6cf.png, 对应的path则为 img/PCtm_d9c8750bed0b3c7d089fa7d55720d6cf.png
 */
+ (void)deleteFile:(NSString *)path;

@end

NS_ASSUME_NONNULL_END
