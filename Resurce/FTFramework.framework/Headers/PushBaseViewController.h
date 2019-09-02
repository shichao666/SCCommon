//
//  PushBaseViewController
//  NavigationPresent
//
//  Created by degulade on 2017/1/8.
//  Copyright © 2017年 degulade. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PushBaseViewController : UIViewController


/**
 push样式的present，需要继承PushBaseViewController

 @param viewControllerToPresent present的vc
 @param animated 动画
 @param completion 事件
 @param isPushStyle push
 */
- (void)presentViewController:(UIViewController *)viewControllerToPresent
                     animated:(BOOL)animated
                   completion:(void (^)(void))completion
                    pushStyle:(BOOL)isPushStyle;

@end
