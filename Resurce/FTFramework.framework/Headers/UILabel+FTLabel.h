//
//  UILabel+FTLabel.h
//  FTTemplate
//
//  Created by 史超 on 2018/11/21.
//  Copyright © 2018年 史超. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UILabel (FTLabel)

/**
 设置文本,并指定行间距
 
 @param text 文本内容
 @param lineSpacing 行间距
 */
-(void)setText:(NSString*)text lineSpacing:(CGFloat)lineSpacing;

@end
