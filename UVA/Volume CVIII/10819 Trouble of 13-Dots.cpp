/* 12416855	10819	Trouble of 13-Dots	Accepted	C++	0.129	2013-09-29 04:54:15 */
#include<stdio.h>
#include<string.h>
#define MAX(x,y) ( (x) >= (y) ? (x) : (y) )
#define FIX 200
#define MAXN 100
#define MAXM 10000
int DP[MAXN+1][MAXM+FIX+1];
int main(){
	int M,N;
	while( scanf("%d%d",&M,&N)==2 ){
		int P[MAXM+1];
		int V[MAXM+1];
		int sum=0;
		for(int i=1;i<=N;i++){
			scanf("%d%d",&P[i],&V[i]);
			sum+=P[i];
		}

		for(int i=0;i<=N;i++)
			for(int j=0;j<=M+FIX;j++)
				DP[i][j]=-2e9;
		DP[0][0]=0;
		int limit = (M+FIX>=sum) ? sum : M+FIX;
		for(int i=1;i<=N;i++)
			for(int j=0;j<=limit;j++){
				if( j-P[i]>=0 )
					DP[i][j]=MAX(DP[i-1][j],DP[i-1][j-P[i]]+V[i]);
				else
					DP[i][j]=DP[i-1][j];
			}
		int max=-1;
		for(int i=0;i<=M;i++)	if( DP[N][i]>max )	max=DP[N][i];
		for(int i=2001;i<=M+FIX;i++)	if( DP[N][i]>max )	max=DP[N][i];
		printf("%d\n",max);
	}
	return 0;
}
/*


Problem F: Trouble of 13-Dots

Time limit: 2 seconds

Do you know 13-Dots? She is the main character of a well-known Hong Kong comic series. She is famous of her beauty, as well as the variety of stylish clothes she wears. Here are some pictures of 13-Dots that I found on the Web:

  

Now 13-Dots is facing a problem. She used to have a large amount of pocket money every month. However, her father has decided to cut down her budget of buying new clothes! In the past, she would buy every dress she liked without hesitation, but now she needs careful consideration before making any purchase. Every month, she prepares a list containing the prices and 'favour indices' (ranging from 1 to 5) of all items she is interested. At the end of the month, she would decide how to spend her money such that the total favour value is maximized. It is important to know that 13-Dots always uses her credit card to pay the bill, which offers her a 200-dollar refund if her total expense in the month exceeds $2000. For example, if her budget is $5000, she can buy clothes with total marked price of at most 5200 dollars.

Since the optimal way is hard to be figured out just by hand, can you write a program for 13-Dots that helps her make the decision? Remember that you should NEVER select an item more than once, even if this leads to a greater total favour value.

Input

The input consists of several test cases. Each of them has the following format:

The first line gives two integers, m and n (0 ≤ m ≤ 10000, 0 ≤ n ≤ 100), which are the amount of pocket money 13-Dots has and the number of items on the list respectively. The following n lines each contains two integers, p and f (0 < p ≤ 4000, 1 ≤ f ≤ 5), where p is the marked price of the item, and f is its 'favour index'.

Input is terminated by EOF.

Output

For each test case, print one line giving the maximum total favour value 13-Dots can get.

Sample Input

500 4
100 2
100 3
200 3
400 4
Sample Output

8
Question 4 in OIPC, Nov. 2003
Image sources include: http://www.hkcomics.com, http://www.yesasia.com, http://isubculture.ichannel.com.hk

*/