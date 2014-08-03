/* 9050682 138 Street Numbers Accepted C++ 0.008 2011-07-15 09:15:18 */
#include<stdio.h>
int main(){
	/*
	int count=0;
	unsigned long long n,k;
	int left,right;
	for(n=3;count<10;n++){
		left=1,right=n;
		while(right-left>1){
			k=(left+right)/2;
			unsigned long long t1=2*k*k;
			unsigned long long t2=n*(n+1);
			if(t1<t2)
				left=k;
			else if(t1>t2)
				right=k;
			else if(t1==t2){
				printf("%10llu%10llu\n",k,n);
				count++;
				break;
			}
		}
	}
	*/
	unsigned long long result_k[]={6,35,204,1189,6930,40391,235416,1372105,7997214,46611179};
	unsigned long long result_n[]={8,49,288,1681,9800,57121,332928,1940449,11309768,65918161};
	for(int i=0;i<10;i++)
		printf("%10llu%10llu\n",result_k[i],result_n[i]);
	return 0;
}
/*

 Street Numbers 
  
A computer programmer lives in a street with houses numbered consecutively (from 1) down one side of the street. Every evening she walks her dog by leaving her house and randomly turning left or right and walking to the end of the street and back. One night she adds up the street numbers of the houses she passes (excluding her own). The next time she walks the other way she repeats this and finds, to her astonishment, that the two sums are the same. Although this is determined in part by her house number and in part by the number of houses in the street, she nevertheless feels that this is a desirable property for her house to have and decides that all her subsequent houses should exhibit it.
 
Write a program to find pairs of numbers that satisfy this condition. To start your list the first two pairs are: (house number, last number):
 
         6         8
        35        49 
		
Input and Output
 
There is no input for this program. Output will consist of 10 lines each containing a pair of numbers, each printed right justified in a field of width 10 (as shown above).
 
*/