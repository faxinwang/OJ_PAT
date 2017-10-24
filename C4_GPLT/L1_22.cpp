#include<iostream> 
using namespace std;

int main(){
	int odd=0,mean=0,tmp,N;
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d",&tmp);
		if(tmp%2) ++odd;
		else ++mean;
	}
	printf("%d %d\n",odd,mean);
	
	return 0;
}
