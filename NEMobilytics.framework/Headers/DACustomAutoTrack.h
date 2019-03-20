//
//  DACustomAutoTrack.h
//  Mobilytics
//
//  Created by jiazhh on 2019/2/28.
//  Copyright © 2019 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DATrackEvent.h"

/**
 * 页面自定义“无埋点”格式
 */
@protocol DAUIViewControllerAutoTrack <NSObject>

@optional
/**
 自定义页面停留时长，离开页面时触发
 可修改的属性包括：eventId、attributes。
 其中 atttributes中固有属性包括$title(页面标题)和$id（对象唯一标识符），请注意避开以免无意覆盖
 */
- (DATrackEvent *)da_pageDurationEvent;

/**
 页面事件，进入页面时触发
 可修改的属性只有attributes。
 其中 atttributes中固有属性包括$screenName(页面类名)和$screenTitle（页面标题）$url(链接URL），请注意避开以免无意覆盖
 */
- (DATrackEvent *)da_screenEvent;

@end

