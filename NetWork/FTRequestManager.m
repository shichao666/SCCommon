//
//  FTRequestManager.m
//  QCMVVM
//
//  Created by 史超 on 2018/11/15.
//  Copyright © 2018年 BYX. All rights reserved.
//

#import "FTRequestManager.h"
//#import "FTDES3EncryptUtil.h"
//#import "FTCommonMacro.h"
#import <FTFramework/FTFramework.h>
@interface FTRequestManager()

@property(strong,nonatomic) AFHTTPSessionManager *manager;
//加载动画/图片
@property(strong,nonatomic) UIImage *loadingImage;

@end

@implementation FTRequestManager

- (AFHTTPSessionManager *)manager {
    if (!_manager) {
        _manager = [AFHTTPSessionManager manager];
        _manager.responseSerializer = [AFHTTPResponseSerializer serializer];//响应
        _manager.requestSerializer = [AFHTTPRequestSerializer serializer];// 请求
        _manager.responseSerializer.acceptableContentTypes = [NSSet setWithObjects:@"text/json",@"text/html",@"application/json",@"text/javascript", nil];
    }
    return _manager;
}

+ (id)allocWithZone:(struct _NSZone *)zone {
    static FTRequestManager *instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        //永远只会被执行一次
        instance = [super allocWithZone:zone];
    });
    return instance;
}

+ (FTRequestManager *)share {
    return [[FTRequestManager alloc] init];
}

//开始监听网络
+ (void)startMoinorNetworking {
    //    AFNetworkReachabilityStatusUnknown          = -1,
    //    AFNetworkReachabilityStatusNotReachable     = 0,
    //    AFNetworkReachabilityStatusReachableViaWWAN = 1,
    //    AFNetworkReachabilityStatusReachableViaWiFi = 2,
    [[AFNetworkReachabilityManager sharedManager] startMonitoring];
    [[AFNetworkReachabilityManager sharedManager] setReachabilityStatusChangeBlock:^(AFNetworkReachabilityStatus status) {
        switch (status) {
            case AFNetworkReachabilityStatusUnknown:
                //未知网络
                NSLog(@"AFNetworkReachabilityStatusUnknown");
                break;
            case AFNetworkReachabilityStatusNotReachable:
                //不可用
                NSLog(@"AFNetworkReachabilityStatusNotReachable");
                break;
            case AFNetworkReachabilityStatusReachableViaWWAN:
                //gprs蜂窝移动数据
                NSLog(@"AFNetworkReachabilityStatusReachableViaWWAN");
                break;
            case AFNetworkReachabilityStatusReachableViaWiFi:
                //wifi
                NSLog(@"AFNetworkReachabilityStatusReachableViaWiFi");
                break;
            default:
                break;
        }
    }];
}

//停止监听网络
+ (void)stopMoinorNetworking {
    [[AFNetworkReachabilityManager sharedManager] stopMonitoring];
}

- (void)setLoadImageName:(NSString *)loadImageName{
    _loadImageName = loadImageName;
    
    NSString * imagePath = [[NSBundle mainBundle] pathForResource:loadImageName ofType:@"gif"];
    if (imagePath) {//gif图片
        self.loadingImage = [UIImage imageWithGIFNamed:loadImageName];
    }else
        self.loadingImage = [UIImage imageNamed:loadImageName];
}

//设置超时时长  不能低于10秒
- (void)setTimeoutInterval:(CGFloat)timeoutInterval {
    _timeoutInterval = timeoutInterval;
    if (timeoutInterval) {
        self.manager.requestSerializer.timeoutInterval = timeoutInterval>=10?timeoutInterval:10;
    }
}

- (instancetype)init {
    if (self = [super init]) {
        // 设置超时时间  并初始化
        self.manager.requestSerializer.timeoutInterval = 30.f;
    }
    return self;
}


/**
 网络请求 GET
 URLPrefix 地址
 parameters 参数
 success 请求成功完成回调（数据model）
 failure 请求失败回调（信息 状态码）
 */
+(void)GET:(NSString *)URLPrefix parameters:(NSDictionary *)parameters success:(void(^)(FTDataModel *data))success failure:(void(^)(NSString *message,ResponseCode code))failure {
    [FTRequestManager GET:URLPrefix showHUD:NO parameters:parameters success:success failure:failure];
}

