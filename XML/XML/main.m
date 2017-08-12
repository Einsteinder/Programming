//
//  main.m
//  XML
//
//  Created by 翁 旭扬 on 15/6/2.
//  Copyright (c) 2015年 翁 旭扬. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSDictionary *glossary = @{@"abstract class": @"A class defined so other classes can inherit from it.",
                                   @"adopt": @"To implement all the methods defined in a protocol ",
                                   @"archiving": @"Storing an object for later use."
                                   };
        if ([glossary writeToFile:@"glossary" atomically:YES]==NO) {
            NSLog(@"Save to file failed!");
        }
    return 0;
}
}