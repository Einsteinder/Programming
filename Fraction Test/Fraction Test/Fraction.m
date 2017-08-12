//
//  Fraction.m
//  Fraction Test
//
//  Created by 翁 旭扬 on 15/5/2.
//  Copyright (c) 2015年 翁 旭扬. All rights reserved.
//

#import "Fraction.h"

@implementation Fraction

@synthesize numerator,denominator;
/*{
     int denominator;
}*/
-(void)reduce
{
    int u=numerator;
    int v=denominator;
    int temp;
    while(v!=0)
    {
        temp=u%v;
        u=v;
        v=temp;
    }
}
/*
-(Fraction *) add:(Fraction *)f
{
    Fraction *result=[[Fraction alloc]init];
    result.numerator=numerator*f.denominator+denominator*f.numerator;
    result.denominator=denominator*f.denominator;
    
    [result reduce];
    return result;
    
}
-(Fraction *)subtract:(Fraction *)f
{
    Fraction *result=[[Fraction alloc]init];
    result.numerator=numerator*f.denominator-denominator*f.numerator;
    result.denominator=denominator*f.denominator;
    
    [result reduce];
    return result;
}
-(Fraction *)multiply:(Fraction *)f
{
    Fraction * result=[[Fraction alloc]init];
    result.numerator=numerator*f.numerator;
    result.denominator=denominator*f.denominator;
    
    [result reduce];
    return result;
    
}
-(Fraction *)divide:(Fraction *)f
{
    Fraction *result=[[Fraction alloc]init];
    result.numerator=numerator*f.denominator;
    result.denominator=denominator*f.numerator;
    
    [result reduce];
    return result;
}
 */
-(id) copyWithZone:(NSZone *)zone
{
    Fraction *newFract = [[Fraction allocWithZone:zone] init];
    
    [newFract setTo:numerator over:denominator];
    return newFract;
}
-(void)setTo:(int)n over:(int)d
{
    numerator=n;
    denominator=d;
    
}
-(instancetype) init
{
    return [self initWith:0 over:0];
}
-(Fraction*) initWith: (int) n over:(int) d;
{
    self = [super init];
    if (self) {
        [self setTo:n over:d];
    }
    return self;
}
-(void) print
{
    NSLog(@"%i/%i",numerator,denominator);
}
/*
-(void) setNumerator:(int)n
{
    numerator=n;
}
-(void) setDenominator:(int)d
{
    denominator=d;
}
-(int) numerator
{
    return numerator;
}
-(int) denominator
{
    return denominator;
}
 */
-(double)convertToNum
{
    if (denominator!=0) {
        return (double)numerator/denominator;
    } else {
        return NAN;
    }
}



@end

@implementation Fraction (MathOps)




-(Fraction *) add:(Fraction *)f
{
    Fraction *result=[[Fraction alloc]init];
    result.numerator = (numerator * f.denominator) + (denominator * f.numerator);
    result.denominator = (denominator * f.denominator);
    
    [result reduce];
    return result;
    
}

-(Fraction *)subtract:(Fraction *)f
{
    Fraction *result=[[Fraction alloc]init];
    result.numerator=numerator*f.denominator-denominator*f.numerator;
    result.denominator=denominator*f.denominator;
    
    [result reduce];
    return result;
}
-(Fraction *)multiply:(Fraction *)f
{
    Fraction * result=[[Fraction alloc]init];
    result.numerator=numerator*f.numerator;
    result.denominator=denominator*f.denominator;
    
    [result reduce];
    return result;
    
}
-(Fraction *)divide:(Fraction *)f
{
    Fraction *result=[[Fraction alloc]init];
    result.numerator=numerator*f.denominator;
    result.denominator=denominator*f.numerator;
    
    [result reduce];
    return result;
}



@end
