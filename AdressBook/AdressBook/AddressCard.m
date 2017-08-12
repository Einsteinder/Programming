    //
    //  AdressCard.m
    //  AdressBook
    //
    //  Created by 翁 旭扬 on 15/5/23.
    //  Copyright (c) 2015年 翁 旭扬. All rights reserved.
    //

    #import "AddressCard.h"

    @implementation AddressCard

    @synthesize name,email;
-(BOOL)isEqual:(AddressCard*) theCard
{
    if ([name isEqualToString:theCard.name]==YES &&[email isEqualToString:theCard.email]==YES){
        return YES;
    }
    else
    {
        return NO;
    }
}
    -(void) print
    {
        NSLog(@"========================================");
        NSLog(@"|                                 |");
        NSLog(@"|  %-31s |",[name UTF8String]);
        NSLog(@"|  %-31s |",[email UTF8String]);
        NSLog(@"|                                 |");
        NSLog(@"|                                 |");
        NSLog(@"|                                 |");
        NSLog(@"|          o          o           |");
        NSLog(@"========================================");
        
    }
    -(void) setName:(NSString *)theName andEmail:(NSString *)theEmail
    {
        name=theName;
        email=theEmail;
    }

    @end
