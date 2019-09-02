//
//  FTToast.h
//  FTTemplate
//
//  Created by 史超 on 2018/11/28.
//  Copyright © 2018年 史超. All rights reserved.
//

//

#import <UIKit/UIKit.h>

@interface FTToast : UIView

//显示时长 默认1.5秒
@property(assign,nonatomic) NSInteger showTime;

//字体大小 默认16
@property(strong,nonatomic) UIFont *font;

@property(strong,nonatomic) UILabel *laebl;

+ (FTToast *)share;

//轻提示
+ (void)showToastWithString:(NSString *)string;

@end
