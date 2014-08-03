/* 9195557 10344 23 out of 5 Accepted C++ 1.012 2011-08-27 13:39:03 */
#include<stdio.h>
int m[5];
bool used[5];
int DFS(int k,int sum){
	if(k==5)
		if(sum==23)
			return true;
		else
			return false;
	for(int i=0;i<5;i++)
		if(!used[i]){
			used[i]=true;
			if(DFS(k+1,sum+m[i]))
				return true;
			if(DFS(k+1,sum-m[i]))
				return true;
			if(DFS(k+1,sum*m[i]))
				return true;
			used[i]=false;
		}
	return false;
}
int main(){
	while(scanf("%d",&m[0])==1){
		bool YES;
		int i;
		for(i=1;i<5;i++)
			scanf("%d",&m[i]);
		for(i=0;i<5&&m[i]==0;i++);
		if(i>=5)
			break;
		for(i=0;i<5;i++)
			used[i]=false;


		YES=false;
		for(i=0;i<5;i++){
			used[i]=true;
			if(DFS(1,m[i])){
				puts("Possible");
				YES=true;
				break;
			}
			used[i]=false;
		}
		if(!YES)
			puts("Impossible");
	}
	return 0;
}
/*

Your task is to write a program that can decide whether you can find an arithmetic expression consisting of five given numbers (1<=i<=5) that will yield the value 23.
 For this problem we will only consider arithmetic expressions of the following from: 
 where : {1,2,3,4,5} -> {1,2,3,4,5} is a bijective functionand  {+,-,*} (1<=i<=4)

 Input

The Input consists of 5-Tupels of positive Integers, each between 1 and 50.
 
 Input is terminated by a line containing five zero's. This line should not be processed.

Output

For each 5-Tupel print "Possible" (without quotes) if their exists an arithmetic expression (as described above) that yields 23. Otherwise print "Impossible". 

Sample Input

1 1 1 1 1
1 2 3 4 5
2 3 5 7 11
0 0 0 0 0

Sample Output

Impossible
Possible
Possible

--------------------------------------------------------------------------------

Thomas Strohmann

*/