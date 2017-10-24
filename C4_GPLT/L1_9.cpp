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

