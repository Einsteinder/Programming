//
//  main.m
//  Enum
//
//  Created by 翁 旭扬 on 15/5/6.
//  Copyright (c) 2015年 翁 旭扬. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        enum month {January=1,February,March,April,May,June,July,August,September,October,Novenmber,December};
        enum month amonth;
        int days;
        
        NSLog(@"Enter a month:");
        scanf("%i",&amonth);
        
        switch(amonth)
        {
            case January:
            case March:
            case May:
            case July:
            case August:
            case October:
            case December:
                days=31;
                break;
            case April:
            case June:
            case September:
            case Novenmber:
                days=30;
                break;
            case February:
                days=28;
                break;
            default:
                NSLog(@"Input Error");
                break;
                
            
        }
        if (days!=0) {
            NSLog(@"This month have %i days",days);
        }
        if (amonth==February) {
            NSLog(@"It cound be 29 days if it's a leap year");
        }
        
        // insert code here...
        NSLog(@"Hello, World!");
    }
    return 0;
}
