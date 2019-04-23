//
//  DAHeatMapConfiguration.h
//  Mobilytics
//
//  Created by jiazhh on 2019/4/16.
//  Copyright © 2019 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DAHeatMapConfiguration : NSObject

// 热图功能是否可用，sdk初始化的时候设置为NO，则热图功能将永久关闭，调用run方法只会返回error
@property(nonatomic, assign) BOOL                                   enabled;
// 自定更新页面热图资源，更新策略: 定时对比变更
@property(nonatomic, assign) BOOL                                   autoUpdate;
// 黑名单机制，加入黑名单的类（view或者controller）将不会使用热图功能
@property(nonatomic, strong) NSArray                                *filterClasses;

@property(nonatomic, strong) NSString                               *appkey;
// 用户ID，用于权限管理,是否需要password，本地权限校验如何完成？
@property(nonatomic, strong, nullable) NSString                     *userId;
// app额外信息，扩展给“定制热图方”使用
@property(nonatomic, strong) NSDictionary                           *extraAppInfos;

// 将appkey、userId、extraAppInfos等字段合并成平铺字典
- (NSDictionary*)toDictionary;
+ (instancetype)defaultConfiguration;

@end

NS_ASSUME_NONNULL_END
