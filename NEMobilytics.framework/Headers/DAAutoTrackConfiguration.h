//
//  DAAutoTrackConfiguration.h
//  Mobilytics
//
//  Created by jiazhh on 2019/2/20.
//  Copyright © 2019 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DAAutoTrackConfiguration : NSObject<NSCopying>

@property(nonatomic, assign) BOOL autoTrackScreenEvent;         //Default: YES
@property(nonatomic, assign) BOOL autoTrackControlEvent;        //Default: YES
@property(nonatomic, assign) BOOL autoTrackGestureEvent;        //Default: YES
@property(nonatomic, assign) BOOL autoTrackTableViewEvent;      //Default: YES
@property(nonatomic, assign) BOOL autoTrackCollectionViewEvent; //Default: YES
@property(nonatomic, assign) BOOL autoTrackTabbarEvent;         //Default: YES

+ (instancetype)defautConfiguration;

@end
