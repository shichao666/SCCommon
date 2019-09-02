//
//  MainTabBarController.h
//  FTTemplate
//
//  Created by 史超 on 2018/11/21.
//  Copyright © 2018年 史超. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CYLTabBarController.h>

@interface MainTabBarController : NSObject

/**
 指定子控制器类名 示例：@[@"vc1",@"vc2"];
 */
@property(strong,nonatomic) NSArray *arrayViewControllerItemsName;

/**
 指定每个tabbaritem的资源图片 素材  名称
 @{CYLTabBarItemTitle : @"nav4", //标题
 CYLTabBarItemImage : @"tabbar_4_normal",//未选择状态下图片
 CYLTabBarItemSelectedImage : @"tabbar_4_select" //选择中状态下图片}
 */
@property(strong,nonatomic) NSArray<NSDictionary *> *arrayAttributesItems;


//设置图片的边距
@property(nonatomic) UIEdgeInsets imageInsets;

//设置title的位置
@property(nonatomic) UIOffset titlePositionAdjustment;


//需要在指定跟视图前  初始化以上属性 才有效果
@property(strong,nonatomic) CYLTabBarController *mainTabBarController;


@end



/**  使用示例
 MainTabBarController *tabbar = [[MainTabBarController alloc] init];
 tabbar.arrayViewControllerItemsName = @[@"TestVC1",@"TestVC2",@"TestVC3",@"TestVC4"];
 tabbar.arrayAttributesItems = [self arrayAttributesItem];
 self.window.rootViewController = tabbar.mainTabBarController;
 
 - (NSArray *)arrayAttributesItem{
 
 //        设置标题  tabbar普通状态下的图片  选中状态下的图片
 NSDictionary *bookcaseItemsAttributes =@{CYLTabBarItemTitle : @"tab1",
 CYLTabBarItemImage : @"tabbar_1_normal",
 CYLTabBarItemSelectedImage : @"tabbar_1_select",};
 
 NSDictionary *discoverItemsAttributes = @{CYLTabBarItemTitle : @"nav2",
 CYLTabBarItemImage : @"tabbar_2_normal",
 CYLTabBarItemSelectedImage : @"tabbar_2_select",};
 
 NSDictionary *askklItemsAttributes = @{CYLTabBarItemTitle : @"nav3",
 CYLTabBarItemImage : @"tabbar_3_normal",
 CYLTabBarItemSelectedImage : @"tabbar_3_select",};
 
 NSDictionary *userItemsAttributes = @{CYLTabBarItemTitle : @"nav4",
 CYLTabBarItemImage : @"tabbar_4_normal",
 CYLTabBarItemSelectedImage : @"tabbar_4_select"};
 
 NSArray *tabBarItemsAttributes = @[bookcaseItemsAttributes,
 discoverItemsAttributes,
 askklItemsAttributes,
 userItemsAttributes];
 return tabBarItemsAttributes;
 }
 
 */

