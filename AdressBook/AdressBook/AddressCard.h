    //
    //  AdressCard.h
    //  AdressBook
    //
    //  Created by 翁 旭扬 on 15/5/23.
    //  Copyright (c) 2015年 翁 旭扬. All rights reserved.
    //

    #import <Foundation/Foundation.h>

    @interface AddressCard : NSObject

    @property (copy,nonatomic) NSString *name, *email;
    -(void) setName:(NSString *) theName andEmail: (NSString *) theEmail;

    -(void) print;
-(BOOL)isEqual:(AddressCard*) theCard;
    @end
