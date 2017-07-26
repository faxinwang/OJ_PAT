#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100005
using namespace std;

unsigned int a[N];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	sort(a+1,a+n+1,greater<int>());
	int E=0,i=1;
	for(; a[i]>i && E<=n; ++E,++i);
	printf("%d\n",E);
	
	return 0;
}
