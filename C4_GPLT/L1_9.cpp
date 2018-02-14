/*
L1-009. N个数求和
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
本题的要求很简单，就是求N个数字的和。麻烦的是，这些数字是以有理数“分子/分母”的
形式给出的，你输出的和也必须是有理数的形式。

输入格式：
输入第一行给出一个正整数N（<=100）。随后一行按格式“a1/b1 a2/b2 ...”给出N个有理数。
题目保证所有分子和分母都在长整型范围内。另外，负数的符号一定出现在分子前面。

输出格式：
输出上述数字和的最简形式 —— 即将结果写成“整数部分 分数部分”，其中分数部分写
成“分子/分母”，要求分子小于分母，且它们没有公因子。如果结果的整数部分为0，则只
输出分数部分。

输入样例1：
5
2/5 4/15 1/30 -2/60 8/3

输出样例1：
3 1/3

输入样例2：
2
4/3 2/3

输出样例2：
2

输入样例3：
3
1/3 -1/6 1/8

输出样例3：
7/24

*/ 
#include<iostream>
#include<cmath>
using namespace std;

class Num{
	public:
		int a,b,c;
	public:
		Num(int a=0,int b=0,int c=1):a(a),b(b),c(c){}
};

/*
-5/3 + 3/5 == -25/15 + 9/15 ==-1 -1/15 ==-2 14/15
*/ 
Num operator+(const Num& n1,const Num& n2){
	int b = (n1.b * n2.c + n2.b * n1.c) ;	//计算新的分子 
	int c = n1.c * n2.c;			//计算新的分母
	//计算新的整数部分 
	int a = n1.a + n2.a +b/c;
	b %= c;
	//如果整数部分不为0并且分子小于0,则把分子调成正数 
	if(b<0 && a){
		b+=c;
		--a;
	}
	//约分 
	for(int i=2;i<=abs(b) && i<=abs(c);)
		if(b%i==0 && c%i==0){
			b/=i;
			c/=i;
		}else{
			++i;
		}
	return Num( a, b, c);
}
//重载输出操作符 
ostream& operator<<(ostream& out,const Num& n){
	if(n.a) out<<n.a;	//如果整数部分不为0，则输出 
	if(n.a && n.b) out<<" ";	//如果分子不为0，则中间加一个空格 
	if(n.b) out<<n.b<<"/"<<n.c;	//如果分子不为0，则输出分数部分
	if(n.a==0 && n.b==0) out<<0;//如果整数部分和分数部分都为0，则输出0 
	return out;
}

int main(){
	int N,b,c;
	Num sum;
	scanf("%d",&N);
	
	while(N--){
		scanf("%d/%d",&b,&c);
		sum = sum + Num(0,b,c);
	}
	cout<<sum<<endl;

	return 0;
}

