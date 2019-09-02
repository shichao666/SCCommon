//
//  MainTabBarController.m
//  FTTemplate
//
//  Created by 史超 on 2018/11/21.
//  Copyright © 2018年 史超. All rights reserved.
//

#import "MainTabBarController.h"

//#import "TFBaseNavigationController.h"
#import <FTFramework/FTFramework.h>

@implementation MainTabBarController

- (CYLTabBarController *)mainTabBarController{
    if (!_mainTabBarController) {
        if (!self.arrayAttributesItems || !self.arrayViewControllerItemsName) {
            [NSException raise:NSStringFromClass([self class]) format:@"arrayAttributesItems或者arrayViewControllerItemsName 不能为空且元素个数需要一致"];
        }
        UIEdgeInsets imageInsets = UIEdgeInsetsZero;
        UIOffset titlePositionAdjustment = UIOffsetZero;
        if (self.imageInsets.left||self.imageInsets.right||self.imageInsets.top||self.imageInsets.bottom) {//如果有值
            imageInsets = self.imageInsets;
        }
        
        if (titlePositionAdjustment.horizontal || titlePositionAdjustment.vertical) {
            titlePositionAdjustment = self.titlePositionAdjustment;
        }
        _mainTabBarController = [CYLTabBarController tabBarControllerWithViewControllers:self.arrayViewControllerItemsName tabBarItemsAttributes:self.arrayAttributesItems imageInsets:imageInsets titlePositionAdjustment:titlePositionAdjustment];
        [self customizeTabBarAppearance:_mainTabBarController];
    }
    return _mainTabBarController;
}

//设置子控制器
- (void)setArrayViewControllerItemsName:(NSArray *)arrayViewControllerItemsName {
    //    _arrayViewControllerItemsName = arrayViewControllerItemsName;
    NSMutableArray *vcArray = [NSMutableArray array];
    for (NSString *vcName in arrayViewControllerItemsName) {
        UIViewController *vc = [(UIViewController *)[NSClassFromString(vcName) alloc] init];
        TFBaseNavigationController *nav = [[TFBaseNavigationController alloc] initWithRootViewController:vc];
        [vcArray addObject:nav];
    }
    _arrayViewControllerItemsName = vcArray;
}

//设置样式
- (void)setArrayAttributesItems:(NSArray<NSDictionary *> *)arrayAttributesItems {
    _arrayAttributesItems = arrayAttributesItems;
    _mainTabBarController.tabBarItemsAttributes = arrayAttributesItems;
}



- (NSArray *)arrayViewControllerItem{
    //    //项目中要替换类名
    //    NSArray *vcNameArray = @[@"TestVC1",@"TestVC2",@"TestVC3",@"TestVC4"];
    //    NSMutableArray *vcArray = [NSMutableArray array];
    //    for (NSString *vcName in vcNameArray) {
    //        UIViewController *vc = [(UIViewController *)[NSClassFromString(vcName) alloc] init];
    //        TFBaseNavigationController *nav = [[TFBaseNavigationController alloc] initWithRootViewController:vc];
    //        [vcArray addObject:nav];
    //    }
    //    return vcArray;
    return @[];
}


- (NSArray *)arrayAttributesItem{
    
    return @[];
    
    //    设置标题  tabbar普通状态下的图片  选中状态下的图片
    //    NSDictionary *bookcaseItemsAttributes =@{CYLTabBarItemTitle : @"tab1",
    //                                             CYLTabBarItemImage : @"tabbar_1_normal",
    //                                             CYLTabBarItemSelectedImage : @"tabbar_1_select",};
    //
    //    NSDictionary *discoverItemsAttributes = @{CYLTabBarItemTitle : @"nav2",
    //                                              CYLTabBarItemImage : @"tabbar_2_normal",
    //                                              CYLTabBarItemSelectedImage : @"tabbar_2_select",};
    //
    //    NSDictionary *askklItemsAttributes = @{CYLTabBarItemTitle : @"nav3",
    //                                           CYLTabBarItemImage : @"tabbar_3_normal",
    //                                           CYLTabBarItemSelectedImage : @"tabbar_3_select",};
    //
    //    NSDictionary *userItemsAttributes = @{CYLTabBarItemTitle : @"nav4",
    //                                          CYLTabBarItemImage : @"tabbar_4_normal",
    //                                          CYLTabBarItemSelectedImage : @"tabbar_4_select"};
    //
    //    NSArray *tabBarItemsAttributes = @[bookcaseItemsAttributes,
    //                                        discoverItemsAttributes,
    //                                       askklItemsAttributes,
    //                                       userItemsAttributes];
    //    return tabBarItemsAttributes;
}


/**
 *  更多TabBar自定义设置：比如：tabBarItem 的选中和不选中文字和背景图片属性、tabbar 背景图片属性等等
 */
- (void)customizeTabBarAppearance:(CYLTabBarController *)tabBarController {
    // Customize UITabBar height
    // 自定义 TabBar 高度
    //     tabBarController.tabBarHeight = CYLTabBarControllerHeight;
    
    // set the text color for unselected state
    // 普通状态下的文字属性
    NSMutableDictionary *normalAttrs = [NSMutableDictionary dictionary];
    normalAttrs[NSForegroundColorAttributeName] = [UIColor grayColor];
    
    // set the text color for selected state
    // 选中状态下的文字属性
    NSMutableDictionary *selectedAttrs = [NSMutableDictionary dictionary];
    selectedAttrs[NSForegroundColorAttributeName] = [UIColor blueColor];
    
    // set the text Attributes
    // 设置文字属性
    UITabBarItem *tabBar = [UITabBarItem appearance];
    [tabBar setTitleTextAttributes:normalAttrs forState:UIControlStateNormal];
    [tabBar setTitleTextAttributes:selectedAttrs forState:UIControlStateSelected];
    
    // Set the dark color to selected tab (the dimmed background)
    // TabBarItem选中后的背景颜色
    // [self customizeTabBarSelectionIndicatorImage];
    
    // update TabBar when TabBarItem width did update
    // If your app need support UIDeviceOrientationLandscapeLeft or UIDeviceOrientationLandscapeRight，
    // remove the comment '//'
    // 如果你的App需要支持横竖屏，请使用该方法移除注释 '//'
    // [self updateTabBarCustomizationWhenTabBarItemWidthDidUpdate];
    
    // set the bar shadow image
    // This shadow image attribute is ignored if the tab bar does not also have a custom background image.So at least set somthing.
    [[UITabBar appearance] setBackgroundImage:[[UIImage alloc] init]];
    [[UITabBar appearance] setBackgroundColor:[UIColor whiteColor]];
    [[UITabBar appearance] setShadowImage:[UIImage imageNamed:@"tapbar_top_line"]];
    
    // set the bar background image
    // 设置背景图片
    //     UITabBar *tabBarAppearance = [UITabBar appearance];
    //     [tabBarAppearance setBackgroundImage:[UIImage imageNamed:@"tab_bar"]];
    
    // remove the bar system shadow image
    // 去除 TabBar 自带的顶部阴影
    // [[UITabBar appearance] setShadowImage:[[UIImage alloc] init]];
    
    
    //解决iOS12.1 正式版导致的TabBar 里面item错误偏移解决办法
    [[UITabBar appearance] setTranslucent:NO];
    
}

@end
