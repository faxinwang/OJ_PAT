#include<iostream>
#include<cstdio>
#include<cmath>
#define MAXDIV 46341
using namespace std;

//求从div开始的连续因子个数 
int max_fact(int n,int div){
	int k=0;
	while( n % div == 0 ){
		++k;
		n/=div;
		++div;
	}
	return k;
}


int main(){
	int fact[MAXDIV]={0};
	int N;
	cin>>N;
	int M = sqrt(N)+1; //最大因子 
	for(int i=2;i<=M;++i)//fact[i]保存以i开始的最大连续因子 
		fact[i]=max_fact(N,i);
	int max=2;
	for(int i=3;i<=M;++i)
		if(fact[max] < fact[i]) max=i;
		
	if(fact[max]==0){
		printf("1\n%d\n",N);
	}
	else{
		printf("%d\n",fact[max]);
		for(int i=max;i<max+fact[max]-1;++i)
			printf("%d*",i);
		printf("%d\n",max+fact[max]-1);
	}
	
	return 0;
}
