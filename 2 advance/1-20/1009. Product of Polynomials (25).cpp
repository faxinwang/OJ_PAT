#include<iostream>
#include<cstdio>
#define SIZE 1001
using namespace std;

/*
use a array to story the polynomial
the index i of array stands for the exponent of the ith item
array[i] storys the coefficient of ith itme
*/

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
