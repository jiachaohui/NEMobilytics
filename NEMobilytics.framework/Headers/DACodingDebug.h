//
//  DACodingDebug.h
//  HubbleData
//
//  Created by CaiSanze on 2018/6/8.
//  Copyright © 2018年 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DATracker;
@class DAVersion;

/**
 编程调试类
 */
@interface DACodingDebug : NSObject

/**
 ABTest试验变量名称
 */
@property (nonatomic, copy) NSString *variableName;

/**
 编程调试是否处于连接状态
 */
@property (nonatomic, assign) BOOL isCodingDebugConnecting;

/**
 当前选中的版本对象
 */
@property (nonatomic, strong) DAVersion *selectedVersion;

/**
 上一次上传的截图HASH
 */
@property (nonatomic, copy) NSString *lastScreenHash;

/**
 初始化
 
 @param tracker DATracker
 @return DACodingDebug
 */
- (instancetype)initWithSDK:(DATracker *)tracker;

- (void)updateVersionInfo:(NSArray *)versionInfo;

/**
 添加和删除编程调试按钮
 */
- (void)addVersionBtnWithPushMessage:(BOOL)pushMessage;
- (void)removeVersionBtn;

/**
 显示和隐藏版本选择列表视图
 */
- (void)showVersionListView;
- (void)hideVersionListViewWithCompletion:(void (^)(void))completion;


/**
 传递编程事件

 @param eventInfo 事件信息
 */
- (void)uploadDebugEventInfo:(NSString *)eventInfo;

/**
 强制关闭连接
 */
- (void)connectCodingDebugWithToken:(NSString *)token;
- (void)disconnectCodingDebug;

@end
