#include<cstdio>
#include<time.h>
#define N 10010

int a=12;
int pri[N*12];
int p[N];
void init(){
	pri[0]=pri[1]=1;
	for(int i=2,n=N*a;i*i<n;++i)
		if(pri[i]==0)
			for(int j=2*i,n=N*a;j<n;j+=i)
				pri[j]=1;
				
	for(int i=2,n=N*a,k=0;i<n && k<N;++i){
		if(pri[i]==0){
			p[k++] = i;
//			printf("k=%d,i=%d ",k,i);
		}
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
//	double start = clock();
	init();
//	double end = clock();
//	printf("%.3lf",(end-start)/CLOCKS_PER_SEC); 
	
	scanf("%d%d",&m,&n);
	print(m,n);
	
	return 0;
}
