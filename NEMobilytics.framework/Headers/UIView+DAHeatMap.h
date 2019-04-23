//
//  UIView+DAHeatMap.h
//  Mobilytics
//
//  Created by jiazhh on 2019/4/16.
//  Copyright © 2019 Netease. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (DAHeatMap)

// 是否开启热图属性，关闭之后,该对象不再参与热图采集
@property(nonatomic, assign) BOOL                   da_heatMapEnabled;

// 对象属性，热图系统使用，这些参数会在附加在热图API请求中，但是是否处理由服务端决定。
@property(nonatomic, strong, nullable) NSDictionary *da_heatMapAttributes;

// 由SDK自动生成的全局唯一ID
@property(nonatomic, strong) NSString *da_heatMapId;

// 类方法，返回NO时，该类的所有对象不参与热图
+ (BOOL)da_heatMapEnabled;

@end

NS_ASSUME_NONNULL_END
