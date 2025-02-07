//
//  TaskResponse.h
//  YFDownloader
//
//  Created by leonard.li on 1/23/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TaskResponse : NSObject

//TaskResponseStatus状态
typedef NS_ENUM(NSInteger, TaskResponseStatus) {
    FIRST_TASK = 301,
    FAILED_TASK = 302,
    COMPLETED_TASK = 303,
    IN_PROGRESS_TASK = 304,
    PAUSE_TASK = 305,
    ERROR = 306,
    CDN_LIST_NULL = 307,
    CDN_TO_JSON_ERRO = 308,
    RES_PATH_NULL = 309,
    OUTPUT_DIR_NULL = 310,
};

// 状态码常量
//extern const NSInteger FIRST_TASK;
//extern const NSInteger FAILED_TASK;
//extern const NSInteger COMPLETED_TASK;
//extern const NSInteger IN_PROGRESS_TASK;
//extern const NSInteger PAUSE_TASK;
//extern const NSInteger ERROR;
//extern const NSInteger CDN_LIST_NULL;
//extern const NSInteger CDN_TO_JSON_ERRO;
//extern const NSInteger RES_PATH_NULL;
//extern const NSInteger OUTPUT_DIR_NULL;

@property (nonatomic, assign) NSInteger code; // 创建任务状态码
@property (nonatomic, strong) NSString *msg;  // 创建任务信息

- (instancetype)initWithCode:(NSInteger)code msg:(NSString *)msg;
- (NSString *)description;

@end

NS_ASSUME_NONNULL_END
