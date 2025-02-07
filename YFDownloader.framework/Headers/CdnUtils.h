//
//  CdnUtils.h
//  YFDownloader
//
//  Created by leonard.li on 1/23/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Cdn : NSObject

@property (nonatomic, strong) NSString *cdn; // 当前下载的cdn地址
@property (nonatomic, assign) NSInteger count; // cdn重试次数

- (instancetype)initWithCdn:(NSString *)cdn count:(NSInteger)count;
- (NSString *)description;

@end

@interface CdnUtils : NSObject

+ (NSString *)serialize:(NSArray<Cdn *> *)cdnList;
+ (NSArray<Cdn *> *)deserialize:(NSString *)cdnUrlsText;

@end

NS_ASSUME_NONNULL_END
