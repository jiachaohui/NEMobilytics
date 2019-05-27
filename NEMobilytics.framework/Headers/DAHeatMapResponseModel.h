//
//  DAHeatMapResponseModel.h
//  Mobilytics
//
//  Created by jiazhh on 2019/4/24.
//  Copyright © 2019 Netease. All rights reserved.
//

#import "DAHeatMapModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface DAHeatMapResponseModel : DAHeatMapModel

/*
 * 服务端根据model对象返回的json数据，data参考格式如下：
 * "uv": {
 *      "style": "single",
 *      "value": 68231
 *  },
 * "pv": {
 *      "style": "single",
 *      "value": 126763
 * },
 */
@property(nonatomic, strong, nullable) NSDictionary   *response;

- (instancetype)initWithHeatMapModel:(DAHeatMapModel*)model response:(NSDictionary*)response;

@end

NS_ASSUME_NONNULL_END
