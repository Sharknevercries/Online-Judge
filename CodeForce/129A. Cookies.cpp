/* 1216241	 Feb 22, 2012 6:49:07 PM	Shark	 129A - Cookies	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		int M[101]={0},sum=0;
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			M[a]++;
			sum+=a;
		}
		int count=0;
		for(int i=1;i<=100;i++)
			if(((sum&1)==0&&(i&1)==0)||((sum&1)==1&&(i&1)==1))
				count+=M[i];
		printf("%d\n",count);
	}
	return 0;
}
/*

Olga came to visit the twins Anna and Maria and saw that they have many cookies. The cookies are distributed into bags. As there are many cookies, Olga decided that it's no big deal if she steals a bag. However, she doesn't want the sisters to quarrel because of nothing when they divide the cookies. That's why Olga wants to steal a bag with cookies so that the number of cookies in the remaining bags was even, that is, so that Anna and Maria could evenly divide it into two (even 0 remaining cookies will do, just as any other even number). How many ways there are to steal exactly one cookie bag so that the total number of cookies in the remaining bags was even?

Input

The first line contains the only integer n (1 ≤ n ≤ 100) — the number of cookie bags Anna and Maria have. The second line contains n integers ai (1 ≤ ai ≤ 100) — the number of cookies in the i-th bag.

Output

Print in the only line the only number — the sought number of ways. If there are no such ways print 0.

input

1
1
10
1 2 2 3 4 4 4 2 2 2
11
2 2 2 2 2 2 2 2 2 2 99

output

1
8
1

Note

In the first sample Olga should take the only bag so that the twins ended up with the even number of cookies.

In the second sample Olga can take any of five bags with two cookies or any of three bags with four cookies — 5 + 3 = 8 ways in total.

In the third sample, no matter which bag with two cookies Olga chooses, the twins are left with 2 * 9 + 99 = 117 cookies. Thus, Olga has only one option: to take the bag with 99 cookies.

*/