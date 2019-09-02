//
//  UIColor+SCColor.h
//  QCMVVM
//
//  Created by 史超 on 2018/11/15.
//  Copyright © 2018年 BYX. All rights reserved.
//

#import <UIKit/UIKit.h>

#define    RAND_MAX    0x7fffffff


@interface UIColor (FTColor)
/**
 *  十六进制RGB颜色
 *
 *  @param hex 十六进制符号 eg.:0x0000ff
 *
 *  @return Color
 */
+ (UIColor *)colorWithRGBHex:(UInt32)hex;

/**
 *  十六进制RGB颜色
 *
 *  @param hex   十六进制符号 eg.:0x00ff00
 *  @param alpha 透明度
 *
 *  @return Color
 */
+ (UIColor *)colorWithRGBHex:(UInt32)hex alpha:(CGFloat)alpha;


//随机颜色
+ (UIColor *)colorWithRandomColor;

//项目中常用的边框颜色
+ (UIColor *)borderColor;

//项目中常用的分割线颜色
+ (UIColor *)lineColor;

@end
