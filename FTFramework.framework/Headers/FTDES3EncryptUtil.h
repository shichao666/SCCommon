//
//  DES3EncryptUtil.h
//  FTTemplate
//
//  Created by sc on 2019/5/5.
//  Copyright © 2019年 史超. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FTCommonMacro.h"

NS_ASSUME_NONNULL_BEGIN

@interface FTDES3EncryptUtil : NSObject

// 加密方法
+ (NSString*)encrypt:(NSString*)plainText;

// 解密方法
+ (NSString*)decrypt:(NSString*)encryptText;


/**
    encryptOrDecrypt ：  kCCEncrypt加密 kCCDecrypt解密
    plainText ：原始字符串
    key    加密秘钥：AVQC7SDIUK312ZZEZ1HTQNJN
    giv    加密向量
 */
+ (NSString *)DESString:(CCOperation)encryptOrDecrypt plainText:(NSString *)plainText key:(NSString *)key giv:(NSString *)giv;

@end

NS_ASSUME_NONNULL_END
