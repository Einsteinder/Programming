//
//  main.m
//  Copy
//
//  Created by 翁 旭扬 on 15/6/2.
//  Copyright (c) 2015年 翁 旭扬. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSMutableArray *dataArray = [ NSMutableArray arrayWithObjects:[NSMutableString stringWithString:@"one"],
                                                                [NSMutableString stringWithString:@"two"],
                                     [NSMutableString stringWithString:@"three"],nil];
        
        NSMutableArray *dataArray2;
        NSMutableString *mStr;
        
        NSLog(@"dataArray: ");
        for(NSString *elem in dataArray)
        {
            NSLog(@"  %@",elem);
        }
        
        dataArray2 = [dataArray mutableCopy];
        
        mStr = dataArray[0];
        [mStr appendString:@"ONE"];
        
        NSLog(@"dataArray: ");
        for(NSString *elem in dataArray)
        {
            NSLog(@"  %@",elem);
        }
        
        NSLog(@"dataArray2: ");
        for( NSString *elem in dataArray2)
        {
            NSLog(@"  %@",elem);
        }
        
    }
    return 0;
}
