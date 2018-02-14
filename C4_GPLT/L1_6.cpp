/*
L1-006. 连续因子
时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
一个正整数N的因子中可能存在若干连续的数字。例如630可以分解为3*5*6*7，其中5、6、7就是3个
连续的数字。给定任一正整数N，要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。

输入格式：
输入在一行中给出一个正整数N（1<N<231）。

输出格式：
首先在第1行输出最长连续因子的个数；然后在第2行中按“因子1*因子2*……*因子k”的格式输出
最小的连续因子序列，其中因子按递增顺序输出，1不算在内。

输入样例：
630

输出样例：
3
5*6*7

解题思路：
对于给定的N，求出从1到sqrt(N)的所有连续因子的个数保存在数组中， 例如f[4]=5，表示从4开始的
连续因子的个数为5，然后找出f[i]中的最大值就可以了。 
*/ 
#include<iostream>
#include<cstdio>
#include<cmath>
#define MAXDIV 46341
using namespace std;

//求从div开始的连续因子个数 
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
	int M = sqrt(N)+1; //最大因子 
	for(int i=2;i<=M;++i)//fact[i]保存以i开始的最大连续因子 
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
