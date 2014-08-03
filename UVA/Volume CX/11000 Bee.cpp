/* 9075240 11000 Bee Accepted C++ 0.012 2011-07-24 09:01:30 */
#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1&&n!=-1){
		long long int mother,father,total;
		long long int tm,tf;
		int year;
		mother=father=0;
		total=1;
		for(year=1;year<=n;year++){
			tm=tf=0;

			tm=father;
			tf=father+mother+1;

			total+=father+1;

			father=tf;
			mother=tm;
		}
		printf("%lld %lld\n",father,total);
	}
	return 0;
}
/*

In Africa there is a very special species of bee. Every year, the female bees of such species give birth to one male bee, while the male bees give birth to one male bee and one female bee, and then they die!
 
Now scientists have accidentally found one "magical female bee" of such special species to the effect that she is immortal, but still able to give birth once a year as all the other female bees. The scientists would like to know how many bees there will be after N years. Please write a program that helps them find the number of male bees and the total number of all bees after N years.
 
The Input
 
Each line of input contains an integer N (≥ 0). Input ends with a case where N = -1. (This case should NOT be processed.)
 
The Output
 
Each line of output should have two numbers, the first one being the number of male bees after N years, and the second one being the total number of bees after N years. (The two numbers will not exceed 232.)
 
Sample Input
 
1
3
-1

Sample Output
 
1 2
4 7
 
--------------------------------------------------------------------------------

*/