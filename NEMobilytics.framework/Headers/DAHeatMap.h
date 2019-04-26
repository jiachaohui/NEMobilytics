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
#import "DAHeatMapResponseModel.h"
#import "DAHeatMapRenderView.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^HeatMapEnabledBlock)(NSError* error);
typedef void(^HeatMapConfigBlock)(DAHeatMapConfiguration* defaultConfiguration);

@class DAHeatMap;

@protocol DAHeatMapDelegate <NSObject>

@optional
/*
 * 拦截热图数据，app自己负责数据和展示的处理；
 * 返回值为YES，则中断默认绘制流程，由app处理数据显示；
 * 返回NO，则继续默认处理和绘制流程
 */
- (BOOL)heatMap:(DAHeatMap *)heatMap didReceiveResponse:(NSArray<DAHeatMapResponseModel *> *)responseModels;

/*
 * 热图数据请求失败
 */
- (void)heatMap:(DAHeatMap *)heatMap failedReceiveResponseForModels:(NSArray<DAHeatMapModel *> *)models error:(NSError*)error;

/*
 * 拦截热图绘制流程，可以自己决定绘制方式,views对象是有SDK生成的渲染结果view，snapshotView是截屏的view对象
 */
- (BOOL)heatMap:(DAHeatMap *)heatMap willRenderViews:(NSArray<DAHeatMapRenderView *> *)renderViews onSnapshot:(UIView *)snapshotView;

/*
 * 编辑服务端返回response数据，并继续绘制流程
 */
- (NSArray<DAHeatMapResponseModel *> *)heatMap:(DAHeatMap *)heatMap filterResponse:(NSArray<DAHeatMapResponseModel *> *)response;

/*
 * 成功获取到用户token;在此之后热图才算真正开始运行(isRunning=YES)
 */
- (void)heatMap:(DAHeatMap *)heatMap didReceiveToken:(NSString *)token;

/*
 * 获取热图token失败；请根据error信息提供正确的参数，再重新调用run方法
 */
- (void)heatMap:(DAHeatMap *)heatMap failedReceiveToken:(NSError *)error;

/*
 * 热图功能已停止，资源已经释放;error为空时表示调用stopRunning方法正常停止
 */
- (void)heatMap:(DAHeatMap *)heatMap didStoppedWithError:(nullable NSError *)error;

@end


@interface DAHeatMap : NSObject

//热图配置属性，如userId,appkey,datatype等
@property(nonatomic, strong) DAHeatMapConfiguration                         *config;

//热图权限，开启热图功能后才可以使用
@property(nonatomic, strong, readonly,nullable) DAHeatMapPrivilege          *privilege;

//代理对象，可以拦截热图流程
@property(nonatomic, weak, nullable) id<DAHeatMapDelegate>                  delegate;

//当前热图功能是否已经启用, isRunning在token有效后才为YES
@property(nonatomic, assign, readonly) BOOL                                 isRunning;

// 单例模式，被tracker对象持有
+ (instancetype)sharedInstance;

// 开启热图模式，开启后会自动获取用户权限和token，可以在delegate里监听
- (void)run;

// 手动触发更新热图, 自动遍历当前页面的view并请求新的热图数据
- (void)update;

// 手动更新指定的views，而非自动遍历全部views
- (void)updateModels:(NSArray<DAHeatMapModel*>*)models;

// 停止热图模式，释放资源
- (void)stopRunning;

@end

NS_ASSUME_NONNULL_END
