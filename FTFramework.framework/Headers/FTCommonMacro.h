//
//  CommonMacro.h
//  QCMVVM
//
//  Created by 史超 on 2018/11/15.
//  Copyright © 2018年 BYX. All rights reserved.
//

#ifndef CommonMacro_h
#define CommonMacro_h

#import <objc/runtime.h>

/*   Category   */
#import "UIView+FTView.h"
#import "NSString+FTString.h"
#import "UIFont+FTFont.h"
#import "UIImage+FTImage.h"
#import "NSObject+FTDevice.h"
#import "NSDate+FTDate.h"
#import "UIViewController+FTAlertView.h"
#import "UIColor+FTColor.h"
#import "UIButton+FTButton.h"
#import "UILabel+FTLabel.h"
#import "FTToast.h"

#define weak_Self __weak __typeof__(self) weakSelf = self;

//输出方法
#define LogFunc NSLog(@"%s", __func__);

//获取window
#define WINDOW ([UIApplication sharedApplication].delegate.window)

//宏定义屏幕宽度
#define SCREENWIDTH ((CGFloat)([UIScreen mainScreen].bounds.size.width))
//宏定义屏幕高度
#define SCREENHEIGHT ((CGFloat)([UIScreen mainScreen].bounds.size.height))

//====================================================
// 用途: 判断设备是否为iPhone
//====================================================
#define isiPhone ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)

//RBG
#define RGBA(r,g,b,a)               [UIColor colorWithRed:(float)r/255.0f green:(float)g/255.0f blue:(float)b/255.0f alpha:a]
//RBG
#define colorRGB(r,g,b,a)               [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
//随机颜色
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
//随机颜色
#define customRandomColor               [UIColor colorWithRed:(arc4random()%255)/255.0 green:(arc4random()%255)/255.0 blue:(arc4random()%255)/255.0 alpha:1]

//图片加载
#define imageWithName(name)             [UIImage imageNamed:name]
//字体设置
#define fontSize(font)                  [UIFont systemFontOfSize:font]


//16进制色值转化为RGB返回UIColor类型对象
#define COLOR_WITH_HEX(hexValue)         [UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16)) / 255.0 green:((float)((hexValue & 0xFF00) >> 8)) / 255.0 blue:((float)(hexValue & 0xFF)) / 255.0 alpha:1.0f]

//加载storyboard控制器
#define StoryBoardVC(storyBoardName,IdentifierName)         [[UIStoryboard storyboardWithName:storyBoardName bundle:nil]instantiateViewControllerWithIdentifier:IdentifierName]

//机型
#define IS_IPHONE_4 (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double )480) < DBL_EPSILON )
#define IS_IPHONE_5 (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double )568) < DBL_EPSILON )
#define IS_IPHONE_6 (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double )667) < DBL_EPSILON )
#define IS_IPHONE_6_PLUS (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double )736) < DBL_EPSILON )

#define iPhone7PWidth 414
#define iPhone7PHeight 736

/** 设备判断(iPhoneX) */
#define kDeviceIsiPhoneX (SCREENWIDTH == 375 && SCREENHEIGHT == 812)

//判断iPHoneXr
#define iPhoneXR ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size) : NO)
//判断iPhoneXs
#define iPhoneXS ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)
//判断iPhoneXs Max
#define iPhoneXSMAX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size) : NO)

#define iPhoneX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)


/////////////iOS11+iPhoneX适配///////////////

//顶部状态条(电量条 高度)
#define StatusBarHeight (iPhoneX||iPhoneXR||iPhoneXS||iPhoneXSMAX ? 44.f : 20.f)
//导航栏
#define StatusBarAndNavBarHeight (iPhoneX||iPhoneXR||iPhoneXS||iPhoneXSMAX ? 88.f : 64.f)
// 顶部多余高度
#define TopMargin (iPhoneX||iPhoneXR||iPhoneXS||iPhoneXSMAX ? (24.f) : 0.f)
// 减去底部的虚拟home位置
#define BottomMargin (iPhoneX||iPhoneXR||iPhoneXS||iPhoneXSMAX ? (34.f) : 0.f)
//底部tab高度
#define TabBarHeight (iPhoneX||iPhoneXR||iPhoneXS||iPhoneXSMAX ? (49.f+34.f) : 49.f)// tab高度


#define TableIOS11(table)\
if (@available(iOS 11.0, *)) {\
table.estimatedRowHeight = 0;\
table.estimatedSectionHeaderHeight = 0;\
table.estimatedSectionFooterHeight = 0;\
table.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;\
}

/****************************类型判断相关****************************/

#define StringCheck(value)      ([value isKindOfClass:[NSString class]] ? value : \
[value isKindOfClass:[NSNumber class]] ? [(NSNumber *)value stringValue] : @"")

#define NumberCheck(value)      ([value isKindOfClass:[NSNumber class]] ? value : @0)

#define StringNumCheck(value)      ([value isKindOfClass:[NSString class]] ? value : \
[value isKindOfClass:[NSNumber class]] ? [(NSNumber *)value stringValue] : @"0")


#define ArrayCheck(value)       ([value isKindOfClass:[NSArray class]] ? value : @[])

#define DictionaryCheck(value)  ([value isKindOfClass:[NSDictionary class]] ? value : @{})


#define HUDStatusTip                          @"正在努力加载..."
#define HUDErrorTip                           @"请求失败，请重新尝试"
#define NetworkErrorMessage                   @"请求失败，请重新尝试"

#ifdef DEBUG
#define NSLog(format, ...)  do {                                                                            \
printf("<%s : %d> %s\n",                                           \
[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String],  \
__LINE__, [[NSString stringWithUTF8String:__FUNCTION__] UTF8String]);                                                        \
(NSLog)((format), ##__VA_ARGS__);                                           \
printf("---------- ---------- ----------\n");                      \
} while (0)
#else
#define NSLog(...) {}
#endif

#endif /* CommonMacro_h */
