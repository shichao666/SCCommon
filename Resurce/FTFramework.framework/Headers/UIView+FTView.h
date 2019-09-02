//
//  UIView+CustomView.h
//  QCMVVM
//
//  Created by 史超 on 2018/11/15.
//  Copyright © 2018年 BYX. All rights reserved.
//

#import <UIKit/UIKit.h>


//typedef void(^requestFailedButtonClick)(UIView *requestFailedView);

@interface UIView (FTView)

@property (nonatomic, assign) CGFloat x;
@property (nonatomic, assign) CGFloat y;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, assign) CGSize  size;
@property (nonatomic, assign) CGPoint origin;
@property (nonatomic, assign) CGFloat bottom;
@property (nonatomic, assign) CGFloat right;
@property (nonatomic, assign) CGFloat centerX;
@property (nonatomic, assign) CGFloat centerY;

@property (nonatomic, assign) CGFloat borderWidth;
@property (nonatomic, strong) UIColor *borderColor;
@property (nonatomic, assign) CGFloat cornerRadius;


@property(strong,nonatomic) UIView *requestFailedView;

//- (UIView *(^)(CGRect frame))sc_frame;
//
//- (UIView *(^)(UIColor *color))sc_color;
//
//- (UIView *(^)(CGFloat value))sc_cornerRadius;
//
//
//- (UIView *)settingView:(void(^)(UIView *scView))make;

//添加 随机颜色的边框  方便测试
- (void)addRandomColorBorder;

// 控件添加单击手势
- (void) addClickEvent:(id)target action:(SEL)action;

// 从 XIB 中加载视图
+ (instancetype)sc_loadViewFromXib;

// 判断是否显示在主窗口上面
- (BOOL)isShowOnWindow;

//父控制器
- (UIViewController *)parentController;

//移除子视图
- (void)removeAllSubviews;

- (void)moveBy:(CGPoint)point;


//添加网络请求失败界面 按钮回调   注意避免循环引用的问题
- (void)showNetworkRequestFailedView:(void(^)(void))action;

//移除网络请求失败显示界面 按钮回调
- (void)removeNetworkRequestFailedView;

@end
