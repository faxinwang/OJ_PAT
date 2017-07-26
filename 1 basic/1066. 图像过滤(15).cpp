#include<iostream> 
#include<cstdio>
using namespace std;

int M,N,A,B,T;

int choose(int pix){
	if(A<=pix && pix<=B) return T;
	return pix;
}

int main(){
	int pix;
//	FILE* fout = fopen("text.txt","w");
	
	scanf("%d%d%d%d%d",&M,&N,&A,&B,&T);
	for(int i=0;i<M;++i){
		scanf("%d",&pix);
		printf("%03d",choose(pix));
		
		for(int j=1;j<N;++j){
			scanf("%d",&pix);
			printf(" %03d",choose(pix));
		}
		printf("\n");
	}
	
	return 0;
}
