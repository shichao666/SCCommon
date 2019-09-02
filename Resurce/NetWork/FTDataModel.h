//
//  FTDataModel.h
//  QCMVVM
//
//  Created by 史超 on 2018/11/15.
//  Copyright © 2018年 BYX. All rights reserved.
//


//接口外层数据 用model形式回传  需要特殊处理的话 在这处理
#import <Foundation/Foundation.h>

@interface FTDataModel : NSObject

//状态码
@property(assign,nonatomic) NSInteger code;

//描述
@property(copy,nonatomic) NSString *msg;

//
@property(strong,nonatomic) id data;

@end
