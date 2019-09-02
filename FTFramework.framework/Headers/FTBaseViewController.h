//
//  FTBaseViewController.h
//  FTTemplate
//
//  Created by 史超 on 2018/11/20.
//  Copyright © 2018年 史超. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface FTBaseViewController : UIViewController

@property (nonatomic, strong) UIButton *leftBarItemBtn;

@property (nonatomic, strong) UIButton *rightBarItemBtn;

//隐藏返回按钮
- (void)hiddenBackButton;

//返回事件重写 用于监听返回事件
-(void)backButtonClick;

//添加右侧按钮
-(void)addRightItemWithTitle:(NSString *)title andImageName:(NSString *)imageName;

//点击右侧导航按钮
- (void)rightBarItemBtnClick;

@end
