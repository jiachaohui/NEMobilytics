//
//  DAHeatMapScreenShotView.h
//  Mobilytics
//
//  Created by jiazhh on 2019/4/25.
//  Copyright © 2019 Netease. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


@interface DAHeatMapScreenShotView : UIImageView

+ (instancetype)screenshot;

// 设置指标
- (void)setTarget:(NSString*)target;

@end

NS_ASSUME_NONNULL_END
