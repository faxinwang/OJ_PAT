/*
L1-006. ��������
ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
��Խ
һ��������N�������п��ܴ����������������֡�����630���Էֽ�Ϊ3*5*6*7������5��6��7����3��
���������֡�������һ������N��Ҫ���д���������������ӵĸ������������С�������������С�

�����ʽ��
������һ���и���һ��������N��1<N<231����

�����ʽ��
�����ڵ�1�������������ӵĸ�����Ȼ���ڵ�2���а�������1*����2*����*����k���ĸ�ʽ���
��С�������������У��������Ӱ�����˳�������1�������ڡ�

����������
630

���������
3
5*6*7

����˼·��
���ڸ�����N�������1��sqrt(N)�������������ӵĸ��������������У� ����f[4]=5����ʾ��4��ʼ��
�������ӵĸ���Ϊ5��Ȼ���ҳ�f[i]�е����ֵ�Ϳ����ˡ� 
*/ 
#include<iostream>
#include<cstdio>
#include<cmath>
#define MAXDIV 46341
using namespace std;

//���div��ʼ���������Ӹ��� 
int max_fact(int n,int div){
	int k=0;
	while( n % div == 0 ){
		++k;
		n/=div;
		++div;
	}
	return k;
}


int main(){
	int fact[MAXDIV]={0};
	int N;
	cin>>N;
	int M = sqrt(N)+1; //������� 
	for(int i=2;i<=M;++i)//fact[i]������i��ʼ������������� 
		fact[i]=max_fact(N,i);
	int max=2;
	for(int i=3;i<=M;++i)
		if(fact[max] < fact[i]) max=i;
		
	if(fact[max]==0){
		printf("1\n%d\n",N);
	}
	else{
		printf("%d\n",fact[max]);
		for(int i=max;i<max+fact[max]-1;++i)
			printf("%d*",i);
		printf("%d\n",max+fact[max]-1);
	}
	
	return 0;
}
