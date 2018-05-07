//大數運算 +-* sample code 
#include <iostream>
#include <string.h>
#include "memory.h"
#define DIGITS 500

using namespace std;

void scan(char s[DIGITS],int b[DIGITS]){
	int n=0;
	for(int i=0;i<DIGITS-1;i++) //初始化陣列皆為0 
		{
			b[i]=0;
		}
	for(int i=strlen(s)-1;i>=0;i--) //逆輸入至陣列 
		{
			b[i]=s[n]-'0';
			n++;
		}
}

void print(int c[DIGITS]){
	int i=DIGITS-1;
	while (c[i] == 0) i--;  // 數字開頭的零都不印
    while (i >= 0) cout << c[i--];
}

void Add(int a[DIGITS], int b[DIGITS],int c[DIGITS]){
		for(int i=0;i<DIGITS;i++)
		c[i]=0;
	
	for(int i=0;i<DIGITS-1;i++) //加法 
		{ 
			c[i]=a[i]+b[i];
		} 
	for(int i=0;i<DIGITS-1;i++) //進位check 
		{
			c[i+1]=c[i+1]+c[i]/10;
			c[i]=c[i]%10;
		}	
}

void Subtraction(int a[DIGITS], int b[DIGITS],int c[DIGITS]){
		for(int i=0;i<DIGITS;i++)
		c[i]=0;
	bool comp=true; // a>b: true a<b: False
	for(int i=DIGITS-1;i>=0;i--)
		{
			if(a[i]>=b[i])
				{
					comp=true;
					continue;
				}
			else
				{
					comp=false;
					break;				
				}
		}
	for(int i=0;i<DIGITS-1;i++) //減法 
		{ 
			if(comp==true)
				c[i]=a[i]-b[i];
			else
				c[i]=b[i]-a[i];
		}
		
	for(int i=0;i<DIGITS-1;i++)
		{
			while(c[i]<0)
				{
					c[i+1]=c[i+1]-1;
					c[i]=c[i]+10;
				}
		}
	//處理負數 
	if(comp==false)
		{
				int l=DIGITS-1;
			while (c[l] == 0) l--; 
			while(c[l]>0)
				{
				c[l]=c[l]*(-1);
				break;
				}
					}			
}
		
void Multiplication(int a[DIGITS], int b[DIGITS],int c[DIGITS]){
	for(int i=0;i<DIGITS;i++) //清空C陣列 
		c[i]=0;
	
	for(int i=0;i<=DIGITS-1;i++) 
		for(int j=0;j<=DIGITS-1;j++)
			if(i+j<DIGITS-1)
				c[i+j]+=a[i]*b[j];
		
		
	for(int i=0;i<DIGITS-1;i++) //進位check 
		{
			c[i+1]=c[i+1]+c[i]/10;
			c[i]=c[i]%10;
		}		


	
	
}



int main(){
	
	char oper, input1[DIGITS],input2[DIGITS];
	while(cin>>input1>>oper>>input2){
		int array1[DIGITS]; //設令要放Input1的陣列大小
		int array2[DIGITS]; //設令要放Input2的陣列大小
		int array3[DIGITS]; //設定要放兩數運算後的陣列大小 
	
		//把String一位一位輸入至陣列 
		scan(input1,array1);
		scan(input2,array2);
		
		
		switch(oper) 
			{ 
				case'+':
				Add(array1,array2,array3);			
				break;
				
				case'-':
				Subtraction(array1,array2,array3);
				break;
				
				case'*': 
				Multiplication(array1,array2,array3);
				break;
				
				default:
				break;
				
				
			}
		//輸出陣列 
		print(array3);
		cout<<endl;

}			

	
return 0;	
	
	
} 
