/* 9194896 11321 Sort! Sort!! and Sort!!! Accepted C++ 0.412 2011-08-27 09:28:09 */
#include<stdio.h>
#define ABS(x) ( (x) >=0 ? (x) : -(x) )
#define swap(x,y) {	int g=x; x=y; y=g;	}
#define EVEN 0
#define ODD 1
int t[10000];
int s[10000];
void SWAP(int next,int split){
	swap(t[next],t[split]);
	swap(s[next],s[split]);
}
void qsort(int left,int right){
	if(right>left){
		bool change;
		int split,next;
		split=left;
		for(next=split+1,change=false;next<=right;next++,change=false){
			if(s[left]>s[next])
				change=true;
			else if(s[left]==s[next]){
				if(ABS(t[left]%2)==0&&ABS(t[next]%2)==0&&t[left]>t[next])
					change=true;
				else if(ABS(t[left]%2)==1&&ABS(t[next]%2)==1&&t[left]<t[next])
					change=true;
				else if(ABS(t[next]%2)==1&&ABS(t[left]%2)==0) // 除錯除好久... 在這裡啊...槓!!!
					change=true;
			}
			if(change){
				split++;
				SWAP(next,split);
			}
		}
		SWAP(left,split);
		qsort(left,split-1);
		qsort(split+1,right);
	}
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		printf("%d %d\n",n,m);
		if(n==0&&m==0)	break;
		int i,j;
		for(i=0;i<n;i++)
			scanf("%d",&t[i]);
		for(i=0;i<n;i++)
			s[i]=t[i]%m;
		qsort(0,n-1);			
		for(i=0;i<n;i++)
			printf("%d\n",t[i]);
	}
}
/*

Hmm! Here you are asked to do a simple sorting. You will be given N numbers and a positive integer M. You will have to sort the N numbers in ascending order of their modulo M value. If there is a tie between an odd number and an even number (that is their modulo M value is the same) then the odd number will precede the even number. If there is a tie between two odd numbers (that is their modulo M value is the same) then the larger odd number will precede the smaller odd number and if there is a tie between two even numbers (that is their modulo M value is the same) then the smaller even number will precede the larger even number. For remainder value of negative numbers follow the rule of C programming language: A negative number can never have modulus greater than zero. E.g. -100 MOD 3 = -1, -100 MOD 4 = 0 etc. 

Input

 The input file contains 20 sets of inputs. Each set starts with two integers N (0<N<=10000) and M (0<M<=10000) which denotes how many numbers are within this set. Each of the next N lines contains one number each. These numbers should all fit in 32-bit signed integer. Input is terminated by a line containing two zeroes. 

Output

 For each set of input produce N+1 lines of outputs. The first line of each set contains the value of N and M. The next N lines contain N numbers, sorted according to the rules mentioned above. Print the last two zeroes of the input file in the output file also.

Sample Input                      

15 3
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
0 0  

Output for Sample Input

15 3
15
9
3
6
12
13
7
1
4
10
11
5
2
8
14
0 0

--------------------------------------------------------------------------------

Problem-setter: Shahriar Manzoor

Special Thanks: Syed Monowar Hossain

*/