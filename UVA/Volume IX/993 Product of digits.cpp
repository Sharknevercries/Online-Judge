/* 993 Product of digits Accepted C++ 0.012 2011-02-25 12:46:31 */
#include<stdio.h>
#define SWAP(x,y) { char c=x; x=y; y=c; }
int main(){
	int s;
	while(scanf("%d",&s)==1)
		while(s--){
			char result[100000];
			int i,j,n,index;
			bool NOT=false;
			scanf("%d",&n);
			index=0;
			if(n==1)
				result[index++]='1';
			while(n!=1&&!NOT){
				for(i=9;i>1&&n%i!=0;i--); // 求得最少位數
				if(i<=1)
					NOT=true;
				else{
					result[index++]=i+'0';
					n/=i;}
			}			
			if(NOT)
				puts("-1");
			else{
				result[index]='\0';
				for(i=0;i<index;i++) // 氣泡排序
					for(j=i+1;j<index;j++)
						if(result[i]>result[j])
							SWAP(result[i],result[j]);
				printf("%s\n",result);
			}
		}
	return 0;
}
/*

For a given non-negative integer number N , find the minimal natural Q such that the product of all digits of Q is equal N . 

Input  

The first line of input contains one positive integer number, which is the number of data sets. Each subsequent line contains one data set which consists of one non-negative integer number N (0N109) . 

Output  

For each data set, write one line containing the corresponding natural number Q or `-1' if Q does not exist. 

Sample Input  

3 
1 
10 
123456789

Sample Output  

1 
25 
-1

*/