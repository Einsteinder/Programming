//
//  main.m
//  OCExercise15.6-1
//
//  Created by 翁 旭扬 on 15/5/28.
//  Copyright (c) 2015年 翁 旭扬. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSDate+ElapseDays.h"
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        long int days;
        NSTimeInterval time1=123123;
        NSDate *today = [NSDate date];
        NSDate *date  = [[NSDate alloc ]initWithTimeIntervalSince1970:time1];
        
        days = [today elapsedDays:date];
        
        printf("these dates are %li days apart", days);
    }
    return 0;
}
