#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int A,B,sum=0,count=0;
	scanf("%d%d",&A,&B);
	for(int i=A;i<=B;++i){
		sum+=i;
		printf("%5d%s",i,(++count%5?"":"\n"));
	}
	if(count%5)
		puts("");
	printf("Sum = %d\n",sum);
	
	return 0;
}
