//
//  NSString+SCString.h
//  QCMVVM
//
//  Created by 史超 on 2018/11/15.
//  Copyright © 2018年 BYX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCryptor.h>
#import <UIKit/UIKit.h>

@interface NSString (FTString)
/**
 *  对 url 字符串进行UTF8编码
 *
 *  @param string 需要编码的字符串
 *
 *  @return 编码后的字符串
 */
+ (NSString *)urlEncodingUTF8:(NSString *)string;

/**
 *  判断是否为空字符及空格
 *
 *  @param string 要判断的字符串
 *
 *  @return 包含空格 ? YES : NO
 */
+ (BOOL)isEmpty:(NSString *)string;

/**
 *  是否为有效的Email
 *
 *  @param checkString 检测字符串
 *
 *  @return 有效的Email ? YES : NO
 */
+ (BOOL) isValidEmail:(NSString *)checkString;

/**
 *  判断一个字符串是否包含另外一个字符串
 *
 *  @param motherString 母字符串
 *  @param sonString    子字符串
 *
 *  @return 包含 ? YES : NO
 */
+ (BOOL)stringContentString:(NSString *)motherString subString:(NSString *)sonString;

/**
 *  格式化日期字符串
 *
 *  @param stringDate   日期字符串，如：2013-01-31 14:08:34
 *  @param oldFormatter 旧日期格式，如果为@""或nil时，默认为 @"yyyy/MM/dd HH:mm:ss"
 *  @param newFormatter 新日期格式，如果为@""或nil时，默认为 @"yyyy-MM-dd HH:mm:ss"
 *
 *  @return 格式化以后的日期字符串
 */
+ (NSString *)dateFormatter:(NSString *)stringDate oldFormatter:(NSString *)oldFormatter newFormatter:(NSString *)newFormatter;

/**
 *  格式化时间字符
 *
 *  @param timeSeconds   为0时表示当前时间,可以传入你定义的时间戳
 *  @param timeFormatStr 为空返回当当时间戳,不为空返回你写的时间格式(yyyy-MM-dd HH:ii:ss)
 *  @param timeZoneStr   ([NSTimeZone systemTimeZone]获得当前时区字符串)
 *
 *  @return 格式化后的时间字符
 */
+(NSString *)setTimeInt:(NSTimeInterval)timeSeconds setTimeFormat:(NSString *)timeFormatStr setTimeZome:(NSString *)timeZoneStr;

/**
 *  MD5
 *
 *  @return MD5 String
 */
- (NSString *)MD5Digest;

/*!
 *  解析查询字符串
 *
 *  @param query 查询字符串
 *
 *  @return NSDictionary
 */
+ (NSDictionary *)parseQueryString:(NSString *)query;

/**
 *  竖排字符串
 *
 *  @param str 需要竖排的字符
 *
 *  @return 排完后的字符串
 */
+ (NSString *)verticalString:(NSString *)str;
/**
 *  计算文字尺寸
 *
 *  @param text    需要计算尺寸的文字
 *  @param font    文字的字体
 *  @param maxSize 文字的最大尺寸
 */
+ (CGSize)sizeWithText:(NSString *)text font:(UIFont *)font maxSize:(CGSize)maxSize;

//获取学生ID
+ (NSNumber *)getUserID;

+ (NSString *)getAccessToken;

//des加密解密
+(NSString *)TripleDES:(NSString *)plainText encryptOrDecrypt:(CCOperation)encryptOrDecrypt;

/**
 *  获取未来某个日期是星期几
 *  注意：featureDate 传递过来的格式 必须 和 formatter.dateFormat 一致，否则endDate可能为nil
 *
 */
-(NSString *)featureWeekdayWithDate:(NSString *)featureDate;

+ (NSString *)hexStringFromString:(NSString *)string;


/**
 *  从字符串中取出数字
 *
 *  @param str 字符串
 *
 *  @return 取出的数字
 */
+ (NSString *)getOnlyNum:(NSString *)str;



/**
 *  时间戳转时间
 *
 *  @param timsp 时间戳
 *
 *  @return 标准时间
 */
+ (NSString *)transToTime:(NSString *)timsp;

/**
 *  隐藏手机号中间4位
 *
 *  @param number 输入的手机号字符创
 *
 *  @return 隐藏中间4位后的手机号
 */
+(NSString *)handlePhoneNumber:(NSString *)number;

/*
 * 手机号是否输入正确
 */
+ (BOOL)phoneNumberIsTrue:(NSString*)phoneNmuber;

//判断字符串是否为空
- (BOOL)isEmpty;


@end