/**
 网络请求 POST
 URLPrefix 地址
 parameters 参数
 success 请求成功完成回调（数据model）
 failure 请求失败回调（信息 状态码）
 */
+(void)POST:(NSString *)URLPrefix  parameters:(NSDictionary *)parameters success:(void(^)(FTDataModel *data))success failure:(void(^)(NSString *message,ResponseCode code))failure {
    [FTRequestManager POST:URLPrefix showHUD:NO parameters:parameters success:success failure:failure];
}


//有参数 HUD控制
+(void)GET:(NSString *)URLPrefix showHUD:(BOOL)HUD parameters:(NSDictionary *)parameters success:(void(^)(FTDataModel *data))success failure:(void(^)(NSString *message,ResponseCode code))failure {
    FTRequestManager *rm =  [FTRequestManager share];
    [rm isShowHUD:HUD];
    //url拼接
    NSString *url = [FTRequestManager urlString:URLPrefix andGetParam:parameters andPostPara:nil];
    
    //参数处理 排序 加密或者添加公共参数等
    NSDictionary *submitParam = [FTRequestManager paramWithParam:parameters];
    
    NSLog(@"请求URL========%@ 参数=========%@",url,submitParam);
    
    [rm.manager GET:url parameters:submitParam progress:nil success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        //逻辑处理  异常处理 异常上报
        [rm requestWithResponseObject:responseObject success:success failure:failure];
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        failure(NetworkErrorMessage,NetworkError);
    }];
    
}

+(void)POST:(NSString *)URLPrefix showHUD:(BOOL)HUD parameters:(NSDictionary *)parameters success:(void(^)(FTDataModel *data))success failure:(void(^)(NSString *message,ResponseCode code))failure {
    FTRequestManager *rm =  [FTRequestManager share];
    [rm isShowHUD:HUD];
    //url拼接
    NSString *url = [FTRequestManager urlString:URLPrefix andGetParam:nil andPostPara:parameters];
    
    //参数处理 排序 加密或者添加公共参数等
    NSDictionary *submitParam = [FTRequestManager paramWithParam:parameters];
    
    NSLog(@"请求URL========%@ 参数=========%@",url,submitParam);
    
    [rm.manager POST:url parameters:submitParam progress:^(NSProgress * _Nonnull uploadProgress) {
        
    } success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        //逻辑处理  异常处理 异常上报
        [rm requestWithResponseObject:responseObject success:success failure:failure];
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        [SVProgressHUD showErrorWithStatus:error.localizedDescription];
        NSLog(@"%@",error.localizedDescription);
    }];
}

- (void)requestWithResponseObject:(id)responseObject success:(void(^)(FTDataModel *data))success failure:(void(^)(NSString *message,ResponseCode code))failure {
    
    if ([responseObject isKindOfClass:[NSData class]]) { //判断数据类型
        //转字符串  加密的话先解密
        //         NSString *utf8Str=[[NSString alloc]initWithData:responseObject encoding:NSUTF8StringEncoding];
        //        NSString *dataStr=[DES3Crypt decrypt:utf8Str];
        //        NSData *responseData=[dataStr dataUsingEncoding:NSUTF8StringEncoding];
        NSError *err;
        NSDictionary *dic = [NSJSONSerialization JSONObjectWithData:(NSData *)responseObject options:NSJSONReadingMutableContainers error:&err];
        if (err) {
            failure(@"json解析错误！！",NetworkErrorCustom);
        }else {
            //外层数据model
            FTDataModel *dataModel = [FTDataModel mj_objectWithKeyValues:dic];
            if (dataModel.code == Success) {//访问成功
                success(dataModel);
            }else {
                failure(dataModel.msg.length?dataModel.msg:HUDErrorTip,NetworkErrorCustom);
            }
        }
    }else if ([responseObject isKindOfClass:[NSDictionary class]]) { //字典
        FTDataModel *dataModel = [FTDataModel mj_objectWithKeyValues:responseObject];
        if (dataModel.code == Success) {//访问成功
            success(dataModel);
        }else {
            failure(dataModel.msg.length?dataModel.msg:HUDErrorTip,NetworkErrorCustom);
        }
    }else if ([responseObject isKindOfClass:[NSArray class]]) {//数组
        
    }else if ([responseObject isKindOfClass:[NSString class]]) {//字符串
        //转data
        NSData *responseData =[responseObject dataUsingEncoding:NSUTF8StringEncoding];
        [self requestWithResponseObject:responseData success:success failure:failure];
    }else {
        failure(@"数据格式错误！",NetworkErrorCustom);
    }
    
}

