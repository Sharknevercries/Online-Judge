/* 9075181 11313 Gourmet Games Accepted C++ 0.012 2011-07-24 08:38:11 */
#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		int n,m,count;
		bool NOT=false;
		scanf("%d%d",&n,&m);
		count=0;
		while(true){
			if((int)n/m==0){
				NOT=true;
				break;
			}
			count+=n/m;
			n=n/m+n%m;
			if(n==1)
				break;
		}
		if(NOT)
			puts("cannot do this");
		else
			printf("%d\n",count);
	}
	return 0;
}
/*

Wolfgang Puck is opening a new exclusive restaurant in Las Vegas and is looking for a chef. His nephew Hansel caught him thinking of posting an ad in newspapers. (Note: Wolfgang has heard of "this Internet thingy", but didn't find it interesting because one could not spread some Internet on a piece of bread, which is the mere minimum that has to be satisfied for something to be interesting, according to Mr. Puck.)

Hansel knows what the advantages of the Internet job postings are, but he came up with an even better idea - given the success of various reality TV shows and given the fact that the restaurant is opening in Las Vegas, why not organize a sort of a cook-off tournament that will decide who Mr. Puck will hire?

The idea basically combines the Iron Chef™ show with the World Series Of Poker™: Every show m cooks prepare a five-course meal for judges and the best one (according to the said judges) advances to the next round. All candidates are ranked based on the previous experience so, even if the number of the candidates is not divisible by m, some of them can get a "bye" and compete in later rounds. The winner of the final show gets the honour of being the chef in the best Wolfgang Puck's restaurant ever.

Hansel realized that even with the byes it might not be possible to hold a tournament with m chefs per show, so he is trying to find out what the best m for the given number of candidates is. If you can just help him by letting him know if he can run a tournament as described with n candidates and m chefs per show and, in the case he can, how many shows he needs, he will be so grateful that he might even convince Mr. Puck to share the Secret Cheesecake Base Recipe with you.

Input
 
Input file starts with the line containing a single integer t, the number of test cases. Next t lines each contain two integers separated by spaces, n and m (2 ≤ n ≤ 10000, 2 ≤ m ≤ n), where n is the total number of candidates and m is the number of chefs participating in a single TV show.

Output
 
For each test case print the number of shows that need to be run to get the new chef. In the case that the tournament cannot be run with given n and m, print "cannot do this".

Sample Input

3
3 2
4 3
4 4

 Output for the Sample Input

2
cannot do this
1

--------------------------------------------------------------------------------
 Darko Aleksic
 Calgary Collegiate Programming Contest 2007

 */