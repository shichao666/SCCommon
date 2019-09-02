//
//  UIFont+SCFont.h
//  QCMVVM
//
//  Created by 史超 on 2018/11/15.
//  Copyright © 2018年 BYX. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIFont (FTFont)

/**
 *  ps和pt转换
 */
+ (UIFont *)fontWithPixel:(CGFloat)pixel;

/**
 *  根据pixel获取相应的iOS加粗字体
 *
 *  @param pixel 像素
 *
 */
+ (UIFont *)boldFontWithPixel:(CGFloat)pixel;


/**
    默认字体
 */
+ (UIFont *)FTFont:(CGFloat)fontSize;

@end
