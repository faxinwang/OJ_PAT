#include<iostream>
#include<cstdio>
#define N 100002
using namespace std;
/*
(0.1) (0.1, 0.2) (0.1, 0.2, 0.3) (0.1, 0.2, 0.3, 0.4) (0.1, 0.2, 0.3, 0.4, 0.5)
(0.2) (0.2, 0.3) (0.2, 0.3, 0.4) (0.2, 0.3, 0.4, 0.5)
(0.3) (0.3, 0.4) (0.3, 0.4, 0.5)
(0.4) (0.4, 0.5)
(0.5)

每个数出现的次数为(N-i) * (i+1) ,i从0开始 
*/

int main(){
	int n;
	double a,sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%lf",&a);
		sum += a * (n-i) * (i+1);
	}	
	printf("%.2lf\n",sum);
	
	return 0;
} 
