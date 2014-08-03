/* 4679664	 Oct 5, 2013 2:17:10 PM	Shark	 106B - Choosing Laptop	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		int S[100][4]; // speed,ram,hdd,cost
		bool outdata[100]={false};
		for(int i=0;i<n;i++)
			scanf("%d%d%d%d",&S[i][0],&S[i][1],&S[i][2],&S[i][3]);
		for(int i=0;i<n;i++)
			if( !outdata[i] )
				for(int j=0;j<n;j++)
					if( !outdata[j]&&S[i][0]>S[j][0]&&S[i][1]>S[j][1]&&S[i][2]>S[j][2] )
						outdata[j]=true;
		int min=2e9,ptr=-1;
		for(int i=0;i<n;i++)
			if( !outdata[i]&&min>S[i][3] )
				min=S[i][3],ptr=i;
		printf("%d\n",ptr+1);
	}
	return 0;
}
/*

B. Choosing Laptop
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasya is choosing a laptop. The shop has n laptops to all tastes.

Vasya is interested in the following properties: processor speed, ram and hdd. Vasya is a programmer and not a gamer which is why he is not interested in all other properties.

If all three properties of a laptop are strictly less than those properties of some other laptop, then the first laptop is considered outdated by Vasya. Among all laptops Vasya does not consider outdated, he chooses the cheapest one.

There are very many laptops, which is why Vasya decided to write a program that chooses the suitable laptop. However, Vasya doesn't have his own laptop yet and he asks you to help him.

Input
The first line contains number n (1 ≤ n ≤ 100).

Then follow n lines. Each describes a laptop as speed ram hdd cost. Besides,

speed, ram, hdd and cost are integers
1000 ≤ speed ≤ 4200 is the processor's speed in megahertz
256 ≤ ram ≤ 4096 the RAM volume in megabytes
1 ≤ hdd ≤ 500 is the HDD in gigabytes
100 ≤ cost ≤ 1000 is price in tugriks
All laptops have different prices.

Output
Print a single number — the number of a laptop Vasya will choose. The laptops are numbered with positive integers from 1 to n in the order in which they are given in the input data.

Sample test(s)
input
5
2100 512 150 200
2000 2048 240 350
2300 1024 200 320
2500 2048 80 300
2000 512 180 150
output
4
Note
In the third sample Vasya considers the first and fifth laptops outdated as all of their properties cannot match those of the third laptop. The fourth one is the cheapest among the laptops that are left. Thus, Vasya chooses the fourth laptop.

*/