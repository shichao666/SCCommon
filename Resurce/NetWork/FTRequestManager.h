//
//  FTRequestManager.h
//  QCMVVM
//
//  Created by 史超 on 2018/11/15.
//  Copyright © 2018年 BYX. All rights reserved.
//

/**
 1.基于AFNetworking 3.2.1
 2.监听网络状态 发起网络请求  封装回调数据  处理异常状态
 3.单例 所以不用担心循环引用的问题 可以在回调block里面使用self.
 
 使用示例:
 
    //开始监听网络
    [FTRequestManager startMoinorNetworking];
    //关闭网络监听
    [FTRequestManager stopMoinorNetworking];
 
    //设置加载展示图片  可以是gif不用加后缀
    [FTRequestManager share].loadImageName = @"loading";
    //设置超时时长 默认为30秒
    [FTRequestManager share].timeoutInterval = 30.f;

    //1.接口地址  2.是否展示hud默认为NO 可以使用另外一个api 3.接口需要的动态参数固定参数可以写在内部 4.成功回调 FTDataModel数据外层model结构 方便外面访问 5.失败回调 错误码和错误信息
    [FTRequestManager POST:scURLString showHUD:YES  parameters:@{}  success:^(FTDataModel *data) {
        NSLog(@"%@",data.data);
    } failure:^(NSString *message, ResponseCode code) {
        NSLog(@"%@",message);
    }];
 
 */

#import <Foundation/Foundation.h>

#import <AFNetworking/AFNetworking.h>
#import "FTAPI_URL.h"    //地址路径URL
#import "FTDataModel.h"  //数据外层model
#import "SVProgressHUD.h"
#import "MJExtension.h"

typedef NS_ENUM(NSUInteger, ResponseCode) {
//    Success         = 200, //请求成功
    Success         = 0, //请求成功

    //    ...
    
    Error404        = 404,//URL路径错误
    
    NetworkError    = 408, //网络错误 请求超时
   
    NetworkErrorCustom = 1,//自定义错误
    
};

//支付宝支付状态码
typedef NS_ENUM(NSUInteger, aliPay_resultStatus) {
    alipay_Success = 9000, //支付成功
    alipay_Dealing = 8000, //正在处理
    alipay_Failure = 4000, //订单支付失败
    alipay_Repeat  = 5000,//重复请求 订单已经支付过
    alipay_Cancel  = 6001,//用户中途取消
    alipay_Error   = 6002,//网络出错
    alipay_Unknown = 6004,//支付结果未知
};

@interface FTRequestManager : NSObject

+ (FTRequestManager *)share;

//loading显示的图片 图片名称
@property(copy,nonatomic) NSString *loadImageName;

//超时设置 不能低于10秒 默认30秒
@property(assign,nonatomic) CGFloat timeoutInterval;

//是否需要公共参数 默认需要 --- limit - param - jsonparam
//@property(assign,nonatomic) BOOL needPublicParam;
//是否需要加密
//@property(assign,nonatomic) BOOL needEncryption;



//开始监听网络
+ (void)startMoinorNetworking;
//停止监听网络
+ (void)stopMoinorNetworking;


/**
 网络请求 GET
 URLPrefix 地址
 parameters 参数
 success 请求成功完成回调（数据model）
 failure 请求失败回调（信息 状态码）
 */
+(void)GET:(NSString *)URLPrefix parameters:(NSDictionary *)parameters success:(void(^)(FTDataModel *data))success failure:(void(^)(NSString *message,ResponseCode code))failure;

/**
 网络请求 POST
 URLPrefix 地址
 parameters 参数
 success 请求成功完成回调（数据model）
 failure 请求失败回调（信息 状态码）
 */
+(void)POST:(NSString *)URLPrefix  parameters:(NSDictionary *)parameters success:(void(^)(FTDataModel *data))success failure:(void(^)(NSString *message,ResponseCode code))failure;


//HUD控制
+(void)GET:(NSString *)URLPrefix showHUD:(BOOL)HUD parameters:(NSDictionary *)parameters success:(void(^)(FTDataModel *data))success failure:(void(^)(NSString *message,ResponseCode code))failure;

+(void)POST:(NSString *)URLPrefix showHUD:(BOOL)HUD parameters:(NSDictionary *)parameters success:(void(^)(FTDataModel *data))success failure:(void(^)(NSString *message,ResponseCode code))failure;

//请求失败尝试次数  多次请求




@end
