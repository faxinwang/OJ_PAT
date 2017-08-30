#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm> 
#define Max 10005
using namespace std;

int m,n;
int a[Max][Max];

int main(){
	int N;
	scanf("%d",&N);
	//计算m n 
	n = sqrt(N);
	while(N % n) --n;
	m = N / n;
	//input data 
	vector<int> v(N);
	for(int i=0;i<N;++i) scanf("%d",&v[i]);
	sort(v.begin(),v.end(),greater<int>()); //descending sort
	int i=0,j=-1,k=0;
	while(k<N){
		//往右走 
		for(++j; j<n && a[i][j]==0; ++j) a[i][j] = v[k++];
		--j;
		//往下走 
		for(++i; i<m && a[i][j]==0; ++i) a[i][j] = v[k++];
		--i;
		//往左走
		for(--j; j>=0&& a[i][j]==0; --j) a[i][j] = v[k++];
		++j;
		//往上走
		for(--i; i>=0&& a[i][j]==0; --i) a[i][j] = v[k++]; 
		++i;
	}
	//print matrix
	for(i=0;i<m;++i){
		printf("%d",a[i][0]);
		for(j=1;j<n;++j) printf(" %d",a[i][j]);
		printf("\n");
	}
	
	return 0;
}
