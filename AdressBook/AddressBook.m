    //
    //  AddressBook.m
    //  AdressBook
    //
    //  Created by 翁 旭扬 on 15/5/23.
    //  Copyright (c) 2015年 翁 旭扬. All rights reserved.
    //

    #import "AddressBook.h"

    @implementation AddressBook
@synthesize bookName,book;//,resultOfLookup;



    -(instancetype) initWithName:(NSString *)name
    {
        self =[super init];
        if (self) {
            bookName = [NSString stringWithString:name];
            book=[NSMutableArray array];
          //  resultOfLookup = [NSMutableArray array];
        }
        return self;
    }

    -(instancetype) init:(NSString *)name
    {
        return [self initWithName:@"NoName"];
    }
-(void) removeCard:(AddressCard*) theCard;
{
    [book removeObject:theCard];
}


    -(void) addCard:(AddressCard *)theCard
    {
        [book addObject:theCard];
    }
//部分符合
-(AddressBook *) extLookUp: (NSString *) theName
{
    NSRange nameRange, emailRange;
    AddressBook *matches;
    matches = [[AddressBook alloc] initWithName: @"Matches"];
    
    for (AddressCard *nextCard in book)
    {
        nameRange = [[nextCard name] rangeOfString: theName options: NSCaseInsensitiveSearch];
        emailRange = [[nextCard email] rangeOfString: theName options: NSCaseInsensitiveSearch];
        if ((nameRange.location != NSNotFound) || (emailRange.location != NSNotFound))
            [matches addCard: nextCard];
    }
    
    if ([matches entries] == 0)
        return nil;
    else
        return matches;
}
//部分符合我的版本
-(NSMutableArray *) myLookup:(NSString *) theName
{
    NSMutableArray * resultOfLookup=[NSMutableArray array];
    for (AddressCard *nextCard in book) {
        if ([nextCard.name localizedCaseInsensitiveCompare:theName] == NSOrderedSame) {
            [resultOfLookup addObject:nextCard];
        }
    }
    return resultOfLookup;
}
    -(AddressCard *) lookup:(NSString *) theName
    {
        for (AddressCard *nextCard in book) {
            if ([nextCard.name caseInsensitiveCompare:theName] == NSOrderedSame) {
                return nextCard;
            }
        }
        return nil;
    }
    -(int) entries
    {
        return [book count];
    }
    -(void)list
    {
        NSLog(@"======== Contents of: %@ =========", bookName);
        
        for (AddressCard * theCard in book) {
            NSLog(@"%-20s   %-32s", [theCard.name UTF8String],[theCard.email UTF8String]);
        }
        NSLog(@"=======================================================");
    }

    @end
