//
//  FTTextField.h
//  FTTemplate
//
//  Created by 史超 on 2019/2/13.
//  Copyright © 2019年 史超. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface FTTextField : UITextField<UITextFieldDelegate>

//最大输入长度
@property(assign,nonatomic) NSInteger maxLength;
//占位文字字体颜色
@property(strong,nonatomic) UIColor *placeholderTextColor;
//占位文字 字体大小
@property(strong,nonatomic) UIFont *placeholderTextFont;



@end
