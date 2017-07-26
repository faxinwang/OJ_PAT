#include<cstdio>
#include<cmath>
#include<time.h>
#define N 10010

int p[N];

void init(){
	int count = 0;
	int num = 2; 
	while(count<N){
		// 优化1：排除偶数
		if(num%2==0 && num!=2){
			++num;
			continue;
		}
		
		// 优化2：不超过第cnt个质数的开方数
		int i=0;
		for(i = 0; i < sqrt(count); ++i)
			if(num % p[i] == 0) break;
		
		if(i >= sqrt(count)){
//			printf("count=%d,s=%lf,num=%d\n",count,sqrt(count),num);
			p[count++] = num;
		}
		++num;
	}
}

void print(int m,int n){
	for(int i=m-1,count=0;i<n-1;++i){
		printf("%d%s",p[i],(++count%10?" ":"\n")); 
	}
	printf("%d",p[n-1]);
}

int main(){
	int m,n;
	double start = clock();
	init();
	double end = clock();
	printf("time = %.3lf",(end-start)/CLOCKS_PER_SEC);
	scanf("%d%d",&m,&n);
	print(m,n); 

	return 0 ;
} 

 
