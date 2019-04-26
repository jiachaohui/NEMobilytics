//
//  DAHeatMapModel.h
//  Mobilytics
//
//  Created by jiazhh on 2019/4/22.
//  Copyright © 2019 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface DAHeatMapModel : NSObject

// view对象，主要用来使用SDK生成的唯一ID： da_heatMapId
@property(nonatomic, strong, nullable) UIView *view;

// 如果没有view对象，可以考虑提供viewHeatMapId，但是要确保其不可重复性, view和viewHeatMapId不可同时为nil
@property(nonatomic, strong, nullable) NSString   *viewHeatmapId;

// 为view绑定的属性，在请求热图数据时会作为request的一部分
@property(nonatomic, strong, nullable) NSDictionary *properties;

- (instancetype)initWithView:(UIView*)view properties:(NSDictionary*)properties;
- (instancetype)initWithViewHeatmapId:(NSString*)viewHeatmapId properties:(NSDictionary*)properties;

- (NSDictionary*)toDictionary;

@end

NS_ASSUME_NONNULL_END
