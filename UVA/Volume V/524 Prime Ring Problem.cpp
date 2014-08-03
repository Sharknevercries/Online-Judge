/* 9117304 524 Prime Ring Problem Accepted C++ 0.352 2011-08-05 13:58:20 */
#include<stdio.h>
#include<math.h>
int check(int n){
	int i;
	for(i=2;i<=sqrt((double)n);i++)
		if(n%i==0)
			return false;
	return true;
}
void print(int m[],int n){
	printf("%d",m[0]);
	for(int i=1;i<n;i++)
		printf(" %d",m[i]);
	putchar('\n');
}
void DFS(int m[],bool used [],int n,int index,bool is_odd){	
	if(index==n){
		if(check(m[n-1]+m[0]))
			print(m,n);
	}
	else{
		for(int i=1;i<n;i++)
			if(!used[i]&&is_odd&&((i+1)&1)==0){
				used[i]=true;
				m[index]=i+1;
				if(check(m[index]+m[index-1]))
					DFS(m,used,n,index+1,false);
				used[i]=false;
			}
			else if(!used[i]&&!is_odd&&((i+1)&1)==1){
				used[i]=true;
				m[index]=i+1;
				if(check(m[index]+m[index-1]))
					DFS(m,used,n,index+1,true);
				used[i]=false;
			}
	}
}
int main(){
	bool first=true;
	int count=1;
	int n;
	while(scanf("%d",&n)==1){
		if(!first)
			putchar('\n');
		first=false;
		int m[16];
		bool used[16]={false};
		m[0]=1;
		printf("Case %d:\n",count++); 
		DFS(m,used,n,1,true);
	}
	return 0;
}
/*

A ring is composed of n (even number) circles as shown in diagram. Put natural numbers into each circle separately, and the sum of numbers in two adjacent circles should be a prime.
 
Note: the number of first circle should always be 1. 

Input  

n (0 < n <= 16)

 Output 

The output format is shown as sample below. Each row represents a series of circle numbers in the ring beginning from 1 clockwisely and anticlockwisely. The order of numbers must satisfy the above requirements.
 
You are to write a program that completes above process. 

Sample Input  

6
8

 Sample Output 

Case 1:
1 4 3 2 5 6
1 6 5 2 3 4

Case 2:
1 2 3 8 5 6 7 4
1 2 5 8 3 4 7 6
1 4 7 6 5 8 3 2
1 6 7 4 3 8 5 2

--------------------------------------------------------------------------------

Miguel A. Revilla 
1999-01-11 

*/