//
//  UIViewController+SCAlertView.h
//  QCMVVM
//
//  Created by 史超 on 2018/11/15.
//  Copyright © 2018年 BYX. All rights reserved.
//

#import <UIKit/UIKit.h>

#define cancelIndex    (-1)

typedef void(^AlertViewBlock)(NSInteger buttonTag);

@interface UIViewController (FTAlertView)
/**
 *  创建提示框
 *
 *  @param title        标题
 *  @param message      提示内容
 *  @param cancelTitle  取消按钮(无操作,为nil则只显示一个按钮)
 *  @param titleArray   标题字符串数组(为nil,默认为"确定")
 *  @param confirm      点击按钮的回调(取消按钮的Index是cancelIndex -1)
 */
- (void)showAlert:(NSString *)title
          message:(NSString *)message
      cancelTitle:(NSString *)cancelTitle
       titleArray:(NSArray *)titleArray
          confirm:(AlertViewBlock)confirm;

/**
 *  创建菜单(Sheet)
 *
 *  @param title        标题
 *  @param message      提示内容
 *  @param cancelTitle  取消按钮(无操作,为nil则只显示一个按钮)
 *  @param titleArray   标题字符串数组(为nil,默认为"确定")
 *  @param confirm      点击确认按钮的回调(取消按钮的Index是cancelIndex -1)
 */
- (void)showSheet:(NSString *)title
          message:(NSString *)message
      cancelTitle:(NSString *)cancelTitle
       titleArray:(NSArray *)titleArray
          confirm:(AlertViewBlock)confirm;

@end
