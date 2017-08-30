#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int a[10005];

/*
解题思路：由于每次将两根绳子相连后两根绳子的长度都会减半，
所以将绳子按长度增加的顺序排序，先将长度短的绳子连起来，在用连起来的
绳子跟更长的绳子连起来。 
*/ 

int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d",a+i);
	}
	sort(a,a+N);
	double s = a[0];
	//与下一根绳子结起来，长度会减半 
	for(int i=1;i<N;++i){
		s += a[i];
		s /= 2;
	}
	printf("%d\n",int(s));
	
	return 0;
}
