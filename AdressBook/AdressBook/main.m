    //
    //  main.m
    //  AdressBook
    //
    //  Created by 翁 旭扬 on 15/5/23.
    //  Copyright (c) 2015年 翁 旭扬. All rights reserved.
    //

    #import "AddressBook.h"

    int main(int argc, const char * argv[]) {
        @autoreleasepool {
            NSString *aName = @"Julia Kochan";
            NSString *aEmail= @"jewls337@axlc.com";
            NSString *bName = @"Tony Iannino";
            NSString *bEmail=@"tony.iannino@techfitness.com";
            NSString *cName = @"Stephen Kochan";
            NSString *cEmail= @"steve@classroomM.com";
            NSString *dName = @"Jamie Baker";
            NSString *dEmail=@"jbaker@classroomM.com";
            
            AddressCard *card1=[[AddressCard alloc] init];
            AddressCard *card2=[[AddressCard alloc] init];
            AddressCard *card3=[[AddressCard alloc] init];
            AddressCard *card4=[[AddressCard alloc] init];
            
          
            
            AddressBook *myBook=[[AddressBook alloc] initWithName:@"Linda's Address Book"];
            AddressCard *myCard=[[AddressCard alloc] init];
            AddressBook *lookupResult=[[AddressBook alloc] init];
            NSMutableArray *MyLookupResult=[[NSMutableArray alloc] init];
            
            //NSLog(@"Entries in address book after creation: %i",[myBook entries]);
            [card1 setName:aName andEmail: aEmail];
            [card2 setName:bName andEmail:bEmail];
            [card3 setName:cName andEmail:cEmail];
            [card4 setName:dName andEmail:dEmail];
            
            [myBook addCard:card1];
            [myBook addCard:card2];
            [myBook addCard:card3];
            [myBook addCard:card4];
            /*
            NSLog(@"Stephen Kochan");
            myCard=[myBook lookup:@"Stephen Kochan"];
            
           // NSLog(@"%@",myCard);
            myCard = [myBook lookup:@"Stephen Kochan"];
            
            if (myCard!=nil) {
                [myCard print];
            }
            else
            {
                NSLog(@"Not Found");
            }

            */
            NSLog(@"我的版本");
            MyLookupResult=[myBook myLookup:@"Stephen Kochan"];
            NSLog(@"%@",MyLookupResult);
            
            for (AddressCard * theCard in MyLookupResult) {
                NSLog(@"%-20s   %-32s", [theCard.name UTF8String],[theCard.email UTF8String]);
            }
            
            /*
            NSLog(@"Stephe");
            lookupResult=[myBook extLookUp:@"S"];
            [lookupResult list];
            [myBook list];
            [myBook removeCard:myCard];
            [myBook list];
            
            
            */
            //NSLog(@"======== Contents of: %@ =========", bookName);
            
        
           /*
            
            NSLog(@"Haibo Zhang");
            myCard = [myBook lookup:@"Haibo Zhang"];
            
            if (myCard!=nil) {
                [myCard print];
            }
            else
            {
                NSLog(@"Not Found");
            }
            */
            
            
            
            //NSLog(@"Entries in address book after adding cards: %i",[myBook entries]);
            
           // [myBook list];
            
            
            // insert code here...
            //NSLog(@"Hello, World!");
        }
        return 0;
    }
