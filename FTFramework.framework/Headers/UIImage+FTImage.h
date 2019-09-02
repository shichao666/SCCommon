//
//  UIImage+SCImage.h
//  QCMVVM
//
//  Created by 史超 on 2018/11/15.
//  Copyright © 2018年 BYX. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef void (^GIFimageBlock)(UIImage *GIFImage);

@interface UIImage (FTImage)

// 根据图片url获取图片尺寸
+(CGSize)getImageSizeWithURL:(id)imageURL;

/* !对图片进行压缩
 *
 * @param scale 图片的压缩倍数
 * @return 压缩后的图片
 */
- (UIImage *)scale:(float)scale;
- (UIImage *)imageAtRect:(CGRect)rect;
- (UIImage *)imageByScalingProportionallyToMinimumSize:(CGSize)targetSize;
- (UIImage *)imageByScalingProportionallyToSize:(CGSize)targetSize;
- (UIImage *)imageByScalingToSize:(CGSize)targetSize;

//- (UIImage *)imageRotatedByRadians:(CGFloat)radians;
//- (UIImage *)imageRotatedByDegrees:(CGFloat)degrees;

/**
 *  按照自定义尺寸大小，对图片进行尺寸缩放
 *
 *  @param size 自定义尺寸
 *
 *  @return 新图
 */
- (UIImage*)reSizeImage:(CGSize)size;


/**
 *  按照自定义比例大小，对图片进行等比缩放
 *
 *  @param scale 缩放比例
 *
 *  @return 新图
 */
- (UIImage*)reScaleImage:(CGFloat)scale;


/**
 *  将图片大小压缩到指定KB
 *
 *  @param kb   指定KB
 *
 *  @return 新图
 */
- (NSData *)scaleImage:(UIImage *)origImage toKB:(NSInteger)kb;

//裁剪图片
- (UIImage *)cropImg:(UIImage *)originImage andSize:(CGSize)cropSize;

/**
 *  将图片裁剪成圆
 *
 *  @param cropSize 需要裁剪成的尺寸  设置CGSizeZero则取图片本身的size
 *
 *  @return 重新绘制的新图片
 */
- (UIImage *)cropCircleImageWithCropSize:(CGSize)cropSize;


/**
 *  CoreImage图片高斯模糊
 *
 *  @param image 图片
 *  @param blur 指定模糊值  默认为10, 范围为0-100
 *
 *  @return 重新绘制的新图片
 */
+ (UIImage *)coreBlurImage:(UIImage *)image withBlurNumber:(CGFloat)blur;


/**
 *  vImage模糊图片
 *
 *  @param image 原始图片
 *  @param blur  模糊数值(0-1)
 *
 *  @return 重新绘制的新图片
 */
+ (UIImage *)boxblurImage:(UIImage *)image withBlurNumber:(CGFloat)blur;


/**
 *  取消searchBar背景色
 *
 *  @param color 背景色
 *  @param size 尺寸
 *
 *  @return 重新绘制的新图片
 */
+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size;




#pragma -mark UIImage+Color
/** 根据颜色生成纯色图片 */
+ (UIImage *)imageWithColor:(UIColor *)color;

/** 取图片某一像素的颜色 */
- (UIColor *)colorAtPixel:(CGPoint)point;

/** 获得灰度图 */
- (UIImage *)convertToGrayImage;


#pragma -mark UIImage+Rotate
/** 纠正图片的方向 */
- (UIImage *)fixOrientation;

/** 按给定的方向旋转图片 */
- (UIImage*)rotate:(UIImageOrientation)orient;

/** 垂直翻转 */
- (UIImage *)flipVertical;

/** 水平翻转 */
- (UIImage *)flipHorizontal;

/** 将图片旋转degrees角度 */
- (UIImage *)imageRotatedByDegrees:(CGFloat)degrees;

/** 将图片旋转radians弧度 */
- (UIImage *)imageRotatedByRadians:(CGFloat)radians;


#pragma -mark UIImage+SubImage
/** 截取当前image对象rect区域内的图像 */
- (UIImage *)subImageWithRect:(CGRect)rect;

/** 压缩图片至指定尺寸 */
- (UIImage *)rescaleImageToSize:(CGSize)size;

/** 压缩图片至指定像素 */
- (UIImage *)rescaleImageToPX:(CGFloat )toPX;

/** 在指定的size里面生成一个平铺的图片 */
- (UIImage *)getTiledImageWithSize:(CGSize)size;

/** UIView转化为UIImage */
+ (UIImage *)imageFromView:(UIView *)view;

/** 将两个图片生成一张图片 */
+ (UIImage*)mergeImage:(UIImage*)firstImage withImage:(UIImage*)secondImage;


#pragma -mark UIImage+Gif
/** 用一个Gif生成UIImage，传入一个GIFData */
+ (UIImage *)animatedImageWithAnimatedGIFData:(NSData *)theData;

/** 用一个Gif生成UIImage，传入一个GIF路径 */
+ (UIImage *)animatedImageWithAnimatedGIFURL:(NSURL *)theURL;


/**生成一张带文字的纯色图片*/
+ (UIImage *)getImageWithText:(NSString *)name withSize:(CGSize)size withBackgroundColor:(UIColor *)backgroundColor;

/** 对View进行截图*/
+ (UIImage *)convertViewToImage:(UIView *)view;



/** 根据本地GIF图片名 获得GIF image对象 */

+ (UIImage *)imageWithGIFNamed:(NSString *)name;

/** 根据一个GIF图片的data数据 获得GIF image对象 */

+ (UIImage *)imageWithGIFData:(NSData *)data;

/** 根据一个GIF图片的URL 获得GIF image对象 */

+ (void)imageWithGIFUrl:(NSString *)url and:(GIFimageBlock)gifImageBlock;


@end
