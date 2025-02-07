//
//  YFDownloadConstant.h
//  YFDownloader
//
//  Created by leonard.li on 1/7/25.
//
#import <YFCore/YFCore.h>

#ifndef YFDownloadConstant_h
#define YFDownloadConstant_h

#define YFDHLogError(frmt, ...)   if ([UIDevice currentDevice].testDevice) LOG_MAYBE(NO,                LOG_LEVEL_DEF, YFSKLogFlagError,   0, @"下载工具", __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define YFDHLogWarn(frmt, ...)    if ([UIDevice currentDevice].testDevice) LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, YFSKLogFlagWarning, 0, @"下载工具", __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define YFDHLogInfo(frmt, ...)    if ([UIDevice currentDevice].testDevice) LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, YFSKLogFlagInfo,    0, @"下载工具", __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define YFDHLogDebug(frmt, ...)   if ([UIDevice currentDevice].testDevice) LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, YFSKLogFlagDebug,   0, @"下载工具", __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define YFDHLogVerbose(frmt, ...) if ([UIDevice currentDevice].testDevice) LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, YFSKLogFlagVerbose, 0, @"下载工具", __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#endif /* YFDownloadConstant_h */

static NSUInteger const maxRetryCount = 3;

//下载错误类型
typedef NS_ENUM(NSUInteger, YFDownloadErrorCode) {
    DHTTPError = 101,                          // 资源路径有问题
    DFileExistError = 102,                     // 资源已存在, 无需重新下载
    DNetworkError = 103,                       // 无网络
};

//下载状态
typedef NS_ENUM(uint32_t, YFDownloadStatus) {
    DSUnstarted = 1,          // 未开始
    DSDownloading = 2,        // 进行中
    DSWaitForRetry = 3,       // 等待重试 - 每个CDN都试过且失败了
    DSCompleted = 4,          // 已完成
    DSFailed = 5,             // 失败 - 每个CDN都试过且失败后, 重复3次还是失败
};


//public class DownLoaderCode {
//    ////单个cdn下载失败的情况 10 开头
//    int HTTP_ERROR = 101;//responseCode！=200  例如responseCode 404 资源绝对路径有问题
//    int SIZE_ZERO = 102;//待下载的文件大小为 0
//
//    int INVALID_URL = 103;//MalformedURLException url对象创建有问题 url地址无效
//    int INVALID_PATH = 104;//FileNotFoundException 文件下载后存储路径有问题
//    int HTTP_TIMEOUT = 105;//SocketTimeoutException http连接或读取超时
//
//    int IO_ERROR = 106;//IOException http单次请求不通过都报这个错误
//    int HOST_ERROR = 107;//UnknownHostException cdn地址错误 无网络导致访问cdn地址错误
//    int SLL_ERROR = 108;//SSLException http下载过程中网络连接中断
//
//    //一轮cdn列表下载失败
//    int CDNS_ERROR = 201;//cdn一轮循环下载失败
//
//    //超过重试次数失败
//    int MAX_RETRY_ERROR = 202;//超过重试次数下载失败了 当此启动不再重试
//
//    //下载任务开始前检查网络情况 网络异常将停止下载任务
//    int NET_ERROR = 401;//网络异常
//}
