/*
L2-005. 集合相似度
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
给定两个整数集合，它们的相似度定义为：Nc/Nt*100%。其中Nc是两个集合都有的不相等整数的个数，
Nt是两个集合一共有的不相等整数的个数。你的任务就是计算任意一对给定集合的相似度。

输入格式：
输入第一行给出一个正整数N（<=50），是集合的个数。随后N行，每行对应一个集合。每个集合首先
给出一个正整数M（<=104），是集合中元素的个数；然后跟M个[0, 109]区间内的整数。
之后一行给出一个正整数K（<=2000），随后K行，每行对应一对需要计算相似度的集合的编号（集合从
1到N编号）。数字间以空格分隔。

输出格式：
对每一对需要计算的集合，在一行中输出它们的相似度，为保留小数点后2位的百分比数字。

输入样例：
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3

输出样例：
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
