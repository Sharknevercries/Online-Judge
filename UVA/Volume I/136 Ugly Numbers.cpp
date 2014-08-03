/* 9050458 136 Ugly Numbers Accepted C++ 0.020 2011-07-15 07:41:13 */
#include<stdio.h>
#include<string.h>
#define SWAP(x,y) { long long int temp=x; x=y; y=temp; }
static long long int m[3000];
// 二分插入法
void Bin(long long int temp,int left,int right,int *n){
	bool repeat=false;
	int mid,pos;
	pos=-1;
	if(temp>m[right])
		pos=*n;
	else if(temp<m[left])
		pos=0;
	else{
		while(right-left>1){
			mid=(left+right)/2;
			if(m[mid]>temp)
				right=mid;
			else if(m[mid]<temp)
				left=mid;
			else{
				repeat=true;
				break;
			}
		}
		pos=left+1;
	}
	if(!repeat){
		memmove(&m[pos+1],&m[pos],sizeof(long long int)*((*n)-pos));
		m[pos]=temp;
		(*n)++;
	}
}
int main(){
	long long int temp;
	int index=1;
	int left;
	m[0]=1;
	for(left=0;index<3000;left++){
		temp=m[left]*2;
		Bin(temp,0,index-1,&index);
		temp=m[left]*3;
		Bin(temp,0,index-1,&index);
		temp=m[left]*5;
		Bin(temp,0,index-1,&index);
	}	
	printf("The 1500'th ugly number is %lld.\n",m[1499]);
	return 0;
}
/*

Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 

1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, ... 

shows the first 11 ugly numbers. By convention, 1 is included. 

Write a program to find and print the 1500'th ugly number. 

Input and Output
 
There is no input to this program. Output should consist of a single line as shown below, with <number> replaced by the number computed.

Sample output
 
The 1500'th ugly number is <number>. 

*/