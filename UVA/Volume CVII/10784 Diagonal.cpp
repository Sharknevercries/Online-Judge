/* 9275939 10784 Diagonal Accepted C++ 0.008 2011-09-19 09:02:01  */
#include<stdio.h>
#include<math.h>
int main(){
    long long int n,t=1;
    while(scanf("%lld",&n)==1){
        if(n==0)
            break;
        
        double a=(sqrt((double)9+8*n)+3)/2;
        printf("Case %d:",t++);
        printf(" %.lf\n",ceil(a));
    }
    return 0;
}
/*

The number of diagonals of an n-gon is not less than N. What is the minimum possible value of n? 
 
Input  

The input file contains less than 1001 lines of inputs. Each line contains a positive integer N ( N1015) that indicates the minimum possible number of diagonals. Input is terminated by a line containing a zero. This line should not be processed. 

Output  

For each line of input produce one line of output, which contains the output serial number, and also the minimum possible value for n (Number of sides). 

Sample Input  
10
100
1000
0

Sample Output  
Case 1: 7
Case 2: 16
Case 3: 47

--------------------------------------------------------------------------------

Miguel Revilla 2004-12-02 

*/
