/* 1240675	 Feb 28, 2012 10:44:18 AM	Shark	 116B - Little Pigs and Wolves	 GNU C++	Accepted	 30 ms	 1400 KB */
#include<stdio.h>
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		char table[100][101];
		bool used[100][100]={false};
		for(int i=0;i<n;i++)
			scanf("%s",table[i]);

		int count=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(table[i][j]=='P'){
					if(i-1>=0&&!used[i-1][j]&&table[i-1][j]=='W')
						count++,used[i-1][j]=true;
					else if(j-1>=0&&!used[i][j-1]&&table[i][j-1]=='W')
						count++,used[i][j-1]=true;
					else if(j+1<m&&!used[i][j+1]&&table[i][j+1]=='W')
						count++,used[i][j+1]=true;
					else if(i+1<n&&!used[i+1][j]&&table[i+1][j]=='W')
						count++,used[i+1][j]=true;
				}
		printf("%d\n",count);

	}
	return 0;
}
/*

Once upon a time there were several little pigs and several wolves on a two-dimensional grid of size n × m. Each cell in this grid was either empty, containing one little pig, or containing one wolf.

A little pig and a wolf are adjacent if the cells that they are located at share a side. The little pigs are afraid of wolves, so there will be at most one wolf adjacent to each little pig. But each wolf may be adjacent to any number of little pigs.

They have been living peacefully for several years. But today the wolves got hungry. One by one, each wolf will choose one of the little pigs adjacent to it (if any), and eats the poor little pig. This process is not repeated. That is, each wolf will get to eat at most one little pig. Once a little pig gets eaten, it disappears and cannot be eaten by any other wolf.

What is the maximum number of little pigs that may be eaten by the wolves?

Input

The first line contains integers n and m (1 ≤ n, m ≤ 10) which denotes the number of rows and columns in our two-dimensional grid, respectively. Then follow n lines containing m characters each — that is the grid description. "." means that this cell is empty. "P" means that this cell contains a little pig. "W" means that this cell contains a wolf.

It is guaranteed that there will be at most one wolf adjacent to any little pig.

Output

Print a single number — the maximal number of little pigs that may be eaten by the wolves.

input

2 3
PPW
W.P
3 3
P.W
.P.
W.P

output

2
0

Note

In the first example, one possible scenario in which two little pigs get eaten by the wolves is as follows.

*/