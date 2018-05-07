//�j�ƹB�� +-* sample code 
#include <iostream>
#include <string.h>
#include "memory.h"
#define DIGITS 500

using namespace std;

void scan(char s[DIGITS],int b[DIGITS]){
	int n=0;
	for(int i=0;i<DIGITS-1;i++) //��l�ư}�C�Ҭ�0 
		{
			b[i]=0;
		}
	for(int i=strlen(s)-1;i>=0;i--) //�f��J�ܰ}�C 
		{
			b[i]=s[n]-'0';
			n++;
		}
}

void print(int c[DIGITS]){
	int i=DIGITS-1;
	while (c[i] == 0) i--;  // �Ʀr�}�Y���s�����L
    while (i >= 0) cout << c[i--];
}

void Add(int a[DIGITS], int b[DIGITS],int c[DIGITS]){
		for(int i=0;i<DIGITS;i++)
		c[i]=0;
	
	for(int i=0;i<DIGITS-1;i++) //�[�k 
		{ 
			c[i]=a[i]+b[i];
		} 
	for(int i=0;i<DIGITS-1;i++) //�i��check 
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
	for(int i=0;i<DIGITS-1;i++) //��k 
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
	//�B�z�t�� 
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
	for(int i=0;i<DIGITS;i++) //�M��C�}�C 
		c[i]=0;
	
	for(int i=0;i<=DIGITS-1;i++) 
		for(int j=0;j<=DIGITS-1;j++)
			if(i+j<DIGITS-1)
				c[i+j]+=a[i]*b[j];
		
		
	for(int i=0;i<DIGITS-1;i++) //�i��check 
		{
			c[i+1]=c[i+1]+c[i]/10;
			c[i]=c[i]%10;
		}		


	
	
}



int main(){
	
	char oper, input1[DIGITS],input2[DIGITS];
	while(cin>>input1>>oper>>input2){
		int array1[DIGITS]; //�]�O�n��Input1���}�C�j�p
		int array2[DIGITS]; //�]�O�n��Input2���}�C�j�p
		int array3[DIGITS]; //�]�w�n���ƹB��᪺�}�C�j�p 
	
		//��String�@��@���J�ܰ}�C 
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
		//��X�}�C 
		print(array3);
		cout<<endl;

}			

	
return 0;	
	
	
} 
