/*
1009. Product of Polynomials (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
This time, you are supposed to find A*B where A and B are two polynomials.

Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and 
each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, 
where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) 
are the exponents and coefficients, respectively. It is given that 
1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.

Output Specification:
For each test case you should output the product of A and B in one line, 
with the same format as the input. Notice that there must be NO extra space 
at the end of each line. Please be accurate up to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output
3 3 3.6 2 6.0 1 1.6

题目大意：求两个多项式相乘的结果 

解题思路：
use a array to story the polynomial
the index i of array stands for the exponent of the ith item
array[i] storys the coefficient of ith itme 

*/ 
#include<iostream>
#include<cstdio>
#define SIZE 1001
using namespace std;

int main(){
	double p1[SIZE]={0},p2[SIZE]={0},p3[SIZE*2]={0},coe;
	int idx,n;
	//input the first polynomial
	cin>>n;
	for(int i=0;i<n;++i){
		scanf("%d",&idx);
		scanf("%lf",p1+idx);
	}
	//input the second polynomial
	cin>>n;
	for(int i=0;i<n;++i){
		scanf("%d",&idx);
		scanf("%lf",p2+idx);
	}
	//produce the A * B
	for(int i=0;i<SIZE;++i){
		if(p1[i])
			for(int j=0;j<SIZE;++j)
				if(p2[j])
					p3[i+j] += p1[i]*p2[j];
	}
	
	//print the result
	//if the result==0,then only 0 is supposed to be print
	int k=0;
	for(int i=0;i<SIZE*2;++i)
		if(p3[i]) ++k;
	cout<<k;
	if(k){
		for(int i=SIZE*2-1;i>=0;--i)
			if(p3[i])
				printf(" %d %.1lf",i,p3[i]);
	}
	
	return 0;
} 
