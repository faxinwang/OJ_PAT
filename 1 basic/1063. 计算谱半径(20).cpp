#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
	int N,a,b;
	double maxr=0;
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d%d",&a,&b);
		double r = sqrt(a*a+b*b);
		if(maxr<r) maxr = r;
	}
	printf("%.2lf\n",maxr);
	
	return 0;
}
