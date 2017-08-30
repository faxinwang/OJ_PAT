#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int A,DA,B,DB;
	int PA=0,PB=0;
	scanf("%d%d%d%d",&A,&DA,&B,&DB);
	
	while(A){
		int t = A % 10;
		if( t == DA ) PA = PA * 10 + DA;
		A /= 10;
	}
	
	while(B){
		int t = B % 10;
		if( t == DB ) PB = PB * 10 + DB;
		B /= 10; 
	}
	
	printf("%d" , PA + PB) ;
	
	
	return 0;
}
