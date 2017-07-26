#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100005
using namespace std;

int a[N];

int main(){
	int n,p,max=1;
	cin>>n>>p;
	for(int i=0;i<n;++i) scanf("%d",a+i);
	sort(a,a+n);
	//i<n-max减小搜索范围 
	for(int i=0;i<n-max;++i){
		//j=i+max加快搜索速度 
		int j=i+max;
		//tmp用int会整形溢出 
		for(double tmp=1.0*a[i]*p; j<n && a[j]<=tmp; ++j);
		max = (max>j-i)?max:j-i;
	}
	printf("%d\n",max);
	
	return 0;
} 
