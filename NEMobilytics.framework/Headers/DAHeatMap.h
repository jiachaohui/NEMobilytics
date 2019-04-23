//
//  DAHeatMap.h
//  Mobilytics
//
//  Created by jiazhh on 2019/4/16.
//  Copyright © 2019 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "DAHeatMapConfiguration.h"
#import "DAHeatMapPrivilege.h"
#import "DAHeatMapModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^HeatMapEnabledBlock)(NSError* error);
typedef void(^HeatMapConfigBlock)(DAHeatMapConfiguration* defaultConfiguration);

@class DAHeatMap;
@protocol DAHeatMapDelegate <NSObject>

/* 拦截热图数据，自己进行处理；
 * 返回值为YES，则中断默认绘制流程，由app处理数据显示；
 * 返回NO，则继续默认绘制流程
 */
- (BOOL)heatMap:(DAHeatMap*)heatmap didReceiveResponse:(NSDictionary*)response;

/*
 * 拦截热图绘制流程，可以自己决定绘制方式
 */
- (BOOL)heatMap:(DAHeatMap*)heatmap willRenderViews:(NSArray*)views onSnapshot:(UIView*)snapshotView;

/*
 * 编辑服务端返回response数据，并继续绘制流程
 */
- (NSDictionary*)heatMap:(DAHeatMap*)heatmap filterResponse:(NSDictionary*)response;

@end


@interface DAHeatMap : NSObject

//热图配置属性，如userId,appkey等
@property(nonatomic, strong, readonly) DAHeatMapConfiguration   *config;

//热图权限，开启热图功能后才可以使用
@property(nonatomic, strong, readonly) DAHeatMapPrivilege       *privilege;

//代理对象，可以拦截热图流程
@property(nonatomic, weak, nullable) id<DAHeatMapDelegate>      delegate;

//当前热图功能是否已经启用
@property(nonatomic, assign, readonly) BOOL isRunning;

// 单例模式，被tracker对象持有
+ (instancetype)sharedInstance;

// 开启热图模式
// 如果返回NSError对象为空，则可以使用privilege检查用户权限
- (void)runWithConfiguration:(HeatMapConfigBlock)configBlock completion:(HeatMapEnabledBlock)completeBlock;
// 手动触发更新热图
- (void)update;

// 手动更新模式下，更新指定的views，而非自动遍历全部views
- (void)updateModels:(NSArray<DAHeatMapModel*>*)models;

// 停止热图模式
- (void)stopRunning;

@end

NS_ASSUME_NONNULL_END
