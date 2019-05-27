//
//  DAHeatMapBubbleView.h
//  Mobilytics
//
//  Created by jiazhh on 2019/5/15.
//  Copyright © 2019 Netease. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class DAHeatMapBubbleView;

@protocol DAHeatMapBubbleViewDelegate <NSObject>

// 点击气泡
- (void)heatMapBubbleDidTapped:(DAHeatMapBubbleView*)bubble;

// 长按气泡
- (void)heatMapBubbleDidLongPressed:(DAHeatMapBubbleView*)bubble;

@end

@interface DAHeatMapBubbleView : UIControl

- (instancetype)initWithDelegate:(id<DAHeatMapBubbleViewDelegate>)delegate;


- (void)setTitle:(NSString*)title;

@end

NS_ASSUME_NONNULL_END
