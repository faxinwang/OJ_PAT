#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int a[10005];

/*
����˼·������ÿ�ν����������������������ӵĳ��ȶ�����룬
���Խ����Ӱ��������ӵ�˳�������Ƚ����ȶ̵�������������������������
���Ӹ������������������� 
*/ 

int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d",a+i);
	}
	sort(a,a+N);
	double s = a[0];
	//����һ�����ӽ����������Ȼ���� 
	for(int i=1;i<N;++i){
		s += a[i];
		s /= 2;
	}
	printf("%d\n",int(s));
	
	return 0;
}
