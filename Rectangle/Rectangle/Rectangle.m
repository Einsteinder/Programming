//
//  Rectangle.m
//  Rectangle
//
//  Created by 翁 旭扬 on 15/5/3.
//  Copyright (c) 2015年 翁 旭扬. All rights reserved.
//

#import "Rectangle.h"
#import "XYPoint.h"
@implementation Rectangle
{
    XYPoint *origin;
}
@synthesize width,height;

-(void)setWidth:(int)w andHeight:(int)h
{
    width=w;
    height=h;
}
-(id) initWithWidth:(int)w andHeight:(int)h
{
    self=[super init];
    if (self) {
        [self setWidth:w andHeight:h];
    }
    return self;
}
-(instancetype) init
{
    return [self initWithWidth:5 andHeight:6];
}
-(void)setOrigin:(XYPoint *)pt
{
   if(! origin){
        origin=[[XYPoint alloc]init];
    
    origin.x=pt.x;
    origin.y=pt.y;
    }
    
}
-(void) draw
{
    printf(" ");
    for (int i=0; i<width; i++) {
        printf("-");
    }
    printf("\n");
    for (int j=0; j<height; j++)
    {
        printf("|");
        for (int k=0; k<width; k++)
        {
            printf(" ");
        }
        printf("|\n");
        
    }
    printf(" ");
    for (int i=0; i<width; i++) {
        printf("-");
    }
    printf("\n");
    
}
-(int)area
{
    return width*height;
}
-(int)perimeter
{
    return (width+height)*2;
}
-(XYPoint *)origin
{
    XYPoint *origin1=[[XYPoint alloc]init];
    origin1.x=origin.x;
    origin1.y=origin.y;
    
    return origin1;
}

@end
