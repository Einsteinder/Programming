//
//  main.c
//  FinalexamReview
//
//  Created by 翁 旭扬 on 14/12/27.
//  Copyright (c) 2014年 翁 旭扬. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    //include <stdio.h>
    //void main() {
        int x = 0x80000001;
        int y;
        y = x>>1;
        printf("%x,%d",y,y);
    //}//how about unsigned int ?

    return 0;
}
