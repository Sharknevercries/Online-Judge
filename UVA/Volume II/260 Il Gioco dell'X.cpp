/* 9366890 260 Il Gioco dell'X Accepted C++ 0.012 2011-10-13 15:18:48 */
#include<stdio.h>
#include<string.h>
char table[201][201];
bool visited[201][201];
int n;
int DFS(int row,int cul){
	if(row==n-1)
		return true;
	else{		
		if(!visited[row+1][cul]&&table[row+1][cul]=='b'){
			visited[row+1][cul]=true;
			if(DFS(row+1,cul))
				return true;
		}
		if(cul+1<n&&!visited[row+1][cul+1]&&table[row+1][cul+1]=='b'){
			visited[row+1][cul+1]=true;
			if(DFS(row+1,cul+1))
				return true;
		}
		if(cul-1>=0&&!visited[row][cul-1]&&table[row][cul-1]=='b'){
			visited[row][cul-1]=true;
			if(DFS(row,cul-1))
				return true;
		}
		if(cul+1<n&&!visited[row][cul+1]&&table[row][cul+1]=='b'){
			visited[row][cul+1]=true;
			if(DFS(row,cul+1))
				return true;
		}
		return false;
	}
}
int main(){
	int t=1;
	while(scanf("%d",&n)==1){
		if(n==0)
			break;
		(void)getchar();

		for(int i=0;i<n;i++)
			gets(table[i]);

		memset(visited,false,sizeof(visited));
		bool BLACK_WIN=false;
		bool s=false;

		for(int i=0;i<n;i++)
			if(table[0][i]=='b'&&!s){
				visited[0][i]=true;
				if(DFS(0,i)){
					BLACK_WIN=true;
					break;
				}
				s=true;
			}
			else
				s=false;

		if(BLACK_WIN)
			printf("%d B\n",t++);
		else
			printf("%d W\n",t++);
	}
	return 0;
}
/*

The game `Il Gioco dell' X' is played on a N by N board ( ). The object of both players, say Black and White, is to join opposite sides of the board by placing in turn their pawns on the board in such a way that a path is made from one side to the other by adjacent (neighboring) pawns of their own color. Although the board is it is not a square but rather diamond-shaped. Let us denote the field on the board in row i and column j by . The neighbors of (i, j) are:
 

                       ( i-1 , j-1 ) , ( i-1 ,  j  ) 
                       (  i  , j-1 ) , (  i  , j+1 ) 
                       ( i+1 ,  j  ) , ( i+l , j+1 ) 
provided these fields do not fall outside the board. 

Black tries to join row 1 with row N, while White tries to join column 1 with column N.
 
lt is a Deep Mathematical Result that this game cannot end in a draw (that is, without winner). As we will present to you only full boards, there will always be a winner. It may, however, be difficult to see who has won, so some computer assistance would be appreciated.
 
Examples:
 
Example 1 Example 2 

In example 1 White has won, and in example 2 Black has won. 

Input
 
The input is a textfile containing a number of games. Each game is given by: one line containing an integer N, being the number of rows. (N can he any number between 2 and 200). This line is followed by N lines, each consisting of a row of N characters from the set {`b',`w'} denoting the pawns of Black and White respectively. The numbers of black and white pawns will differ by at most one. Note that all positions on the board are filled with pawns. The list of games ends with a single zero on a line of its own. (Of course, this is not a game for which a winner has to be determined.)
 
Output
 
The output will be a textfile containing one line for each game. This line should contain the number of the game (starting at 1) followed by a space, and followed by an uppercase `B' if Black did win, or followed by an uppercase `W' if White did win.
 
Sample Input
 
4
bbwb
wwbw
bbwb
bwww
4
bbwb
wwbw
bwwb
wwbb
0 

Sample Output
 
1 W
2 B 

*/