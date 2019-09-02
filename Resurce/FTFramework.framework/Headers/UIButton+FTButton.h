//
//  UIButton+SCButton.h
//  FTTemplate
//
//  Created by 史超 on 2018/11/19.
//  Copyright © 2018年 史超. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^buttonClicked)(UIButton *btn);

@interface UIButton (FTButton)

//根据文字创建按钮  默认文字 字体颜色黑色
+ (UIButton *)buttonWithTitle:(NSString *)title andAction:(buttonClicked)action;

//根据文字创建按钮
+ (UIButton *)buttonWithTitle:(NSString *)title andTitleColor:(UIColor *)titleColor andAction:(buttonClicked)action;


//根据文字创建按钮  默认文字 字体颜色黑色
+ (UIButton *)buttonWithTitle:(NSString *)title andTarget:(id)target andAction:(SEL)action;

//根据文字创建按钮  默认文字 字体颜色黑色
+ (UIButton *)buttonWithTitle:(NSString *)title andTitleColor:(UIColor *)titleColor andTarget:(id)target andAction:(SEL)action;


//根据图片创建按钮
//+ (UIButton *)buttonWithImageName:(NSString *)imageName andBackgroundImageName:(NSString *)backImageName andAction:(buttonClicked)action;

//根据图片创建按钮
//+ (UIButton *)buttonWithImageName:(NSString *)imageName andBackgroundImageName:(NSString *)backImageName andTarget:(id)target andAction:(SEL)action;



#pragma mark - UIButton下image和title的各种位置的分类封装
typedef NS_ENUM(NSUInteger,HLButtonEdgeInsetsStyle) {
    
    HLButtonEdgeInsetsStyleTop,//image在上，label在下
    HLButtonEdgeInsetsStyleLeft,//image在左,label在右
    HLButtonEdgeInsetsStyleBottom,//image在下，label在上
    HLButtonEdgeInsetsStyleRight//image在右,label在左
};

/**
 *  设置button内部的image和title的布局样式
 *
 *  @param style 布局样式
 *  @param space 间距
 */
- (void)layoutButtonWithEdgeInsetsStyle:(HLButtonEdgeInsetsStyle)style imageTitleSpace:(CGFloat)space;

@end
