//
//  ViewController.m
//  iPhone_1
//
//  Created by 翁 旭扬 on 15/6/6.
//  Copyright (c) 2015年 翁 旭扬. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

@synthesize display;

-(IBAction) click1
{
    display.text=@"1
    ";
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
