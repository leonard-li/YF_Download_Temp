//
//  DownloaderListener.h
//  YFDownloader
//
//  Created by leonard.li on 1/23/25.
//
#import <YFDownloader/ResourceDownloader.h>
#import <YFDownloader/DownloadConfig.h>
#import <YFDownloader/ResourceDownloadTask.h>
#import <YFDownloader/DownloaderListener.h>
#import <YFDownloader/ResFileManager.h>

#ifndef DownloaderListener_h
#define DownloaderListener_h


@protocol DownloaderListener <NSObject>

// 资源开始下载回调 回调下载任务对象
- (void)onDownloadStart:(ResourceDownloadTask *)task;

// 下载进度回调
- (void)onDownloadProgress:(ResourceDownloadTask *)task
                 totalSize:(long)totalSize
                loadedSize:(long)loadedSize;

// 下载完成回调
- (void)onDownloadSuccess:(ResourceDownloadTask *)task
             fileSavePath:(NSString *)fileSavePath
                      cdn:(NSString *)cdn
             downloadSize:(long)downloadSize;

// 下载失败回调
- (void)onDownloadFail:(ResourceDownloadTask *)task
       downloaderError:(DownloaderError *)downloaderError;

// 提交任务回调
- (void)onCreateTask:(ResourceDownloadTask *)task
         taskResponse:(TaskResponse *)taskResponse;

@end

#endif /* DownloaderListener_h */
