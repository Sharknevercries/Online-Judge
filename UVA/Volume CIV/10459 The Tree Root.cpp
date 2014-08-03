/* 9784646	10459	The Tree Root	Accepted	C++	0.124	2012-02-26 16:17:02 */
#include<stdio.h>
#include<vector>
std::vector<int> T[5001];
int h1[5001],h2[5001];
int s1[5001],s2[5001];
int p[5001];
int n;
void record(int s,int heigh,int t){
	if(heigh>h1[s]){
		h2[s]=h1[s],s2[s]=s1[s];
		h1[s]=heigh,s1[s]=t;
	}
	else if(heigh>h2[s])
		h2[s]=heigh,s2[s]=t;
}
void DFS1(int s){
	h1[s]=h2[s]=0;
	for(int t=0;t<T[s].size();t++)
		if(T[s][t]!=p[s]){
			p[T[s][t]]=s;
			DFS1(T[s][t]);
			record(s,h1[T[s][t]]+1,T[s][t]);
		}
}
void DFS2(int s){
	if(p[s]!=s){
		int t=p[s];
		if(s1[t]==s)
			record(s,h2[t]+1,t);
		else
			record(s,h1[t]+1,t);
	}
	for(int t=0;t<T[s].size();t++)
		if(T[s][t]!=p[s])
			DFS2(T[s][t]);
}
int main(){	
	while(scanf("%d",&n)==1){
		for(int i=1;i<=n;i++){
			int k;
			scanf("%d",&k);
			T[i].clear();
			for(int j=0;j<k;j++){
				int a;
				scanf("%d",&a);
				T[i].push_back(a);
			}
		}
		p[1]=1;
		DFS1(1);
		DFS2(1);
		int min=2e9,max=0;
		for(int i=1;i<=n;i++){
			if(h1[i]>max)	max=h1[i];
			if(min>h1[i])	min=h1[i];
		}
		printf("Best Roots  :");
		for(int i=1;i<=n;i++)
			if(min==h1[i])
				printf(" %d",i);
		putchar('\n');
		printf("Worst Roots :");
		for(int i=1;i<=n;i++)
			if(max==h1[i])
				printf(" %d",i);
		putchar('\n');
	}
	return 0;
}
/*

Tree is an important data structure. Searching is a basic operation in any data structure. In a tree searching mainly depends on its height. Consider the following three trees.

If you observe carefully, you will see that all trees are same except different nodes are used as roots. Here the height of the tree varies with the selection of the root. In the 1st tree root is '2' and height is 3. In 2nd one root is '1' and height is 2. And in last one root is '4' and height is 4. We will call '1' best root as it keeps the tree with the least possible height and '4' worst root for the opposite reason.
In this problem, you have to find out all best roots and worst roots for a given tree.
 
Input

Each dataset starts with a positive integer N(3<=N<=5000), which is the number of nodes in the tree. Each node in the tree has a unique id from 1 to N. Then successively for each i'th node there will be a positive integer K[i] following id of K[i] nodes which are adjacent to i. Input is terminated by EOF.

Output

For each dataset print two lines. In the 1st line show all the best roots in ascending order and in next line show all worst roots in ascending order. See sample output for exact format.
 
Sample Input

7
2 2 3
3 1 6 7
3 1 4 5
1 3
1 3
1 2
1 2

Sample Output
 
Best Roots  : 1
Worst Roots : 4 5 6 7

*/