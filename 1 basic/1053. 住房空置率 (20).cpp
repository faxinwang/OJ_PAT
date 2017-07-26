#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int N,D;
	int maybe=0,be=0;
	double E,e;
	cin>>N>>E>>D;
	for(int i=0;i<N;++i){
		int count = 0,k;
		scanf("%d",&k);
		for(int j=0;j<k;++j){
			scanf("%lf",&e);
			if(e<E) ++count; 
		}
		if(k>D && count > k/2) ++be;
		else if(count > k/2) ++maybe;
	}
	printf("%.1lf%% %.1lf%%\n",100.0*maybe/N, 100.0*be/N);
	
	return 0;
}
