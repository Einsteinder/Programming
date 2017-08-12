//
//  Rectangle.h
//  Rectangle
//
//  Created by 翁 旭扬 on 15/5/3.
//  Copyright (c) 2015年 翁 旭扬. All rights reserved.
//

#import <Foundation/Foundation.h>

@class XYPoint;
@interface Rectangle : NSObject

@property int width,height;

-(XYPoint*) origin;
-(void) setOrigin:(XYPoint*) pt;
-(void) setWidth:(int) w andHeight:(int) h;
-(int) area;
-(int) perimeter;
-(void) draw;
-(id) initWithWidth:(int) w andHeight: (int) h;


@end
