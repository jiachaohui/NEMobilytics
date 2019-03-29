//
//  DATrackEvent.h
//  Mobilytics
//
//  Created by jiazhh on 2019/2/20.
//  Copyright © 2019 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 埋点事件信息，原本埋点通过DATracker的trackEvent方法来完成的，这样做可以满足大部分场景，但是针对埋点时机是有SDK来确定
 的场景，通过让ViewControler/UIControl提供/重载埋点信息更合适
 例如:
 app开发要修改“页面停留时长”的自动埋点信息，则只需要实现DAUIViewControllerAutoTrack协议，并在controler里实现
 - (DATrackEvent *)da_pageDurationEvent {
    return [DAAutoTrackEvent alloc] initWithEventId
 }
 */
@interface DATrackEvent : NSObject

@property(nonatomic, strong) NSString*      eventId;
@property(nonatomic, assign) int            costTime;
@property(nonatomic, strong) NSString*      category;
@property(nonatomic, strong) NSString*      label;
@property(nonatomic, strong) NSDictionary*  attributes;

- (instancetype)initWithEventId:(NSString *)eventId attributes:(NSDictionary *)attributes;

- (instancetype)initWithEventId:(NSString *)eventId
                       costTime:(int)costTime
                       category:(NSString*)category
                          label:(NSString*)label
                     attributes:(NSDictionary *)attributes;

@end
