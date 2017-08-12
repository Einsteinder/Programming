//
//  main.m
//  Rectangle
//
//  Created by 翁 旭扬 on 15/5/3.
//  Copyright (c) 2015年 翁 旭扬. All rights reserved.
//

#import "Rectangle.h"
#import "XYPoint.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        Rectangle *myRect=[[Rectangle alloc]init];
        XYPoint * myPoint=[[XYPoint alloc]init];
        [myPoint setX:100 andY:200];
       // [myRect setWidth:80 andHeight:40];
        //myRect.origin=myPoint;
        [myRect setOrigin:myPoint];
        NSLog(@"Origin at(%i,%i)",myRect.origin.x,myRect.origin.y);
        
        
        [myPoint setX:50 andY:50];
        NSLog(@"Origin at(%i,%i)",myRect.origin.x,myRect.origin.y);
        
        
        XYPoint *theOrigin = myRect.origin;
        theOrigin.x=200;
        theOrigin.y=300;
        NSLog(@"Origin at(%i,%i)",myRect.origin.x,myRect.origin.y);
        [myRect draw];
        
        // insert code here...
        NSLog(@"Hello, World!");
    }
    return 0;
}
