/* 9110413 10637 Coprimes Accepted C++ 0.236 2011-08-03 12:05:23 */
#include<stdio.h>
int GCD(int a,int b){
	int r;
	do{
		r=a%b;
		a=b;
		b=r;
	}while(r!=0);
	return a;
}
bool check(int table[],int n){
	int i;
	for(i=0;i<n-1;i++)
		if(GCD(table[i],table[n-1])!=1)
			return false;
	return true;
}
void DFS(int table[],int index,int s,int m,int pre){
	int i;
	if(index>=m){
		printf("%d",table[0]);
		for(i=1;i<m;i++)
			printf(" %d",table[i]);
		putchar('\n');
	}	
	else if(s>0){
		if(index+1==m){
			if(s>=pre){
				table[index]=s;
				if(check(table,index+1))
					DFS(table,index+1,0,m,s);
			}
		}
		else{
			for(i=(pre==0)?1:pre;(m-(index+1))*i<s;i++){
				table[index]=i;
				if(check(table,index+1))
					DFS(table,index+1,s-i,m,i);
			}
		}
	}
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		for(int t=1;t<=n;t++){
			int table[30];
			int s,m;
			scanf("%d%d",&s,&m);
			printf("Case %d:\n",t);
			DFS(table,0,s,m,0);
		}
	}
	return 0;
}
/*

How many times must a man look up
 Before he can see the sky?
 Yes, 'n' how many ears must one man have
 Before he can hear people cry?
 Yes, 'n' how many deaths will it take till he knows
 That too many people have died?
 The answer, my friend, is blowin' in the wind,
 The answer is blowin' in the wind.

Another gloomy day has begun for Shahriar but as usual his CD player is singing a song of hope. He has a large piece of paper in front of him on which he is trying to partition a number into some co-prime numbers by hand in as many ways as possible and surely things are getting out of his control. He wants to write a program to do this but his limited programming ability is not helping his cause. He has already thought about asking Mr. Kisman to write a code for him but as he has already asked too many favors from him he is looking for help from another source. Can you help him? A group of numbers is co-prime when the GCD of any two of them is 1.  

Shahriar has decided to give a party to all those who will solve this problem so he definitely wants an efficient and intelligent solution so that number of people in the party is small and of course his budget is limited :).

Input  

The first line of the input file is an integer N (0<N<40), which indicates how many sets of inputs are there. Each of the next N lines contains one set of input. Each line contains two integers S (0<S<=100) and t (0<t<=30). So your job is to partition S into t co-prime numbers.

Output 

For each line of input you should give several lines of outputs. The description of output for each line of input is given in the paragraph below:

First line should be the serial of the output. Next lines should contain all possible partitions of S into t co-prime numbers. Each line should contain one possible partition. In a partition the printed numbers should be ordered in non-decreasing order and two consecutive numbers should be separated by a single space. The partitions should be printed in ascending order. Let say one partition is P1=a1, a2 …, an and another partition is P2=b1, b2, …, bn. ak and bk are not equal and for all value of i(0<i<k) ai=bi. Then partition P1>P2 iff ak>bk and P1<P2 iff ak<bk. There can be around 15000 lines in the output file in total.

Sample Input 

2
40 6
8 3 

Output for Sample Input

Case 1:
1 1 1 1 1 35
1 1 1 1 5 31
1 1 1 1 7 29
1 1 1 1 11 25
1 1 1 1 13 23
1 1 1 1 17 19
1 1 1 3 5 29
1 1 1 3 11 23
1 1 1 5 9 23
1 1 1 5 11 21
1 1 1 5 13 19
1 1 1 7 11 19
1 1 1 7 13 17
1 1 1 9 11 17
1 1 3 5 7 23
1 1 3 5 11 19
1 1 3 5 13 17
1 1 3 7 11 17
1 1 5 7 9 17
1 1 5 9 11 13
1 3 5 7 11 13
Case 2:
1 1 6
1 2 5
1 3 4

--------------------------------------------------------------------------------

Problemsetter: Shahriar Manzoor, Member of Elite Problemsetters' PanelSpecial Thanks: Jimmy Mårdell, Member of Elite Problemsetters' Panel (Alternate Soln)  
“I like to mess with things. I used to garden, but my traveling resulted in the demise of all but my peach trees. I can fix a car, but I won't fix yours. I like to write software, but I don't like to read yours. I can say "Please put down your pencils!" in several languages. After thirty years, I can still play a trumpet well enough to know that some practice would do wonders. I have no idiosyncrasies.”

- Bill Poucher
  
*/