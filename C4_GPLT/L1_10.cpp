#include<iostream>
using namespace std;

int min(int a,int b,int c){
	return a<b?(a<c?a:c):(b<c?b:c);
}
int max(int a,int b,int c){
	return a>b?(a>c?a:c):(b>c?b:c);
}

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int min_=min(a,b,c);
	int max_=max(a,b,c);
	int mid_=(a+b+c)-(max_+min_);
	printf("%d->%d->%d\n",min_,mid_,max_);
	
	
	return 0;
}
