#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int sum=0,N;
	int a[10];
	scanf("%d",&N);
	for(int i=0;i<N;++i) scanf("%d",a+i);
	for(int i=0;i<N-1;++i)
		for(int j=i+1;j<N;++j)
			sum += 10*a[i] + a[j] + 10*a[j] + a[i];
	printf("%d\n",sum);
	
	return 0;
}
