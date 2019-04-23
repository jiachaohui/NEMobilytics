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

/*
 * 拦截热图数据，自己进行处理；
 * 返回值为YES，则中断默认绘制流程，由app处理数据显示；返回NO，则继续默认绘制流程
 */
- (BOOL)heatMap:(DAHeatMap *)heatmap didReceiveResponse:(NSArray *)response forModel:(NSArray *)heatmapModels;

/*
 * 热图数据请求失败，请检查Error进行错误处理
 */
- (void)heatMap:(DAHeatMap *)heatmap FailedReceiveResponse:(NSError *)error forModel:(NSArray *)heatMapModels;

/*
 * 拦截热图绘制流程，可以自己决定绘制方式,views对象是有SDK生成的渲染结果view，snapshot是截屏的view对象
 */
- (BOOL)heatMap:(DAHeatMap *)heatmap willRenderViews:(NSArray *)views onSnapshot:(UIView *)snapshotView;

/*
 * 编辑服务端返回response数据，并继续绘制流程
 */
- (NSArray *)heatMap:(DAHeatMap *)heatmap filterResponse:(NSArray *)response forModel:(NSArray *)heatmapModels;

/*
 * 成功获取到用户token，再次之后热图才算真正开始运行(isRunning=YES)，后续想用token，可以从privilege里读取
 */
- (void)heatMap:(DAHeatMap *)heatmap DidReceiveToken:(NSString *)token;

/*
 * 成功获取到用户token，后续想用token，可以从privilege里读取
 */
- (void)heatMap:(DAHeatMap *)heatmap FailedReceiveToken:(NSError *)error;

/*
 * 热图功能已停止，资源已经释放，Error可为空
 */
- (void)heatMap:(DAHeatMap *)heatmap didStoppedWithError:(NSError *)error;

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

// 手动触发更新热图, 自动便利当前页面的view并请求新的热图数据
- (void)update;

// 手动更新模式下，更新指定的views，而非自动遍历全部views
- (void)updateModels:(NSArray<DAHeatMapModel*>*)models;

// 停止热图模式，释放资源
- (void)stopRunning;

@end

NS_ASSUME_NONNULL_END
