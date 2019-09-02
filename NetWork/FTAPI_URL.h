//
//  FTAPI_URL.h
//  QCMVVM
//
//  Created by 史超 on 2018/11/15.
//  Copyright © 2018年 BYX. All rights reserved.
//

#ifndef FTAPI_URL_h
#define FTAPI_URL_h


//#define DEBUG 1  // 1为测试环境, 0为生产环境


//项目key添加
/******************************************************************/
static  NSString * app_key = @"afafda7193c3787f899217b5b09d4a9e";

//域名配置
/******************************************************************/
static const NSString * URL_Prefix = @"http://etest.foton.com.cn/"; //测试环境
//static const NSString * URL_Prefix = @"https://czyl.foton.com.cn/"; //生产环境


//接口名
/******************************************************************/
//登录
#define ft_login                        @"getLogin.action"

//维修申请详情
#define sc_approveRepairDetail          @"approve/repairDetail.action"

//删除扫描数据接口
#define sc_delPartInfo                  @"rts/pubServiceScanner/delPartInfo"

//获取未完成单子数量
#define sc_getIncompleteOrderCount      @"rts/pubServiceScanner/getIncompleteOrderCount"

#endif /* FTAPI_URL_h */
