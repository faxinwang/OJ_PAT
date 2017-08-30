#include<iostream>
#include<cstdio>
using namespace std;

int s[101];

int main(){
	int n,k,score;
	
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&score);
		++s[score];
	}
	scanf("%d%d",&k,&score);
	printf("%d",s[score]);
	for(int i=1;i<k;++i){
		scanf("%d",&score);
		printf(" %d",s[score]);
	}
	
	return 0;
}
