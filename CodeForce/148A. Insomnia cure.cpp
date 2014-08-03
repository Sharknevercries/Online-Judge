/* 1204328	 Feb 19, 2012 7:29:35 PM	Shark	 148A - Insomnia cure	 GNU C++	Accepted	 30 ms	 1400 KB */
#include<stdio.h>
#include<string.h>
bool M[100001];
int main(){
	int S[4],n;
	while(scanf("%d%d%d%d%d",&S[0],&S[1],&S[2],&S[3],&n)==5){
		memset(M,false,sizeof(M));
		int count=0;
		for(int i=0;i<4;i++)
			for(int j=S[i];j<=n;j+=S[i]){
				if(!M[j])
					count++;
				M[j]=true;
			}
		printf("%d\n",count);
	}
	return 0;
}
/*

 «One dragon. Two dragon. Three dragon», — the princess was counting. She had trouble falling asleep, and she got bored of counting lambs when she was nine.

However, just counting dragons was boring as well, so she entertained herself at best she could. Tonight she imagined that all dragons were here to steal her, and she was fighting them off. Every k-th dragon got punched in the face with a frying pan. Every l-th dragon got his tail shut into the balcony door. Every m-th dragon got his paws trampled with sharp heels. Finally, she threatened every n-th dragon to call her mom, and he withdrew in panic.

How many imaginary dragons suffered moral or physical damage tonight, if the princess counted a total of d dragons?

Input

Input data contains integer numbers k, l, m, n and d, each number in a separate line (1 ≤ k, l, m, n ≤ 10, 1 ≤ d ≤ 105).

Output

Output the number of damaged dragons.

input

1
2
3
4
12
2
3
4
5
24

output

12
17

Note

In the first case every first dragon got punched with a frying pan. Some of the dragons suffered from other reasons as well, but the pan alone would be enough.

In the second case dragons 1, 7, 11, 13, 17, 19 and 23 escaped unharmed.

*/