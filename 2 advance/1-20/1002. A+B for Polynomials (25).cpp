#include<cstdio>
#define Size 1001

/*
�� hash table ��������
�����±��ʾ����
ϵ�������ڶ�Ӧ�±��Ԫ���� 
*/ 

int main(){
	//table elems should be initialized to 0
	double table[Size]={0},coe;
	int idx,N;
	//input the number of elem of first Polynomial
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		//input the exponent
		scanf("%d",&idx);
		//input the coefficient
		scanf("%lf",table+idx);
	}
	//input the number of elem of second Polynomial
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		//input the exponent
		scanf("%d",&idx);
		//input the coefficient
		scanf("%lf",&coe);
		table[idx]+=coe;
	}
	//count the nonzero polynomial
	int k=0;
	for(int i=0;i<Size;++i)
		if(table[i]) ++k;
	
	//print the result
	printf("%d",k);
	//if the result is 0,then only 0 is supposed to be printed
	if(k){
		for(int i=Size-1;i>=0;--i)
			if(table[i])
				printf(" %d %.1lf",i,table[i]);
	}
	
	return 0;
} 
