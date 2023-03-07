//
//  HelperClasses.h
//  KYCDemo
//
//  Created by Akarapu Bharadwaj on 11/3/20.
//  Copyright © 2020 go-jek. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

@class GojekCV;

typedef NS_ENUM(NSUInteger, eCardType) {
    KTP = 0,
    SIM = 1,
    SELFIE = 2,
    SELFIE_WITH_ID = 3,
};

typedef NS_ENUM(NSUInteger, eRotation) {
    ROTATION_0 = 0,
    ROTATION_270 = 3,
    ROTATION_MIRRORED_90 = 5,
    ROTATION_MIRRORED_270 = 7
};

typedef NS_ENUM(NSUInteger, eErrorCode) {
    OK = 0x000,
    NULLPTRERR = 0x001,
    VALUEERR = 0x002,
    FD_ERR = 0x101,
    FD_ALLOCERR = 0x102,
    FD_MEMERR = 0x103,
    FD_MODELERR = 0x104,
    FD_MODELPATHERR = 0x105,
    FD_NULLPTRERR = 0x106,
    IQ_ERR = 0x201,
    IQ_ALLOCERR = 0x202,
    IQ_MEMERR = 0x203,
    IQ_NULLPTRERR = 0x204
};

typedef NS_ENUM(NSUInteger, ePixelFormat) {
    YUV = 0,
    RGBA8888 = 1,
    BGRA32 = 2
};

@interface Landmarks : NSObject

    @property CGPoint LEFT_EYE;
    @property CGPoint RIGHT_EYE;
    @property CGPoint NOSE;
    @property CGPoint MOUTH_LEFT;
    @property CGPoint MOUTH_RIGHT;
    
- (instancetype) init:(CGPoint)LEFT_EYE
                     :(CGPoint)RIGHT_EYE
                     :(CGPoint)NOSE
                     :(CGPoint)MOUTH_LEFT
                     :(CGPoint)MOUTH_RIGHT;

@end

@interface Face : NSObject

    @property CGRect boundingBox;
    @property Landmarks *landmarks;
    @property int confidenceScore;

- (instancetype) init:(CGRect)boundingBox :(Landmarks*)landmarks :(int)confidenceScore;
@end

@interface DetectionResult : NSObject

    @property int blurValue;
    @property int highlightValue;
    @property int lowlightValue;
    @property int facezoomValue;
    @property int meta_blurValue;
    @property int meta_highlightValue;
    @property int meta_lowlightValue;
    @property NSMutableArray<Face*>* faces;

- (instancetype) init;

- (void) setFaces:(int *) data :(int)numFaces;

@end

NS_ASSUME_NONNULL_END
