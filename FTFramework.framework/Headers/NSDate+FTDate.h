//
//  NSData+SCData.h
//  QCMVVM
//
//  Created by 史超 on 2018/11/15.
//  Copyright © 2018年 BYX. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDate (FTDate)

//
- (NSUInteger)daysAgo;
- (NSUInteger)daysAgoAgainstMidnight;
- (NSString *)stringDaysAgo;
- (NSString *)stringDaysAgoAgainstMidnight:(BOOL)flag;

+ (NSUInteger)weekday;
+ (NSInteger)year;

// 格式互转
+ (NSDate *)dateFromString:(NSString *)string;
+ (NSDate *)dateFromString:(NSString *)string withFormat:(NSString *)format;
+ (NSString *)stringFromDate:(NSDate *)date withFormat:(NSString *)string;
+ (NSString *)stringFromDate:(NSDate *)date;
+ (NSString *)stringForDisplayFromDate:(NSDate *)date;
+ (NSString *)stringForDisplayFromDate:(NSDate *)date prefixed:(BOOL)prefixed;
+ (NSString *)stringForDisplayFromDate:(NSDate *)date prefixed:(BOOL)prefixed alwaysDisplayTime:(BOOL)displayTime;

- (NSString *)string;
- (NSString *)stringWithFormat:(NSString *)format;
- (NSString *)stringWithDateStyle:(NSDateFormatterStyle)dateStyle timeStyle:(NSDateFormatterStyle)timeStyle;

// 开始标志
- (NSDate *)beginningOfWeek;
- (NSDate *)beginningOfDay;
- (NSDate *)endOfWeek;

// 日期时间格式
+ (NSString *)dateFormatString;
+ (NSString *)timeFormatString;
+ (NSString *)timestampFormatString;
+ (NSString *)dbFormatString;

// 两个时间的秒数之差
+ (NSTimeInterval)timeIntervalWithDate:(NSString *)strDate sinceDate:(NSString *)strSinceDate;

// 通过时间戳获取具体时间
+ (NSString *)stringFromTimeInterval:(NSTimeInterval)interval withFormat:(NSString *)format;
+ (NSString *)stringFromTimeInterval:(NSTimeInterval)interval;

// 判断是否已过期
+ (BOOL)judgeIsOverTime:(NSString *)time withFormat:(NSString *)format;

// 计算多长时间之前
+ (NSString *)stringTimesAgo:(NSString *)time withFormat:(NSString *)format;
+ (NSString *)stringTimesAgo:(NSString *)time;

// 计算年龄
+ (NSInteger)ageFromDate:(NSDate *)date;
+ (NSInteger)ageFromString:(NSString *)string withFormat:(NSString *)format;
+ (NSInteger)ageFromString:(NSString *)string;
@end
