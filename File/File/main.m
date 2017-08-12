//
//  main.m
//  File
//
//  Created by 翁 旭扬 on 15/6/2.
//  Copyright (c) 2015年 翁 旭扬. All rights reserved.
//

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSFileManager *fm;
        NSFileHandle *inFile, *outFile;
        NSData *buffer;
        NSURL *myURL = [NSURL URLWithString:@"http://www.baiud.com"];
        NSString *myHomePage = [NSString stringWithContentsOfURL:myURL encoding:NSASCIIStringEncoding error:NULL];
        
        fm = [NSFileManager defaultManager];
        [fm createFileAtPath:@"testout" contents:nil attributes:nil];
        
        NSLog(@"%@",[fm currentDirectoryPath]);
        
        inFile = [NSFileHandle fileHandleForReadingAtPath:@"fileA"];
        
        if (inFile == nil) {
            NSLog(@"Open of fileA for reading failed ");
            return 1;
        }
        
        outFile = [NSFileHandle fileHandleForWritingAtPath:@"fileB"];
        
        if (outFile == nil) {
            NSLog(@"Open of fileB for writing failed");
            return 2;
        }
        
        [outFile seekToEndOfFile];
        
        buffer = [inFile readDataToEndOfFile];
        [outFile writeData:buffer];
        
         [inFile closeFile];
         [outFile closeFile];
        NSLog(@"%@",[NSString stringWithContentsOfFile:@"fileB" encoding:NSUTF8StringEncoding error:NULL]);
        NSLog(@"%@",myHomePage);
        
        
    }
    return 0;
}
