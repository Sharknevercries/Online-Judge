/* 4571529	 Sep 27, 2013 10:52:37 AM	Shark	 344B - Simple Molecules	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
int main(){
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)==3){
		if( (a+b-c)%2==0&&(a+c-b)%2==0&&(b+c-a)%2==0 ){
			int x,y,z;
			x=(a+b-c)/2;
			y=(b+c-a)/2;
			z=(a+c-b)/2;
			if( ((x==0&&y==0)||(x==0&&z==0)||(y==0&&z==0))||x<0||y<0||z<0 )
				puts("Impossible");
			else
				printf("%d %d %d\n",x,y,z);
		}
		else
			puts("Impossible");
	}
	return 0;
}
/*

B. Simple Molecules
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Mad scientist Mike is busy carrying out experiments in chemistry. Today he will attempt to join three atoms into one molecule.

A molecule consists of atoms, with some pairs of atoms connected by atomic bonds. Each atom has a valence number — the number of bonds the atom must form with other atoms. An atom can form one or multiple bonds with any other atom, but it cannot form a bond with itself. The number of bonds of an atom in the molecule must be equal to its valence number.


Mike knows valence numbers of the three atoms. Find a molecule that can be built from these atoms according to the stated rules, or determine that it is impossible.

Input
The single line of the input contains three space-separated integers a, b and c (1 ≤ a, b, c ≤ 106) — the valence numbers of the given atoms.

Output
If such a molecule can be built, print three space-separated integers — the number of bonds between the 1-st and the 2-nd, the 2-nd and the 3-rd, the 3-rd and the 1-st atoms, correspondingly. If there are multiple solutions, output any of them. If there is no solution, print "Impossible" (without the quotes).

Sample test(s)
input
1 1 2
output
0 1 1
input
3 4 5
output
1 3 2
input
4 1 1
output
Impossible
Note
The first sample corresponds to the first figure. There are no bonds between atoms 1 and 2 in this case.

The second sample corresponds to the second figure. There is one or more bonds between each pair of atoms.

The third sample corresponds to the third figure. There is no solution, because an atom cannot form bonds with itself.

The configuration in the fourth figure is impossible as each atom must have at least one atomic bond.

*/