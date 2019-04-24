//
//  DAHeatMapRenderView.h
//  Mobilytics
//
//  Created by jiazhh on 2019/4/24.
//  Copyright © 2019 Netease. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DAHeatMapResponseModel.h"

NS_ASSUME_NONNULL_BEGIN

/*
 * 根据数据渲染出来的结果view
 */
@interface DAHeatMapRenderView : UIControl

// 绑定的model对象
@property(nonatomic, strong) DAHeatMapResponseModel *responseModel;

@end

NS_ASSUME_NONNULL_END
