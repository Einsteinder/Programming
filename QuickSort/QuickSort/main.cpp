//
//  main.cpp
//  Q
//
//  Created by 翁 旭扬 on 14-12-2.
//  Copyright (c) 2014年 翁 旭扬. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <stack>
using namespace std;

void swap(int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int partition(int A[], int l, int r, int& pivot) {
    do { // Move the bounds inward until they meet
        while (A[++l]<pivot); // Move l right and
        while ((l < r) && (pivot<A[--r])); // r left
        swap(A, l, r); // Swap out-of-place values
    } while (l < r); // Stop when they cross
    return l; // Return first position in right partition
}

int findpivot(int A[], int i, int j)
{
    return (i+j)/2;
}
void inssort(int A[], int n) { // Insertion Sort
    for (int i=1; i<n; i++) // Insert i’th record
        for (int j=i; (j>0) && (A[j]<A[j-1]); j--)
            swap(A, j, j-1);
}
int findpivot2(int A[],int i, int j)
{
    
    if (A[i]<A[j]&&A[(i+j)/2]<A[i]) {
        return i;
    }
    else if(A[(i+j)/2]<A[i]&&A[j]<A[(i+j)/2])
    {
        return (i+j)/2;
    }
    else //if(A[j]<A[i]&&A[(i+j)/2]<A[j])
    {
        return j;
    }
    
}



void qsort(int A[], int i, int j) { // Quicksort
    if (j <= i)
    {
        return;
    }// Don’t sort 0 or 1 element
    int pivotindex = findpivot(A, i, j);
    swap(A, pivotindex, j); // Put pivot at end
    // k will be the first position in the right subarray
    int k = partition(A, i-1, j, A[j]);
    swap(A, k, j); // Put pivot in place
    qsort(A, i, k-1);
    qsort(A, k+1, j);
}
void qsortLookMore(int A[], int i, int j) { // Quicksort
    if (j <= i)
    {
        return;
    }// Don’t sort 0 or 1 element
    int pivotindex = findpivot2(A, i, j);
    swap(A, pivotindex, j); // Put pivot at end
    // k will be the first position in the right subarray
    int k = partition(A, i-1, j, A[j]);
    swap(A, k, j); // Put pivot in place
    qsortLookMore(A, i, k-1);
    qsortLookMore(A, k+1, j);
}
void qsortaddinssort(int A[], int i, int j,int tv)
{
    while(j<=tv)
    {
        inssort(A,j+1);
        return;
    }
    if (j <= i)
    {
        return;
    }// Don’t sort 0 or 1 element
    int pivotindex = findpivot(A, i, j);
    swap(A, pivotindex, j); // Put pivot at end
    // k will be the first position in the right subarray
    int k = partition(A, i-1, j, A[j]);
    // swap(A, k, j); // Put pivot in place
    
    
    swap(A, k, j); // Put pivot in place
    qsortaddinssort(A, i, k-1,tv);
    qsortaddinssort(A, k+1, j,tv);
    
}
void qsortaddinssortLookMore(int A[], int i, int j)
{
    while(j<=2)
    {
        inssort(A,j+1);
        return;
    }
    if (j <= i)
    {
        return;
    }// Don’t sort 0 or 1 element
    int pivotindex = findpivot2(A, i, j);
    swap(A, pivotindex, j); // Put pivot at end
    // k will be the first position in the right subarray
    int k = partition(A, i-1, j, A[j]);
    // swap(A, k, j); // Put pivot in place
    
    
    swap(A, k, j); // Put pivot in place
    qsortaddinssortLookMore(A, i, k-1);
    qsortaddinssortLookMore(A, k+1, j);
    
}
void quicksortStack(int a[], int x,int size)
{
	int mystack[100];
	int top=-1;
	mystack[++top] = 0;
	mystack[++top] = size-1;
    
	while (top>0)
	{
		int end = mystack[top--];
		int start = mystack[top--];
        
		int x = a[end];
		int i = start-1;
		for (int j = start; j < end; j++)
		{
			if (a[j] < x)
			{
				i++;
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				//exch(a[i], a[j]);
			}
		}
		int temp = a[i+1];
		a[i+1] = a[end];
		a[end] = temp;
		//exch(a[i+1], a[end]);
		if (start < i)
		{
			mystack[++top]=start;
			mystack[++top]=i;
		}
		if (i+2 < end)
		{
			mystack[++top] = i+2;
			mystack[++top] = end;
		}
	}
}

/*
void quicksortStack(int A[],int i,int j){
	stack<int> st;
	if(i<j){
        int k=partition(A,i,j,A[j]);
		if(i<k-1){
			st.push(i);
			st.push(k-1);
		}
		if(k<j){
			st.push(k);
			st.push(j);
		}
		
		while(!st.empty()){
            
			int q=st.top();
			st.pop();
			int p=st.top();
			st.pop();
            int pivotindex = findpivot(A, p, q);
            swap(A, pivotindex, q);
            int kk=partition(A,p,q,A[q]);
            swap(A, kk, q); // Put pivot in place
            
            //	k=partition(A,p,q,A[q]);
            
			if(p<kk-1){
				st.push(p);
				st.push(kk-1);
			}
            
			if(kk<q){
				st.push(kk);
				st.push(q);
			}
            
		}
	}
    
}*/
void quicksortStackLookMore(int a[], int x,int size)
{
	int mystack[100];
	int top=-1;
	mystack[++top] = 0;
	mystack[++top] = size-1;
    
	while (top>0)
	{
		int end = mystack[top--];
		int start = mystack[top--];
        int pivot= findpivot2(a, start, end);
        
		int x = a[pivot];//pivot
		int i = start-1;
		for (int j = start; j < end; j++)
		{
			if (a[j] < x)
			{
				i++;
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
        //exchange pivot
		int temp = a[i+1];
		a[i+1] = a[end];
		a[end] = temp;
		if (start < i)
		{
			mystack[++top]=start;
			mystack[++top]=i;
		}
		if (i+2 < end)
		{
			mystack[++top] = i+2;
			mystack[++top] = end;
		}
	}
}
/*
void quicksortStackLookMore(int A[],int i,int j){
	stack<int> st;
	if(i<j){
        int k=partition(A,i,j,A[j]);
		if(i<k-1){
			st.push(i);
			st.push(k-1);
		}
		if(k<j){
			st.push(k);
			st.push(j);
		}
		
		while(!st.empty()){
            
			int q=st.top();
			st.pop();
			int p=st.top();
			st.pop();
            int pivotindex = findpivot2(A, p, q);
            swap(A, pivotindex, q);
            int kk=partition(A,p,q,A[q]);
            swap(A, kk, q); // Put pivot in place
            
            //	k=partition(A,p,q,A[q]);
            
			if(p<kk-1){
				st.push(p);
				st.push(kk-1);
			}
            
			if(kk<q){
				st.push(kk);
				st.push(q);
			}
            
		}
	}
    
}
 */
void quicksortStackInsert(int a[], int x,int size,int tv)
{
	int mystack[100];
	int top=-1;
	mystack[++top] = 0;
	mystack[++top] = size-1;
    
	while (top>0)
	{
        
		int end = mystack[top--];
		int start = mystack[top--];
    while (end-start<tv) {
           inssort(a, end);
           return;
      }
        int x = a[end];
        
		//int x = a[pivot];//pivot
		int i = start-1;
		for (int j = start; j < end; j++)
		{
			if (a[j] < x)
			{
				i++;
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
        //exchange pivot
		int temp = a[i+1];
		a[i+1] = a[end];
		a[end] = temp;
		if (start < i)
		{
			mystack[++top]=start;
			mystack[++top]=i;
		}
		if (i+2 < end)
		{
			mystack[++top] = i+2;
			mystack[++top] = end;
		}
	}
}
/*
void quicksortStackInsert(int A[],int i,int j,int tv){//threshold value
	stack<int> st;
	if(i<j){
        int k=partition(A,i,j,A[j]);
		if(i<k-1){
			st.push(i);
			st.push(k-1);
		}
		if(k<j){
			st.push(k);
			st.push(j);
		}
		
		while(!st.empty()){
            
			int q=st.top();
			st.pop();
			int p=st.top();
			st.pop();
            while (q-p<tv) {
                inssort(A, q);
                return;
            }
            int pivotindex = findpivot(A, p, q);
            swap(A, pivotindex, q);
            int kk=partition(A,p,q,A[q]);
            swap(A, kk, q); // Put pivot in place
            
            //	k=partition(A,p,q,A[q]);
            
			if(p<kk-1){
				st.push(p);
				st.push(kk-1);
			}
            
			if(kk<q){
				st.push(kk);
				st.push(q);
			}
            
		}
	}
    
}
 */

void quicksortStackInsertLookMore(int a[], int x,int size,int tv)
{
	int mystack[100];
	int top=-1;
	mystack[++top] = 0;
	mystack[++top] = size-1;
    
	while (top>0)
	{
        
		int end = mystack[top--];
		int start = mystack[top--];
        while (end-start<tv) {
            inssort(a, end);
            return;
        }
        int  pivot=findpivot2(a, start, end);
        int x = a[pivot];
        
		//int x = a[pivot];//pivot
		int i = start-1;
		for (int j = start; j < end; j++)
		{
			if (a[j] < x)
			{
				i++;
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
        //exchange pivot
		int temp = a[i+1];
		a[i+1] = a[end];
		a[end] = temp;
		if (start < i)
		{
			mystack[++top]=start;
			mystack[++top]=i;
		}
		if (i+2 < end)
		{
			mystack[++top] = i+2;
			mystack[++top] = end;
		}
	}
}
/*
void quicksortStackInsertLookMore(int A[],int i,int j,int tv){
	stack<int> st;
	if(i<j){
        int k=partition(A,i,j,A[j]);
		if(i<k-1){
			st.push(i);
			st.push(k-1);
		}
		if(k<j){
			st.push(k);
			st.push(j);
		}
		
		while(!st.empty()){
            
			int q=st.top();
			st.pop();
			int p=st.top();
			st.pop();
            while (q-p<tv) {
                inssort(A, q);
                return;
            }
            int pivotindex = findpivot2(A, p, q);
            swap(A, pivotindex, q);
            int kk=partition(A,p,q,A[q]);
            swap(A, kk, q); // Put pivot in place
            
            //	k=partition(A,p,q,A[q]);
            
			if(p<kk-1){
				st.push(p);
				st.push(kk-1);
			}
            
			if(kk<q){
				st.push(kk);
				st.push(q);
			}
            
		}
	}
    
}
 */
int main(int argc, const char * argv[])
{
    
    cout<<"Please input the Insersort Threshold value:";
    int k;
    cin>>k;
    //  time_t start = ;
    
    cout<<"n=                        "<<10<<"     "<<100<<"    "<<1000<<"  "<<10000<<"  "<<100000<<"  "<<1000000<<endl;
    // int x=randint();
    // srand((unsigned int)time((time_t *)NULL));
    srand(1);
    int n11=10;
    int *list11=new int[n11];
    for (int i=0; i<n11; i++) {
        
        // x=;
        list11[i]=rand();
        
    }
    time_t start11=clock();
    qsort(list11,0,n11-1);
    time_t end11=clock();
    cout<<"Initial:                  "<<double(end11 -start11)*1000/CLOCKS_PER_SEC<<" ";
    
    
    //n=100
    int n12=100;
    int *list12=new int[n12];
    for (int i=0; i<n12; i++) {
        
        list12[i]=rand();
        
    }
    time_t start12=clock();
    qsort(list12,0,n12-1);
    time_t end12=clock();
    cout<<" "<<double(end12 -start12)*1000/CLOCKS_PER_SEC<<" ";
    
    //n=1000
    int n13=1000;
    int *list13=new int[n13];
    for (int i=0; i<n13; i++) {
        
        list13[i]=rand();
        
    }
    time_t start13=clock();
    qsort(list13,0,n13-1);
    time_t end13=clock();
    cout<<" "<<double(end13 -start13)*1000/CLOCKS_PER_SEC<<" ";
    
    //n=10000
    int n14=10000;
    int *list14=new int[n14];
    for (int i=0; i<n14; i++) {
        
        list14[i]=rand();
        
    }
    time_t start14=clock();
    qsort(list14,0,n14-1);
    time_t end14=clock();
    cout<<" "<<double(end14 -start14)*1000/CLOCKS_PER_SEC<<" ";
    
    
    //n=100000
    int n15=100000;
    int *list15=new int[n15];
    for (int i=0; i<n15; i++) {
        
        list15[i]=rand();
        
    }
    time_t start15=clock();
    qsort(list15,0,n15-1);
    time_t end15=clock();
    cout<<" "<<double(end15 -start15)*1000/CLOCKS_PER_SEC<<" ";
    
    
    
    //n=1000000
    int n16=1000000;
    int *list16=new int[n16];
    for (int i=0; i<n16; i++) {
        
        list16[i]=rand();
        
    }
    time_t start16=clock();
    qsort(list16,0,n16-1);
    time_t end16=clock();
    cout<<" "<<double(end16 -start16)*1000/CLOCKS_PER_SEC<<endl;
    
    
    //lookmore n=10
    int n21=10;
    int *list21=new int[n21];
    for (int i=0; i<n21; i++) {
        
        list21[i]=rand();
        
    }
    time_t start21=clock();
    qsortLookMore(list21,0,n21-1);
    time_t end21=clock();
    cout<<"(a)LookMoreValueForPivot: "<<double(end21 -start21)*1000/CLOCKS_PER_SEC<<"  ";
    
    
    //lookmore n=100
    int n22=100;
    int *list22=new int[n22];
    for (int i=0; i<n22; i++) {
        
        list22[i]=rand();
        
    }
    time_t start22=clock();
    qsortLookMore(list22,0,n22-1);
    time_t end22=clock();
    cout<<""<<double(end22 -start22)*1000/CLOCKS_PER_SEC<<"  " ;
    
    
    //lookmore n=1000
    int n23=1000;
    int *list23=new int[n23];
    for (int i=0; i<n23; i++) {
        
        list23[i]=rand();
        
    }
    time_t start23=clock();
    qsortLookMore(list23,0,n23-1);
    time_t end23=clock();
    cout<<""<<double(end23 -start23)*1000/CLOCKS_PER_SEC<<"  ";
    
    //lookmore n=10000
    int n24=10000;
    int *list24=new int[n24];
    for (int i=0; i<n24; i++) {
        
        list24[i]=rand();
        
    }
    time_t start24=clock();
    qsortLookMore(list24,0,n24-1);
    time_t end24=clock();
    cout<<""<<double(end24 -start24)*1000/CLOCKS_PER_SEC<<" ";
    
    
    //lookmore n=100000
    int n25=100000;
    int *list25=new int[n25];
    for (int i=0; i<n25; i++) {
        
        list25[i]=rand();
        
    }
    time_t start25=clock();
    qsortLookMore(list25,0,n25-1);
    time_t end25=clock();
    cout<<" "<<double(end25 -start25)*1000/CLOCKS_PER_SEC<<"  ";
    
    
    //lookmore n=1000000
    int n26=1000000;
    int *list26=new int[n26];
    for (int i=0; i<n26; i++) {
        
        list26[i]=rand();
        
    }
    time_t start26=clock();
    qsortLookMore(list26,0,n26-1);
    time_t end26=clock();
    cout<<""<<double(end26 -start26)*1000/CLOCKS_PER_SEC<<endl;
    
    //ThresholdInsertSort n=10
    int n31=10;
    int *list31=new int[n31];
    for (int i=0; i<n31; i++) {
        
        list31[i]=rand();
        
    }
    time_t start31=clock();
    qsortaddinssort(list31,0,n31-1,k);
    time_t end31=clock();
    cout<<"(b)ThresholdInsertSort:   "<<double(end31 -start31)*1000/CLOCKS_PER_SEC<<" ";
    
    //ThresholdInsertSort n=100
    int n32=100;
    int *list32=new int[n32];
    for (int i=0; i<n32; i++) {
        
        list32[i]=rand();
        
    }
    time_t start32=clock();
    qsortaddinssort(list32,0,n32-1,k);
    time_t end32=clock();
    cout<<" "<<double(end32 -start32)*1000/CLOCKS_PER_SEC<<" ";
    
    
    //ThresholdInsertSort n=1000
    int n33=1000;
    int *list33=new int[n33];
    for (int i=0; i<n33; i++) {
        
        list33[i]=rand();
        
    }
    time_t start33=clock();
    qsortaddinssort(list33,0,n33-1,k);
    time_t end33=clock();
    cout<<""<<double(end33 -start33)*1000/CLOCKS_PER_SEC<<" ";
    
    //ThresholdInsertSort n=10000
    int n34=10000;
    int *list34=new int[n34];
    for (int i=0; i<n34; i++) {
        
        list34[i]=rand();
        
    }
    time_t start34=clock();
    qsortaddinssort(list34,0,n34-1,k);
    time_t end34=clock();
    cout<<""<<double(end34 -start34)*1000/CLOCKS_PER_SEC<<" ";
    
    //ThresholdInsertSort n=100000
    int n35=100000;
    int *list35=new int[n35];
    for (int i=0; i<n35; i++) {
        
        list35[i]=rand();
        
    }
    time_t start35=clock();
    qsortaddinssort(list35,0,n35-1,k);
    time_t end35=clock();
    cout<<""<<double(end35 -start35)*1000/CLOCKS_PER_SEC<<" ";
    
    //ThresholdInsertSort n=1000000
    int n36=1000000;
    int *list36=new int[n36];
    for (int i=0; i<n36; i++) {
        
        list36[i]=rand();
        
    }
    time_t start36=clock();
    qsortaddinssort(list36,0,n36-1,k);
    time_t end36=clock();
    cout<<""<<double(end36 -start36)*1000/CLOCKS_PER_SEC<<endl;
    
    
    //StackReplaceRecursion n=10
    int n41=10;
    int *list41=new int[n41];
    for (int i=0; i<n41; i++) {
        
        list41[i]=rand();
        
    }
    time_t start41=clock();
    quicksortStack(list41,0,n41-1);
    time_t end41=clock();
    cout<<"(c)StackReplaceRecursion: "<<double(end41 -start41)*1000/CLOCKS_PER_SEC<<" ";
    
    //StackReplaceRecursion n=100
    int n42=100;
    int *list42=new int[n42];
    for (int i=0; i<n42; i++) {
        
        list42[i]=rand();
        
    }
    time_t start42=clock();
    quicksortStack(list42,0,n42-1);
    time_t end42=clock();
    cout<<" "<<double(end42 -start42)*1000/CLOCKS_PER_SEC<<" ";
    
    
    //StackReplaceRecursion n=1000
    int n43=1000;
    int *list43=new int[n43];
    for (int i=0; i<n43; i++) {
        
        list43[i]=rand();
        
    }
    time_t start43=clock();
    quicksortStack(list43,0,n43-1);
    time_t end43=clock();
    cout<<""<<double(end43 -start43)*1000/CLOCKS_PER_SEC<<" ";
    
    //StackReplaceRecursion n=10000
    int n44=10000;
    int *list44=new int[n44];
    for (int i=0; i<n44; i++) {
        
        list44[i]=rand();
        
    }
    time_t start44=clock();
    quicksortStack(list44,0,n44-1);
    time_t end44=clock();
    cout<<""<<double(end44 -start44)*1000/CLOCKS_PER_SEC<<" ";
    
    //StackReplaceRecursion n=100000
    int n45=100000;
    int *list45=new int[n45];
    for (int i=0; i<n45; i++) {
        
        list45[i]=rand();
        
    }
    time_t start45=clock();
    quicksortStack(list45,0,n45-1);
    time_t end45=clock();
    cout<<""<<double(end45 -start45)*1000/CLOCKS_PER_SEC<<" ";
    
    //StackReplaceRecursion n=1000000
    int n46=1000000;
    int *list46=new int[n46];
    for (int i=0; i<n46; i++) {
        
        list46[i]=rand();
        
    }
    time_t start46=clock();
    quicksortStack(list46,0,n46-1);
    time_t end46=clock();
    cout<<""<<double(end46 -start46)*1000/CLOCKS_PER_SEC<<endl;
   // for (int i =0; i<n46; i++) {
   //     cout<<list46[i]<<endl;
   // }
    
    
    
    
    //(a) combine (b) n=10
    int n51=10;
    int *list51=new int[n51];
    for (int i=0; i<n51; i++) {
        
        list51[i]=rand();
        
    }
    time_t start51=clock();
    qsortaddinssortLookMore(list51,0,n51-1);
    time_t end51=clock();
    cout<<"(a) combine (b):          "<<double(end51 -start51)*1000/CLOCKS_PER_SEC<<" ";
    
    //(a) combine (b) n=100
    int n52=100;
    int *list52=new int[n52];
    for (int i=0; i<n52; i++) {
        
        list52[i]=rand();
        
    }
    time_t start52=clock();
    qsortaddinssortLookMore(list52,0,n52-1);
    time_t end52=clock();
    cout<<" "<<double(end52 -start52)*1000/CLOCKS_PER_SEC<<" ";
    
    
    //(a) combine (b) n=1000
    int n53=1000;
    int *list53=new int[n53];
    for (int i=0; i<n53; i++) {
        
        list53[i]=rand();
        
    }
    time_t start53=clock();
    qsortaddinssortLookMore(list53,0,n53-1);
    time_t end53=clock();
    cout<<""<<double(end53 -start53)*1000/CLOCKS_PER_SEC<<" ";
    
    //(a) combine (b) n=10000
    int n54=10000;
    int *list54=new int[n54];
    for (int i=0; i<n54; i++) {
        
        list54[i]=rand();
        
    }
    time_t start54=clock();
    qsortaddinssortLookMore(list54,0,n54-1);
    time_t end54=clock();
    cout<<""<<double(end54 -start54)*1000/CLOCKS_PER_SEC<<" ";
    
    //(a) combine (b) n=100000
    int n55=100000;
    int *list55=new int[n55];
    for (int i=0; i<n55; i++) {
        
        list55[i]=rand();
        
    }
    time_t start55=clock();
    qsortaddinssortLookMore(list55,0,n55-1);
    time_t end55=clock();
    cout<<""<<double(end55 -start55)*1000/CLOCKS_PER_SEC<<" ";
    
    //(a) combine (b) n=1000000
    int n56=1000000;
    int *list56=new int[n56];
    for (int i=0; i<n56; i++) {
        
        list56[i]=rand();
        
    }
    time_t start56=clock();
    qsortaddinssortLookMore(list56,0,n56-1);
    time_t end56=clock();
    cout<<""<<double(end56 -start56)*1000/CLOCKS_PER_SEC<<endl;
    
    
    //(a) combine (c) n=10
    int n61=10;
    int *list61=new int[n61];
    for (int i=0; i<n61; i++) {
        
        list61[i]=rand();
        
    }
    time_t start61=clock();
    quicksortStackLookMore(list61,0,n61-1);
    time_t end61=clock();
    cout<<"(a) combine (c):          "<<double(end61 -start61)*1000/CLOCKS_PER_SEC<<" ";
    
    //(a) combine (c) n=100
    int n62=100;
    int *list62=new int[n62];
    for (int i=0; i<n62; i++) {
        
        list62[i]=rand();
        
    }
    time_t start62=clock();
    quicksortStackLookMore(list62,0,n62-1);
    time_t end62=clock();
    cout<<" "<<double(end62 -start62)*1000/CLOCKS_PER_SEC<<" ";
    
    
    //(a) combine (c) n=1000
    int n63=1000;
    int *list63=new int[n63];
    for (int i=0; i<n63; i++) {
        
        list63[i]=rand();
        
    }
    time_t start63=clock();
    quicksortStackLookMore(list63,0,n63-1);
    time_t end63=clock();
    cout<<""<<double(end63 -start63)*1000/CLOCKS_PER_SEC<<" ";
    
    //(a) combine (c) n=10000
    int n64=10000;
    int *list64=new int[n64];
    for (int i=0; i<n64; i++) {
        
        list64[i]=rand();
        
    }
    time_t start64=clock();
    quicksortStackLookMore(list64,0,n64-1);
    time_t end64=clock();
    cout<<""<<double(end64 -start64)*1000/CLOCKS_PER_SEC<<" ";
    
    //(a) combine (c) n=100000
    int n65=100000;
    int *list65=new int[n65];
    for (int i=0; i<n65; i++) {
        
        list65[i]=rand();
        
    }
    time_t start65=clock();
    quicksortStackLookMore(list65,0,n65-1);
    time_t end65=clock();
    cout<<""<<double(end65 -start65)*1000/CLOCKS_PER_SEC<<" ";
    
    //(a) combine (c) n=1000000
    int n66=1000000;
    int *list66=new int[n66];
    for (int i=0; i<n66; i++) {
        
        list66[i]=rand();
        
    }
    time_t start66=clock();
    quicksortStackLookMore(list66,0,n66-1);
    time_t end66=clock();
    cout<<""<<double(end66 -start66)*1000/CLOCKS_PER_SEC<<endl;
    
    
    //(b) combine (c) n=10
    int n71=10;
    int *list71=new int[n71];
    for (int i=0; i<n71; i++) {
        
        list71[i]=rand();
        
    }
    time_t start71=clock();
    quicksortStackInsert(list71,0,n71-1,k);
    time_t end71=clock();
    cout<<"(b) combine (c):          "<<double(end71 -start71)*1000/CLOCKS_PER_SEC<<" ";
    
    //(b) combine (c) n=100
    int n72=100;
    int *list72=new int[n72];
    for (int i=0; i<n72; i++) {
        
        list72[i]=rand();
        
    }
    time_t start72=clock();
    quicksortStackInsert(list72,0,n72-1,k);
    time_t end72=clock();
    cout<<" "<<double(end72 -start72)*1000/CLOCKS_PER_SEC<<" ";
    
    
    //(b) combine (c) n=1000
    int n73=1000;
    int *list73=new int[n73];
    for (int i=0; i<n73; i++) {
        
        list73[i]=rand();
        
    }
    time_t start73=clock();
    quicksortStackInsert(list73,0,n73-1,k);
    time_t end73=clock();
    cout<<""<<double(end73 -start73)*1000/CLOCKS_PER_SEC<<" ";
    
    //(b) combine (c) n=10000
    int n74=10000;
    int *list74=new int[n74];
    for (int i=0; i<n74; i++) {
        
        list74[i]=rand();
        
    }
    time_t start74=clock();
    quicksortStackInsert(list74,0,n74-1,k);
    time_t end74=clock();
    cout<<""<<double(end74 -start74)*1000/CLOCKS_PER_SEC<<" ";
    
    //(b) combine (c) n=100000
    int n75=100000;
    int *list75=new int[n75];
    for (int i=0; i<n75; i++) {
        
        list75[i]=rand();
        
    }
    time_t start75=clock();
    quicksortStackInsert(list75,0,n75-1,k);
    time_t end75=clock();
    cout<<""<<double(end75 -start75)*1000/CLOCKS_PER_SEC<<" ";
    
    //(b) combine (c) n=1000000
    
    cout<<""<<"--------"<<endl;
    
    //(a) combine (b) and (c)) n=10
    int n81=10;
    int *list81=new int[n81];
    for (int i=0; i<n81; i++) {
        
        list81[i]=rand();
        
    }
    time_t start81=clock();
    quicksortStackInsertLookMore(list81,0,n81-1,k);
    time_t end81=clock();
    cout<<"(a) combine (b) and (c)): "<<double(end81 -start81)*1000/CLOCKS_PER_SEC<<" ";
    
    //(a) combine (b) and (c)) n=100
    int n82=100;
    int *list82=new int[n82];
    for (int i=0; i<n82; i++) {
        
        list82[i]=rand();
        
    }
    time_t start82=clock();
    quicksortStackInsertLookMore(list82,0,n82-1,k);
    time_t end82=clock();
    cout<<" "<<double(end82 -start82)*1000/CLOCKS_PER_SEC<<" ";
    
    
    //(a) combine (b) and (c)) n=1000
    int n83=1000;
    int *list83=new int[n83];
    for (int i=0; i<n83; i++) {
        
        list83[i]=rand();
        
    }
    time_t start83=clock();
    quicksortStackInsertLookMore(list83,0,n83-1,k);
    time_t end83=clock();
    cout<<""<<double(end83 -start83)*1000/CLOCKS_PER_SEC<<" ";
    
    //(a) combine (b) and (c)) n=10000
    int n84=10000;
    int *list84=new int[n84];
    for (int i=0; i<n84; i++) {
        
        list84[i]=rand();
        
    }
    time_t start84=clock();
    quicksortStackInsertLookMore(list84,0,n84-1,k);
    time_t end84=clock();
    cout<<""<<double(end84 -start84)*1000/CLOCKS_PER_SEC<<" ";
    
    //(a) combine (b) and (c)) n=100000
    int n85=100000;
    int *list85=new int[n85];
    for (int i=0; i<n85; i++) {
        
        list85[i]=rand();
        
    }
    time_t start85=clock();
    quicksortStackInsertLookMore(list85,0,n85-1,k);
    time_t end85=clock();
    cout<<""<<double(end85 -start85)*1000/CLOCKS_PER_SEC<<" ";
    
    //(a) combine (b) and (c)) n=1000000
    
    cout<<"  "<<"-------"<<endl;
    
    
    ///////qsortLookMore(list, 0, n-1);
    //////qsortaddinssort(list, 0, n-1);
    ///////quicksortStack(list, 0, n-1);
    //////qsortaddinssortLookMore(list, 0, n-1);
    //////quicksortStackLookMore(list, 0, n-1);
    //quicksortStackInsert(list, 0, n-1);
    //quicksortStackInsertLookMore(list, 0, n-1);
    
    
    
    
    //   for (int i=0; i<n11; i++)
    //     {
    //          cout<<list11[i]<<endl;
    //       }
    //   cout<<list[0]<<endl;
    // insert code here...
    return 0;
    
}

