#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;

int ascend(int n){
	int a[4]={0};
	for(int i=0;n;++i){
		a[i] = n % 10;
		n /= 10;
	}
	sort(a,a+4);
	
	return a[0]*1000+a[1]*100+a[2]*10+a[3];
}

int descend(int n){
	int a[4] = {0};
	for(int i=0;n;++i){
		a[i] = n % 10;
		n /= 10;
	}
	sort(a,a+4,greater<int>());
	return a[0]*1000+a[1]*100+a[2]*10+a[3];
}

int main(){
	int n;
	scanf("%d",&n);
	if(ascend(n) == descend(n)){
		printf("%04d - %04d = 0000\n",n,n);
	}else{
		int a=descend(n),b=ascend(n);
		for(;a - b != 6174; a = descend(n),b=ascend(n)){
			n = a - b;
			printf("%04d - %04d = %04d\n",a,b,n);
		}
		printf("%04d - %04d = 6174\n",a,b);
	}
	
	return 0;
}
