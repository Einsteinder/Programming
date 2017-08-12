//
//  Fraction.h
//  Fraction Test
//
//  Created by 翁 旭扬 on 15/5/2.
//  Copyright (c) 2015年 翁 旭扬. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Fraction : NSObject

@property int numerator,denominator;
-(void) print;
-(Fraction*) add:(Fraction *) f;
-(Fraction*) subtract:(Fraction *) f;
-(Fraction*) multiply:(Fraction *) f;
-(Fraction*) divide:(Fraction *) f;
-(void) setTo:(int) n over:(int)d;
-(void) reduce;


/*
-(void) setNumerator:(int) n;
-(void) setDenominator:(int)d;
-(int) numerator;
-(int) denominator;
 */
-(double) convertToNum;

@end
