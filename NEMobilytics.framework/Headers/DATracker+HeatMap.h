//
//  DATracker+HeatMap.h
//  Mobilytics
//
//  Created by jiazhh on 2019/4/23.
//  Copyright © 2019 Netease. All rights reserved.
//

#import "DATracker.h"
#import "DAHeatMap.h"

NS_ASSUME_NONNULL_BEGIN

@interface DATracker (HeatMap)

@property(nonatomic, strong, readonly) DAHeatMap *heatMap;

@end

NS_ASSUME_NONNULL_END
