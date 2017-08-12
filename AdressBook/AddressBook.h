    //
    //  AddressBook.h
    //  AdressBook
    //
    //  Created by 翁 旭扬 on 15/5/23.
    //  Copyright (c) 2015年 翁 旭扬. All rights reserved.
    //

    #import <Foundation/Foundation.h>
    #import "AddressCard.h"

    @interface AddressBook : NSObject

    @property (nonatomic,copy) NSString *bookName;
@property (nonatomic,strong)NSMutableArray *book;//*resultOfLookup;

    -(instancetype) initWithName:(NSString *) name;
    -(void) addCard: (AddressCard *) theCard;
-(void) removeCard:(AddressCard*) theCard;
-(BOOL)isEqual:(AddressCard*) theCard;
    -(int) entries;
    -(void) list;
    -(AddressCard *) lookup:(NSString *) theName;
    -(AddressBook *) extLookUp: (NSString *) theName;
-(NSMutableArray *) myLookup:(NSString *) theName;
    @end
