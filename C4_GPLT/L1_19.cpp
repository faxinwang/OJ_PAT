#include<iostream>
using namespace std;

int main(){
	int jlA,jlB,A,B,N;
	cin>>jlA>>jlB>>N;//����N���Բ�ʹ�� 
	A=jlA;
	B=jlB;
	int a1,a2,b1,b2;
	while( A>=0 && B>=0){
		scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
		bool faila = a2==(a1+b1);//�׻� == (�׺� + �Һ�) 
		bool failb = b2==(a1+b1);
		if(faila && failb) continue;//������ͬʱ�� 
		if(faila) --A;
		if(failb) --B;
	}
	if(A<0){//���ȵ��� 
		printf("A\n%d",jlB-B);
	}else{
		printf("B\n%d",jlA-A);
	}
	
	return 0;
}
