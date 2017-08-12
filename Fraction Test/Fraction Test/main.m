//
//  main.m
//  Fraction Test
//
//  Created by 翁 旭扬 on 15/5/2.
//  Copyright (c) 2015年 翁 旭扬. All rights reserved.
//

#import "Fraction.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        Fraction *aFraction=[[Fraction alloc]init];
        Fraction *bFraction=[[Fraction alloc]init];
        Fraction *resultFracttion=[[Fraction alloc]init];
        
        
        [aFraction setNumerator:1];
        [aFraction setDenominator:3];
        [bFraction setNumerator:88];
        [bFraction setDenominator:5];
        //resultFracttion=[aFraction add:bFraction];
        
        resultFracttion=[aFraction add:bFraction];
        
        
            
        // insert code here...
        NSLog(@"The value of resultFraction is:");
       // NSLog(@"%i,%i",1%3,3%1);
        [aFraction print];
        [bFraction print];
        [resultFracttion print];
        
        
        //测试copy
        Fraction *f1 = [[Fraction alloc] init];
        Fraction *f2;
        
        [f1 setTo:2 over:5];
        f2=[f1 copy];
        
        [f2 setTo:1 over:3];
        [f1 print];
        [f2 print];
        
    }
    return 0;
}
