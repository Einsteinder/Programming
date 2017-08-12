//
//  ViewController.h
//  Fraction_Calculator
//
//  Created by 翁 旭扬 on 15/6/6.
//  Copyright (c) 2015年 翁 旭扬. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController

@property (strong, nonatomic) IBOutlet UILabel *display;

-(void) processDigit: (int) digit;
-(void) processOp: (char) theOp;
-(void) storeFracPart;

-(IBAction)clickDigit:(UIButton *) sender;

-(IBAction) clickPlus;
-(IBAction) clickMinus;
-(IBAction) clickMutiply;
-(IBAction) clickDivide;

-(IBAction) clickOver;
-(IBAction) clickEquals;
-(IBAction) clickClear;


@end

