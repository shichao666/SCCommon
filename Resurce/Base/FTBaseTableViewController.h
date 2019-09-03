//
//  FTBaseTableViewController.h
//  FTTemplate
//
//  Created by 史超 on 2018/11/20.
//  Copyright © 2018年 史超. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIScrollView+EmptyDataSet.h"
#import "ReactiveCocoa.h"
@interface FTBaseTableViewController : UITableViewController<DZNEmptyDataSetSource,DZNEmptyDataSetDelegate>

@property (nonatomic, strong) UIButton *leftBarItemBtn;

@property (nonatomic, strong) UIButton *rightBarItemBtn;

//是否显示空数据页面  默认为显示
@property(nonatomic,assign) BOOL isShowEmptyData;

//空数据页面的title -- 可不传，默认为：暂无任何数据
@property(nonatomic,strong) NSString *noDataTitle;

//空数据页面的图片 -- 可不传，默认图片为：NoData
@property(nonatomic,strong) NSString *noDataImgName;

//显示副标题的时候，需要赋值副标题，否则不显示
@property(nonatomic,strong) NSString *noDataDetailTitle;

//按钮标题、图片 --不常用
@property(nonatomic,strong) NSString *noDataBtnTitle;

@property(nonatomic,strong) NSString *noDataBtnImgName;

//RACSignal
@property(strong,nonatomic) RACSubject *noDataBtnActionSingal;




//隐藏返回按钮
- (void)hiddenBackButton;

//返回事件重写 用于监听返回事件
-(void)backButtonClick;

//添加右侧按钮
-(void)addRightItemWithTitle:(NSString *)title andImageName:(NSString *)imageName;

//点击右侧导航按钮
- (void)rightBarItemBtnClick;
@end
