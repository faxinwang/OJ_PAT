
#include<cstdio>
using namespace std;


int main(){
	int N,*a,i,j;
	scanf("%d",&N);
	a=new int[N];
	for(i=0;i<N;++i){
		scanf("%d",a+i);
	}
	for(i=0;i<N-1;++i){
		int count=0;
		for(j=i+1;j<N;++j)
			if(a[i]>a[j])
				++count;
		printf("%d ",count);
	}
	printf("0");
	
	return 0;
} 

