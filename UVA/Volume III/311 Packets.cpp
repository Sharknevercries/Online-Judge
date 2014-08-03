/* 9250705 311 Packets Accepted C++ 0.008 2011-09-12 04:25:37 */
#include<stdio.h>
#include<math.h>
int main(){
	int m[6];	
	while(scanf("%d%d%d%d%d%d",&m[0],&m[1],&m[2],&m[3],&m[4],&m[5])==6){
		if(m[0]==0&&m[1]==0&&m[2]==0&&m[3]==0&&m[4]==0&&m[5]==0)
			break;
		int count=0,temp;
		
		// 6*6
		count+=m[5];
		m[5]=0;
		// 5*5
		count+=m[4]; m[0] = (m[0]-m[4]*11 >= 0 ? m[0]-m[4]*11 : 0 )	;	m[4]=0;
		// 4*4
		count+=m[3];	
		temp=m[3]*5*(2*2);
		if(m[1]>=m[3]*5)
			m[1]-=m[3]*5,temp=0;
		else
			temp-=m[1]*(2*2),m[1]=0;
		m[0] = (m[0]-temp >= 0 ?m[0]-temp : 0 );
		m[3]=0;
		// 3*3
		count+=ceil((m[2]/4.0));
		m[2]%=4;
		switch(m[2]){
		case 0:	break;
		case 1:
			temp=6*6-3*3;
			if(m[1]>=5)
				m[1]-=5,temp-=5*(2*2);
			else
				temp-=m[1]*(2*2),m[1]=0;
			m[0] = (m[0]-temp >= 0 ? m[0]-temp : 0 );
			break;
		case 2:
			temp=6*6-3*3*2;
			if(m[1]>=3)
				m[1]-=3,temp=3*(2*2);
			else
				temp-=m[1]*(2*2),m[1]=0;
			m[0] = (m[0]-temp >= 0 ? m[0]-temp : 0 );
			break;		
		case 3:
			temp=6*6-3*3*3;
			if(m[1]>=1)
				m[1]-=1,temp-=1*(2*2);
			else
				temp-=m[1]*(2*2),m[1]=0;
			m[0] = (m[0]-temp >= 0 ? m[0]-temp : 0 );
			break;
		}
		m[2]=0;
		// 2*2;
		count+=ceil(m[1]/9.0);
		m[1]%=9;
		temp = ( m[1]!=0 ? temp=6*6-m[1]*2*2	 : temp=0 );
		m[0] = (m[0]-temp >= 0 ? m[0]-temp : 0 );
		m[1]=0;
		// 1*1
		count+=ceil(m[0]/36.0);
		m[0]=0;
		printf("%d\n",count);
	}
	return 0;
}
/* 

A factory produces products packed in square packets of the same height h and of the sizes , , , , , . These products are always delivered to customers in the square parcels of the same height h as the products have and of the size . Because of the expenses it is the interest of the factory as well as of the customer to minimize the number of parcels necessary to deliver the ordered products from the factory to the customer. A good program solving the problem of finding the minimal number of parcels necessary to deliver the given products according to an order would save a lot of money. You are asked to make such a program.
 
Input
 
The input file consists of several lines specifying orders. Each line specifies one order. Orders are described by six integers separated by one space representing successively the number of packets of individual size from the smallest size to the biggest size . The end of the input file is indicated by the line containing six zeros.
  
Output
 
The output file contains one line for each line in the input file. This line contains the minimal number of parcels into which the order from the corresponding line of the input file can be packed. There is no line in the output file corresponding to the last ``null'' line of the input file.
 
Sample Input 

0 0 4 0 0 1
7 5 1 0 0 0
0 0 0 0 0 0 

Sample Output
 
2
1 

*/