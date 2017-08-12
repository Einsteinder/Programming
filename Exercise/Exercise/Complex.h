//
//  Complex.h
//  Exercise
//
//  Created by 翁 旭扬 on 15/5/4.
//  Copyright (c) 2015年 翁 旭扬. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Complex : NSObject

@property double real,imaginary;

-(void) print;
-(void) setReal:(double) a andImaginary:(double) b;
-(Complex *) add:(Complex *) f;

@end
