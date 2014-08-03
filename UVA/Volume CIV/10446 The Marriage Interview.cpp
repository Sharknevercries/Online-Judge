/* 9347851 10446 The Marriage Interview :-) Accepted C++ 0.008 2011-10-08 14:49:13 */
#include<stdio.h>
int main(){
	unsigned long long DP[100][100];
	int i,j,k;
	for(i=0;i<=61;i++)
		DP[0][i]=DP[1][i]=1;
	for(i=2;i<=61;i++){
		DP[i][0]=1;
		for(j=1;j<=60;j++){
			unsigned long long sum=0;
			for(k=1;k<=j;k++)
				sum+= i-k<=0 ? 1 : DP[i-k][j];
			DP[i][j]=sum+1;
		}	
	}

	int n,m,t;
	t=1;
	while(scanf("%d%d",&n,&m)==2){
		if(n>60)
			break;
		else if(m<=0||n<=0) // ³±ÀIªº´ú¸ê
			printf("Case %d: 1\n",t++,DP[n][m]);
		else
			printf("Case %d: %llu\n",t++,DP[n][m]);
	}
	return 0;	
}
/*

Tanbir has recently got married with Nupa. But the steps prior to this event were not easy. He had to submit a novel like curriculum vitae and also he had to face a long interview. A senior computer engineer from the bride¡¦s family took the interview. Just before the interview Tanbir solved a lot of problems from Valladolid Site and many packing problems of Erich Friedman and did well on most parts of the interview. But he had a tough time solving a different type of problem. It may be mentioned that Tanbir loved (!) to solve Geometric (Problem-setter of Problem H of this contest) and Parsing Problems. After the interview Tanbir went to one of his problem-setter friends to discuss about the problem. Tanbir and his so-called veteran problem-setter friend solved that problem correctly (hopefully) in seven days and thirteen nights (!). Now here is that problem for you (Who knows you may have to face a similar interview on a similar occasion in near future!!! Very few of you may arrange such an interview).

You can see a function named trib() below. This function is called with two-integer parameter from main() function.

__int64 is a 64-bit integer data type in Visual C++. So the following code was written in Visual C++.

typedef unsigned __int64 datatype;
datatype count;
datatype trib(int n, unsigned int back)
{
    datatype sum=0;
    int i;
    count++;
    if(n<=0) return 0;
    if(n==1) return 1;
    for(i=1;i<=back;i++)
         sum+=trib(n-i,back);
    return sum;
} 
void main(void)
{
    count=0;
    trib(5,5); 
    printf(¡§%I64u\n¡¨,count);
}

If you test you will find that the function trib() is invoked 41 times when it is called from the main function as trib(5, 5). You will have to determine the number of times the function is invoked for different values of n and back.

Input

The input file contains several lines of input. Each line contains two integers n(n<=61) and back(back<=60).   

Output

For each line of input produce one line of output. This line contains the case number and then an integer which denotes the number of times the trib() function is invoked for the corresponding input values of n and back. Input is terminated by a case where the value of n is greater than 60. This line should not be processed.

Sample Input              

3 3
4 4
5 5
6 6
7 7
8 8
9 9
61 61

Sample Output

Case 1: 7
Case 2: 17
Case 3: 41
Case 4: 97
Case 5: 225
Case 6: 513
Case 7: 1153

--------------------------------------------------------------------------------

(Problem-setter: Shahriar Manzoor, ACM Valladolid Online Judge)

*/