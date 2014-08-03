/* 8892332 10625 GNU = GNU'sNotUnix Accepted C++ 0.136 2011-05-27 10:42:45 */
#include<stdio.h>
int main(){
	int t,n;
	scanf("%d",&n);
	for(t=1;t<=n;t++){		
		int s[10][257]={0};
		char c[10];
		char str[101];
		char find;
		int i,j,k,p,index;
		int r,x;
		scanf("%d",&r);
		(void) getchar();
		for(i=1,index=0;i<=r;i++){
			gets(str);
			c[index]=str[0];
			for(j=3;str[j]!='\0';j++)
				s[index][(int)str[j]]++;
			index++;
		}
		scanf("%d",&r);
		(void) getchar();
		for(i=1;i<=r;i++){
			unsigned long long chart[257]={0};
			scanf("%s %c%d",str,&find,&x);
			for(j=0;str[j]!='\0';j++)
				chart[(int)str[j]]++;
			for(j=1;j<=x;j++){
				unsigned long long temp[257];
				for(k=0;k<257;k++){ // 複製資料
					for(p=0;p<index;p++)
						if((int)c[p]==k){
							temp[k]=0;
							break;
						}
					if(p>=index)
						temp[k]=chart[k];
				}
				for(k=0;k<index;k++)
					if(chart[(int)c[k]]){
						for(p=0;p<257;p++)
							temp[p]+=chart[(int)c[k]]*s[k][p];	
					}
				for(k=0;k<257;k++) // 複製資料
					chart[k]=temp[k];
			}
			printf("%llu\n",chart[(int)find]);
		}
	}
	return 0;
}
/*

Let us define GNU, the recursive acronym for GNU's Not Unix with the following recursive rules:
1. G -> GNU's 
2. N -> Not 
3. U -> Unix 
In each step we apply all the rules simultaneously. If a character in a string does not have a rule associated with it (there will be at most one rule per character), it remains in the string. 

For example if we start with GNU, we get: 

Step String

0 GNU

1 GNU'sNotUnix

2 GNU'sNotUnix'sNototUnixnix

3 GNU'sNotUnix'sNototUnixnix'sNotototUnixnixnix

4 GNU'sNotUnix'sNototUnixnix'sNotototUnixnixnix'sNototototUnixnixnixnix

...
...
 
As you can see, the strings are growing larger in every steps. And in certain cases the growth can be quite fast. Fear not, for we're not interested in the entire string. We just want to know the frequency of a particular character after a finite number of steps. 

Input

The first line of the input starts with an integer, T(1<=T<=10), the number of test cases. Then T test cases will follow. The first line of each test case will give you R, (1<=R<=10) the number of rules. In each of the next R lines there will be one rule. The rules are written in the following format: "x->S" (without the quotes). Here x is a single character and S is a sequence of characters. You can assume that the ASCII value of the characters lie in the range 33 to 126, that S will contain no more than 100 characters. You can also assume that the symbols '-' and '>' won't appear in S. The rules can be immediately recursive, recursive in a cycle or not recursive at all. After the rules, you'll find an integer Q (1<=Q<=10), the number of queries to follow.. Each of the Q queries will be presented in the format "initial_string x n" in a single line, where initial_string is the string that you have in step 0 (with length between 1 and 100), x is the character whose frequency you should count, and n (1<=n<=10000) is the number of times the rules should be applied. All characters in the initial string will have ASCII values in the range 33 to 126.
 
Output

For each query, print the number of occurances of the particular character in the result string after applying the rules n times, starting with the initial string. The output will always fit in a 64-bit unsigned integer.
 
Sample Input

2
3
G->GNU's
N->Not
U->Unix
2
GNU t 3
GNU N 3
1
A->BAcX
1
ABCcXA c 10000

Sample Output

6
4
20001
 
--------------------------------------------------------------------------------
Problem setter: Monirul Hasan, Member of Elite Problemsetters' Panel
Special thanks to: Jimmy Mårdell (Alternate Solution) 

*/