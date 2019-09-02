//
//  FTLocationManager.h
//  FTTemplate
//
//  Created by 史超 on 2018/11/22.
//  Copyright © 2018年 史超. All rights reserved.
//


//使用说明

/**
 1. 需要导入框架 CoreLocation.framework
 2. 需要在info.plist授权定位
// Privacy - Location Usage Description
// Privacy - Location When In Use Usage Description
// Privacy - Location Always Usage Description
 
 3. #import "FTLocationManager.h"
 4.
 [[FTLocationManager sharedManager] getLocation:^(NSString *lon, NSString *lat,NSString *address) {
 NSLog(@"%@",lat);
 }];
 */


#import <Foundation/Foundation.h>

typedef void(^LocationBlock)(NSString * lon, NSString * lat,NSString *formattedAddress);

@interface FTLocationManager : NSObject

@property (nonatomic, strong) NSString * lon;
@property (nonatomic, strong) NSString * lat;

+ (instancetype)sharedManager;
- (void)getLocation:(LocationBlock)block;


@end
