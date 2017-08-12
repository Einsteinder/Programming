//
//  NSDate+ElapseDays.m
//  OCExercise15.6-1
//
//  Created by 翁 旭扬 on 15/5/28.
//  Copyright (c) 2015年 翁 旭扬. All rights reserved.
//

#import "NSDate+ElapseDays.h"

@implementation NSDate(ElapsedDays)

-(unsigned long)elapsedDays:(NSDate *)theDate
{
    unsigned long interval;
    interval = ([theDate timeIntervalSince1970] - [self timeIntervalSince1970])/3600/24;
    return interval;
}

@end
