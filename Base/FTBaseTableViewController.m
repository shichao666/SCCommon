//
//  FTBaseTableViewController.m
//  FTTemplate
//
//  Created by 史超 on 2018/11/20.
//  Copyright © 2018年 史超. All rights reserved.
//

#import "FTBaseTableViewController.h"
//#import "FTCommonMacro.h"
#import <FTFramework/FTFramework.h>
@interface FTBaseTableViewController ()

@end

@implementation FTBaseTableViewController


#pragma -mark 懒加载
- (UIButton*)leftBarItemBtn {
    if (!_leftBarItemBtn) {
        _leftBarItemBtn = [UIButton buttonWithType:UIButtonTypeCustom];
        _leftBarItemBtn.frame = CGRectMake(0, 0, 30, 44);
        [_leftBarItemBtn addTarget:self action:@selector(backButtonClick) forControlEvents:UIControlEventTouchUpInside];
        [_leftBarItemBtn setImage:[UIImage imageNamed:@"nav_back_image"] forState:UIControlStateNormal];
    }
    return _leftBarItemBtn;
}

- (UIButton*)rightBarItemBtn {
    if (!_rightBarItemBtn) {
        _rightBarItemBtn = [UIButton buttonWithType:UIButtonTypeCustom];
        _rightBarItemBtn.frame = CGRectMake(0, 0, 60, 44);
        [_rightBarItemBtn addTarget:self action:@selector(rightBarItemBtnClick) forControlEvents:UIControlEventTouchUpInside];
        _rightBarItemBtn.titleLabel.font = [UIFont systemFontOfSize:14];
        [_rightBarItemBtn setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    }
    return _rightBarItemBtn;
}

- (RACSubject *)noDataBtnActionSingal {
    if (!_noDataBtnActionSingal) {
        _noDataBtnActionSingal = [RACSubject subject];
    }
    return _noDataBtnActionSingal;
}


//隐藏返回按钮
- (void)hiddenBackButton {
    self.leftBarItemBtn.hidden = YES;
    self.navigationItem.leftBarButtonItem = nil;
}

//返回事件重写 用于监听返回事件
-(void)backButtonClick {
    LogFunc
    [self.navigationController popViewControllerAnimated:YES];
}

- (void)setnoDataBtnTitle:(NSString *)noDataBtnTitle {
    _noDataBtnTitle = noDataBtnTitle;
     [self emptyDataSetShouldDisplay:self.tableView];
}

- (void)setIsShowEmptyData:(BOOL)isShowEmptyData {
    _isShowEmptyData = isShowEmptyData;
    [self emptyDataSetShouldDisplay:self.tableView];
    if (_isShowEmptyData) {
        self.tableView.emptyDataSetDelegate = self;
        self.tableView.emptyDataSetSource = self;
    }
}

//点击右侧按钮
- (void)rightBarItemBtnClick {
    LogFunc
}

//添加右侧功能按钮
- (void)addRightItemWithTitle:(NSString *)title andImageName:(NSString *)imageName {
    if (!title && !imageName) {
        return;
    }
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:self.rightBarItemBtn];
    if (title) {
        [self.rightBarItemBtn setTitle:title forState:UIControlStateNormal];
    }
    if (imageName) {
        [self.rightBarItemBtn setImage:imageWithName(imageName) forState:UIControlStateNormal];
    }
}


- (void)viewDidLoad {
    [super viewDidLoad];
    
    /*  tableview 通用设置*/
    self.tableView.tableFooterView = [UIView new];
    
    self.isShowEmptyData = YES;
    
    self.tableView.emptyDataSetSource = self;
    self.tableView.emptyDataSetDelegate = self;
    
    
    //禁止滑动返回
    //    self.navigationController.interactivePopGestureRecognizer.enabled = NO;
    
    //设置背景颜色
    self.view.backgroundColor = RGBA(246, 246, 246, 1);
    
//    self.automaticallyAdjustsScrollViewInsets = NO;
    
    //有上级界面添加返回按钮
    if ([self.navigationController.viewControllers indexOfObject:self] > 0) {
        self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:self.leftBarItemBtn];
    }

    
    self.navigationController.navigationBar.barTintColor = [UIColor whiteColor];
    
//    TableIOS11(self.tableView);
}


#pragma -mark DZNEmptyDataSetSource,DZNEmptyDataSetDelegate

- (UIImage *)imageForEmptyDataSet:(UIScrollView *)scrollView {
    if (self.noDataImgName) {
        return imageWithName(self.noDataImgName);
    }
    return imageWithName(@"noData_image");
}

- (NSAttributedString *)titleForEmptyDataSet:(UIScrollView *)scrollView {
    NSString *text = self.noDataTitle?self.noDataTitle:@"暂无任何数据";
    
    NSDictionary *attributes = @{NSFontAttributeName: [UIFont boldSystemFontOfSize:16.0f],
                                 NSForegroundColorAttributeName: [UIColor grayColor]};
    
    return [[NSAttributedString alloc] initWithString:text attributes:attributes];
}

- (NSAttributedString *)descriptionForEmptyDataSet:(UIScrollView *)scrollView {
    NSString *text = self.noDataDetailTitle;
    
    NSMutableParagraphStyle *paragraph = [NSMutableParagraphStyle new];
    paragraph.lineBreakMode = NSLineBreakByWordWrapping;
    paragraph.alignment = NSTextAlignmentCenter;
    
    NSDictionary *attributes = @{NSFontAttributeName: [UIFont systemFontOfSize:14.0f],
                                 NSForegroundColorAttributeName: [UIColor lightGrayColor],
                                 NSParagraphStyleAttributeName: paragraph};
    
    return self.noDataDetailTitle?[[NSAttributedString alloc] initWithString:text attributes:attributes]:nil;
}

- (BOOL)emptyDataSetShouldAllowTouch:(UIScrollView *)scrollView {
    return YES;
}

- (BOOL)emptyDataSetShouldDisplay:(UIScrollView *)scrollView {
    return self.isShowEmptyData;
}

- (CGFloat)verticalOffsetForEmptyDataSet:(UIScrollView *)scrollView {
    return -self.tableView.tableHeaderView.frame.size.height/2.0f;
}

- (NSAttributedString *)buttonTitleForEmptyDataSet:(UIScrollView *)scrollView forState:(UIControlState)state {
    NSDictionary *attributes = @{NSFontAttributeName: [UIFont boldSystemFontOfSize:16.0f]};
    
    return self.noDataBtnTitle?[[NSAttributedString alloc] initWithString:self.noDataBtnTitle attributes:attributes]:nil;
}

- (UIImage *)buttonImageForEmptyDataSet:(UIScrollView *)scrollView forState:(UIControlState)state {
    return self.noDataBtnImgName?[UIImage imageNamed:self.noDataBtnImgName]:nil;
}

- (void)emptyDataSet:(UIScrollView *)scrollView didTapButton:(UIButton *)button {
    if (self.noDataBtnActionSingal) {
        [self.noDataBtnActionSingal sendNext:@"点击加载按钮"];
    }else {
        NSLog(@"没有订阅事件");
    }
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [self.view endEditing:YES];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
