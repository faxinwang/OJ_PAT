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
	//i<n-max��С������Χ 
	for(int i=0;i<n-max;++i){
		//j=i+max�ӿ������ٶ� 
		int j=i+max;
		//tmp��int��������� 
		for(double tmp=1.0*a[i]*p; j<n && a[j]<=tmp; ++j);
		max = (max>j-i)?max:j-i;
	}
	printf("%d\n",max);
	
	return 0;
} 
