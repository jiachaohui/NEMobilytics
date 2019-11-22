//
//  DAAccurateLocation.h
//  Mobilytics
//
//  Created by jiazhh on 2019/9/27.
//  Copyright © 2019 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@interface DAAccurateLocation : NSObject

+ (instancetype)shared;

- (void)enable;
- (void)disable;

@end
