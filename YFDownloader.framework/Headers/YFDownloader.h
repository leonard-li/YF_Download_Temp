//
//  YFDownloader.h
//  YFDownloader
//
//  Created by leonard.li on 1/7/25.
//

#import <Foundation/Foundation.h>

//! Project version number for YFDownloader.
FOUNDATION_EXPORT double YFDownloaderVersionNumber;

//! Project version string for YFDownloader.
FOUNDATION_EXPORT const unsigned char YFDownloaderVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <YFDownloader/PublicHeader.h>

#import <YFDownloader/YFDownloadHelper.h>
#import <YFDownloader/YFDownloadConstant.h>


#import <YFDownloader/CdnUtils.h>
#import <YFDownloader/IdUtil.h>
#import <YFDownloader/NetworkUtil.h>
#import <YFDownloader/ResFileManager.h>

#import <YFDownloader/ResourceDownloader.h>
#import <YFDownloader/ResourceDownloadTask.h>

#import <YFDownloader/DownloadConfig.h>
#import <YFDownloader/DownloaderError.h>
#import <YFDownloader/TaskResponse.h>

#import <YFDownloader/DownloaderAgent.h>
#import <YFDownloader/DownloaderListener.h>



#define YF_DOWNLOADER_VERSION @"1.0.1"
