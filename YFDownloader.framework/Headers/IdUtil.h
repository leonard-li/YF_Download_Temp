//
//  IdUtil.h
//  YFDownloader
//
//  Created by leonard.li on 1/23/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IdUtil : NSObject

// 获取 UUID
+ (NSString *)getUUID;

// 计算字符串的 MD5 哈希
+ (NSString *)getMD5:(NSString *)value;

@end

NS_ASSUME_NONNULL_END
