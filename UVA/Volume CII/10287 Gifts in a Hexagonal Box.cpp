#include<stdio.h>
#include<math.h>
int main(){
	double s;
	while(scanf("%lf",&s)==1){
		printf("%.10lf %.10lf %.10lf %.10lf\n",s/2*sqrt(3.0),s/(1.0+2.0*sqrt(3.0)/3),s*sqrt(3.0)/4,3*s/(sqrt(3.0)*4));
	}
	return 0;
}