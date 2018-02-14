/*
1002. A+B for Polynomials (25)
ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
CHEN, Yue
This time, you are supposed to find A+B where A and B are two polynomials.

Input
Each input file contains one test case. Each case occupies 2 lines, and each 
line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, 
where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) 
are the exponents and coefficients, respectively. It is given that 
1 <= K <= 10��0 <= NK < ... < N2 < N1 <=1000.

Output
For each test case you should output the sum of A and B in one line, with 
the same format as the input. Notice that there must be NO extra space 
at the end of each line. Please be accurate to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output
3 2 1.5 1 2.9 0 3.2


����˼·�� 
�� hash table ��������
�����±��ʾ����
ϵ�������ڶ�Ӧ�±��Ԫ����
*/ 

#include<cstdio>
#define Size 1001

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
