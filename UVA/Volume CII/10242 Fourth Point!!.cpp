/* 8850899 10242 Fourth Point !! Accepted C++ 0.012 2011-05-16 10:51:53 */
#include<stdio.h>
int main(){
	double x[4],y[4];
	while(scanf("%lf%lf",&x[0],&y[0])==2){
		bool found;
		int i,j,k;
		int index[2],pos[2],count;
		double ans_x,ans_y;
		for(i=1;i<4;i++)
			scanf("%lf%lf",&x[i],&y[i]);
		for(i=0,found=false;i<4;i++){
			for(j=i+1;j<4;j++)
				if(x[i]==x[j]&&y[i]==y[j]){
					found=true;
					break;
				}
			if(found) break;
		}
		for(k=count=0;k<4;k++)
			if(k==i||k==j)
				continue;
			else{
				index[count]=k;
				if(x[index[count]]>=x[i]&&y[index[count]]>y[i]) // 判斷該點屬於重複點之相對象限
					pos[count++]=1;                             // 其實pos只需判斷其一即可 但為了方便...
				else if(x[index[count]]<x[i]&&y[index[count]]>=y[i])
					pos[count++]=2;
				else if(x[index[count]]<=x[i]&&y[index[count]]<y[i])
					pos[count++]=3;
				else
					pos[count++]=4;
			}
		if(pos[index[0]]==1){
			ans_x=x[index[1]]+(x[index[0]]-x[i]);
			ans_y=y[index[1]]+(y[index[0]]-y[i]);
		}
		else if(pos[index[0]]==2){
			ans_x=x[index[1]]-(x[i]-x[index[0]]);
			ans_y=y[index[1]]+(y[index[0]]-y[i]);
		}
		else if(pos[index[0]]==3){
			ans_x=x[index[1]]-(x[i]-x[index[0]]);
			ans_y=y[index[1]]-(y[i]-y[index[0]]);
		}
		else{
			ans_x=x[index[1]]+(x[index[0]]-x[i]);
			ans_y=y[index[1]]-(y[i]-y[index[0]]);
		}
		printf("%.3lf %.3lf\n",ans_x,ans_y);
		
	}
	return 0;
}
/*

Given are the (x, y) coordinates of the endpoints of two adjacent sides of a parallelogram. Find the (x, y) coordinates of the fourth point. 
 
 Input

Each line of input contains eight floating point numbers: the (x, y) coordinates of one of the endpoints of the first side followed by the (x, y) coordinates of the other endpoint of the first side, followed by the (x, y) coordinates of one of the endpoints of the second side followed by the (x, y) coordinates of the other endpoint of the second side. All coordinates are in meters, to the nearest mm. All coordinates are between -10000 and +10000. Input is terminated by end of file.

Output

For each line of input, print the (x, y) coordinates of the fourth point of the parallelogram in meters, to the nearest mm, separated by a single space.
 
 Sample Input

 0.000 0.000 0.000 1.000 0.000 1.000 1.000 1.000
 1.000 0.000 3.500 3.500 3.500 3.500 0.000 1.000
 1.866 0.000 3.127 3.543 3.127 3.543 1.412 3.145
 
Sample Output

 1.000 0.000
 -2.500 -2.500
 0.151 -0.398
 
--------------------------------------------------------------------------------

(World Finals Warm-up Contest, Problem Source: University of Alberta Local Contest)

“You don’t get a rank in a contest if you don’t solve any problem. So there must be a Problem

which can be solved by almost every team.”
 
*/