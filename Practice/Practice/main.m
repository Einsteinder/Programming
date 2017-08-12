//
//  main.m
//  Practice
//
//  Created by 翁 旭扬 on 15/4/25.
//  Copyright (c) 2015年 翁 旭扬. All rights reserved.
//
/*
#import <Foundation/Foundation.h>

//@interface
@interface MyPoint:NSObject

-(void) print;
-(void) setXPoint:(int) n;
-(void) setYPoint:(int) n;
-(int) getXPoint;
-(int) getYPoint;

@end

//@implementation
@implementation MyPoint
{
    int xPoint;
    int yPoint;
}
-(void)print
{
    NSLog(@"%i,%i",xPoint,yPoint);
}
-(void)setXPoint:(int)n
{
    xPoint=n;
}
-(void)setYPoint:(int)n
{
    yPoint=n;
}
-(int)getXPoint
{
    return xPoint;
}
-(int)getYPoint
{
    return yPoint;
}

@end
//@program
int main()
{
    @autoreleasepool {
        MyPoint *point1=[[MyPoint alloc] init];
        [point1 setXPoint:1];
        [point1 setYPoint:2];
        [point1 print];
        NSLog(@"%i,%i",[point1 getXPoint],[point1 getYPoint]);
    }
}
*/
/*
#import <Foundation/Foundation.h>

int main()
{
    @autoreleasepool {
        int number;
        NSLog(@"n and n^2");
        NSLog(@"n  n^2");
        NSLog(@"--  --");
        for(number=1;number<11;number++)
        {
            NSLog(@" %i  %i" ,number,number*number);
        }
    }
}
*/
#import<Foundation/Foundation.h>
int main()
{
    int inputA,inputB;
    NSLog(@"Please in put two number:");
    scanf("%i%i",&inputA,&inputB);
    if (inputA%inputB==0) {
        NSLog(@"%i can divided by %i",inputA,inputB);
    }
    else
    {
        NSLog(@"%i can't divided by %i",inputA,inputB);
    }
}