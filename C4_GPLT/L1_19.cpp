#include<iostream>
using namespace std;

int main(){
	int jlA,jlB,A,B,N;
	cin>>jlA>>jlB>>N;//这里N可以不使用 
	A=jlA;
	B=jlB;
	int a1,a2,b1,b2;
	while( A>=0 && B>=0){
		scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
		bool faila = a2==(a1+b1);//甲划 == (甲喊 + 乙喊) 
		bool failb = b2==(a1+b1);
		if(faila && failb) continue;//两个人同时输 
		if(faila) --A;
		if(failb) --B;
	}
	if(A<0){//甲先倒下 
		printf("A\n%d",jlB-B);
	}else{
		printf("B\n%d",jlA-A);
	}
	
	return 0;
}
