//
//  Complex.m
//  Exercise
//
//  Created by 翁 旭扬 on 15/5/4.
//  Copyright (c) 2015年 翁 旭扬. All rights reserved.
//

#import "Complex.h"

@implementation Complex

@synthesize real,imaginary;

-(void) print
{
    NSLog(@"%g + %gi",real,imaginary);
}
-(void) setReal:(double) a andImaginary: (double) b;
{
    real=a;
    imaginary=b;
}
-(Complex*) add:(Complex *)f
{
    Complex *result=[[Complex alloc]init];
    
    result.real=real+f.real;
    result.imaginary=imaginary+f.imaginary;
    
    return result;
}

@end
