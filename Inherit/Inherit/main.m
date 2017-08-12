//
//  main.m
//  Inherit
//
//  Created by 翁 旭扬 on 15/5/4.
//  Copyright (c) 2015年 翁 旭扬. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ClassA :NSObject
{
    int x;
}

-(void) intVar;
-(void) printVar;
@end


@implementation ClassA
-(void)intVar
{
    x=100;
}
-(void)printVar
{
    NSLog(@"x=%i",x);
}
@end


@interface ClassB:ClassA
-(void) intVar;
//-(void) printVar;

@end

@implementation ClassB
-(void)intVar
{
    x=201;
}
/*-(void) printVar
{
    NSLog(@"x=%i",x);
}
 */
@end



int main(int argc, const char * argv[]) {
    @autoreleasepool {
        ClassA *a=[[ClassA alloc]init];
        ClassB *b=[[ClassB alloc]init];
        [a intVar];
        [a printVar];
        [b intVar];
        [b printVar];
    }
    return 0;
}
