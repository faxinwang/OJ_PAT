#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	printf("2^%d = %d\n",n,(2<<(n-1)));
	
	return 0;
}
