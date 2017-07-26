#include<stdio.h>
#define MAX 100010

int prime[MAX];
int p[MAX];

void init(){
	prime[0] = prime[1] = 1; //设为1表示不是素数 
	//素数筛选
	for(int i=2;i*i<MAX;++i)
		if(prime[i]==0)		//如果该位置的数没有被去除 ,就筛去他的倍数 
			for(int j=i*i;j<MAX; j+=i)
				prime[j] = 1;
				
	//把所有素数转存到另一个数组中
	for(int i=2,k=0; i<MAX;++i) 
		if(prime[i]==0){
			p[k++] = i;
//			printf("%d %s",i,(k%10?" ":"\n")); 
		} 
}

int main(){
	int N,count=0;
	scanf("%d",&N);
	init();
	for(int i=1; p[i] <= N; ++i){
		if(p[i] - p[i-1] == 2) ++count;
	}
	printf("%d",count); 
	
	return 0;
}
