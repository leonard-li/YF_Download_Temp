//
//  ResFileManager.h
//  YFDownloader
//
//  Created by leonard.li on 1/23/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ResFileManager : NSObject

// 初始化资源管理器
+ (void)initWithContext;

// 获取资源下载根目录
+ (NSString *)getResRootPath;

// 通过文件名称获取资源路径
+ (NSString *)getZipPath:(NSString *)recId;

@end

NS_ASSUME_NONNULL_END
