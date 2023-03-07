//
//  GojekCV.h
//  KYCDemo
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
//#import "DetectionResult.h"
#import "HelperClasses.h"
NS_ASSUME_NONNULL_BEGIN


@interface GojekCVBridging : NSObject

- (UInt64)createInstance:(eCardType)cardtype :(int)normsize :(eRotation)rotation;
- (int)setFaceDetectionParam:(UInt64)instance :(int)minfacesize :(int)numthread;
- (int)run:(UInt64)instance imageData:(NSData *)imageData width:(int)width height:(int)height pixelFormat:(ePixelFormat)pixelFormat detectMultipleFaces:(bool)detectMultipleFaces result:(DetectionResult*)result doFaceDetection:(bool)doFaceDetection doImageAnalysis:(bool)doImageAnalysis;
- (int)SetROIPercentage:(UInt64)instance :(int)left top:(int)top right:(int)right bottom:(int)bottom width:(int)width height:(int)height;
- (int)destroyInstance:(UInt64)instance;

@end

NS_ASSUME_NONNULL_END