//是否展示hud
- (void)isShowHUD:(BOOL)HUD {
    if (HUD) {
        
        if (self.loadImageName && self.loadImageName.length) {
            [SVProgressHUD setDefaultStyle:SVProgressHUDStyleCustom];
            [SVProgressHUD setDefaultMaskType:SVProgressHUDMaskTypeCustom];
            [SVProgressHUD setBackgroundColor:[UIColor colorWithWhite:0 alpha:0]];
            [SVProgressHUD setBackgroundLayerColor:[UIColor colorWithWhite:0 alpha:0]];
            
            [SVProgressHUD setMaximumDismissTimeInterval:CGFLOAT_MAX];
            [SVProgressHUD setMinimumDismissTimeInterval:CGFLOAT_MAX];
            //            [SVProgressHUD setInfoImage:image];
            [SVProgressHUD setInfoImage:self.loadingImage];
            [SVProgressHUD showInfoWithStatus:@""];
            //                [SVProgressHUD setImageViewSize:CGSizeMake(200, 200)];
            [SVProgressHUD setImageViewSize:self.loadingImage.size];
        }else
            [SVProgressHUD showWithStatus:HUDStatusTip];
        //        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        //            [SVProgressHUD dismiss];
        //        });
    }
}

#pragma -mark 参数拼接处理 加密 添加公共参数
+ (NSDictionary *)paramWithParam:(NSDictionary *)param {
    
    NSMutableDictionary *limitDic = [NSMutableDictionary dictionary];
    NSMutableDictionary *mutableDic = [NSMutableDictionary dictionary];
#warning 需要具体参数
    //添加UID
    [limitDic setObject:@"751650" forKey:@"uid"];
    //添加token
    [limitDic setObject:@"C37718FA85F9FD707C00C45B75607D2E21CB90002419B5EFA28650BC7DBB620F67E1C57D" forKey:@"auth"];
    //添加用户类型
    [limitDic setObject:@"40" forKey:@"userType"];
    
    //添加时间戳
    NSString *timestamp = [NSString stringWithFormat:@"%.0f", [[NSDate dateWithTimeIntervalSinceNow:0] timeIntervalSince1970]];
    [limitDic setObject:timestamp forKey:@"timestamp"];
    
    //添加平台参数 方便问题处理 web=1，iOS=2，Android=3
    [limitDic setObject:@"iOS" forKey:@"from"];
    
    //添加版本号
    NSString *app_Version = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"];
    [limitDic setObject:app_Version forKey:@"version"];
    
    //添加limit
    [mutableDic setObject:limitDic forKey:@"limit"];
    //添加参数
    [mutableDic setObject:param forKey:@"param"];
    
    NSData *data=[NSJSONSerialization dataWithJSONObject:mutableDic options:  NSJSONWritingPrettyPrinted  error:nil];
    NSString *parString=[[NSString alloc]initWithData:data encoding:NSUTF8StringEncoding];
    
    //参数加密  可以添加配置 是否需要排序加密
    //       parString = [FTDES3EncryptUtil encrypt:parString];
    
    return @{@"jsonParame":parString};
}

#pragma -mark url处理 拼接
+ (NSString *)urlString:(NSString *)apiURL andGetParam:(NSDictionary *)getParam andPostPara:(NSDictionary *)postParam {
    // 其他操作  URL拼接
    
    if ([apiURL hasPrefix:@"http"]) {//外包拼接好的url不做拼接直接返回
        return apiURL;
    }
    
    if (getParam && getParam.allKeys.count) {//GET 参数拼接方式
        NSString *paramString = @"?";
        for (NSString *key in getParam.allKeys) {
            paramString = [paramString stringByAppendingString:[NSString stringWithFormat:@"%@=%@&",key,[getParam objectForKey:key]]];
        }
        paramString = [paramString substringToIndex:paramString.length-1];
        //对url编码 特殊字符或者中文处理
        return  [[NSString stringWithFormat:@"%@%@%@",URL_Prefix,apiURL,paramString] stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
    }
    //对url编码 特殊字符或者中文处理
    return [[NSString stringWithFormat:@"%@%@",URL_Prefix,apiURL] stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
}




@end
