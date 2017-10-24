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
	int b = (n1.b * n2.c + n2.b * n1.c) ;	//�����µķ��� 
	int c = n1.c * n2.c;			//�����µķ�ĸ
	//�����µ��������� 
	int a = n1.a + n2.a +b/c;
	b %= c;
	//����������ֲ�Ϊ0���ҷ���С��0,��ѷ��ӵ������� 
	if(b<0 && a){
		b+=c;
		--a;
	}
	//Լ�� 
	for(int i=2;i<=abs(b) && i<=abs(c);)
		if(b%i==0 && c%i==0){
			b/=i;
			c/=i;
		}else{
			++i;
		}
	return Num( a, b, c);
}
//������������� 
ostream& operator<<(ostream& out,const Num& n){
	if(n.a) out<<n.a;	//����������ֲ�Ϊ0������� 
	if(n.a && n.b) out<<" ";	//������Ӳ�Ϊ0�����м��һ���ո� 
	if(n.b) out<<n.b<<"/"<<n.c;	//������Ӳ�Ϊ0���������������
	if(n.a==0 && n.b==0) out<<0;//����������ֺͷ������ֶ�Ϊ0�������0 
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

