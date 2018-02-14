/*
L2-005. �������ƶ�
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
���������������ϣ����ǵ����ƶȶ���Ϊ��Nc/Nt*100%������Nc���������϶��еĲ���������ĸ�����
Nt����������һ���еĲ���������ĸ��������������Ǽ�������һ�Ը������ϵ����ƶȡ�

�����ʽ��
�����һ�и���һ��������N��<=50�����Ǽ��ϵĸ��������N�У�ÿ�ж�Ӧһ�����ϡ�ÿ����������
����һ��������M��<=104�����Ǽ�����Ԫ�صĸ�����Ȼ���M��[0, 109]�����ڵ�������
֮��һ�и���һ��������K��<=2000�������K�У�ÿ�ж�Ӧһ����Ҫ�������ƶȵļ��ϵı�ţ����ϴ�
1��N��ţ������ּ��Կո�ָ���

�����ʽ��
��ÿһ����Ҫ����ļ��ϣ���һ����������ǵ����ƶȣ�Ϊ����С�����2λ�İٷֱ����֡�

����������
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3

���������
50.00%
33.33%

*/ 
#include<iostream> 
#include<set>
using namespace std;
set<int> s[50];

double familiar(set<int>&a,set<int>& b){
	int Nc=0;
	typename set<int>::iterator pa,pb;
	for(pa=a.begin(),pb=b.begin(); pa!=a.end() && pb!=b.end();){
		if(*pa < *pb){
			++pa;
		}else if(*pa > *pb){
			++pb;
		}else{
			++pa; ++pb; ++Nc;
		}
	}
	int Nt = a.size()+b.size()-Nc;
	return 1.0*Nc/Nt*100;
}

int main(){
	int N,M;
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d",&M);
		int tmp;
		for(int j=0;j<M;++j){
			scanf("%d",&tmp);
			s[i].insert(tmp);
		}
	}
	scanf("%d",&M);
	for(int i=0;i<M;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%.2lf%%\n",familiar(s[a-1],s[b-1]));
	}	
	
	return 0;
}
