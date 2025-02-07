//
//  NetworkUtil.h
//  YFDownloader
//
//  Created by leonard.li on 1/23/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NetworkUtil : NSObject

+ (instancetype)sharedInstance;

// 检查网络是否可用
- (BOOL)isNetworkAvailable;

// 检查网络类型（WiFi/蜂窝网络等）
- (NSString *)networkType;

@end

NS_ASSUME_NONNULL_END
