//
//  DAHeatMapPrivilege.h
//  Mobilytics
//
//  Created by jiazhh on 2019/4/16.
//  Copyright © 2019 Netease. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DAHeatMapAccess : NSObject

@property(nonatomic, strong) NSString       *name;
@property(nonatomic, strong) NSString       *type;

- (instancetype)initWithName:(NSString*)name type:(NSString*)type;

@end


@interface DAHeatMapPrivilege : NSObject

// 用户权限表，key为缩写，value为中文描述，如：用户量
@property(nonatomic, strong, nullable) NSArray<DAHeatMapAccess *>           *accesses;
// 绘制方式
@property(nonatomic, strong, nullable) NSArray<DAHeatMapAccess *>           *drawTypes;
// 请求热图数据必填token
@property(nonatomic, strong) NSString                                           *token;
// 有效期，如：7200
@property(nonatomic, assign) NSInteger                                          expireTime;

- (instancetype)initWithToken:(NSString*)token
                     accesses:(NSArray<DAHeatMapAccess *> *)accesses
                     drawTypes:(NSArray<DAHeatMapAccess *> *)drawTypes
                   expireTime:(NSInteger)expireTime;

@end

NS_ASSUME_NONNULL_END
