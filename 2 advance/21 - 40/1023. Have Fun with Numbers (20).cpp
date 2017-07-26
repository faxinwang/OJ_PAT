#include<iostream>
#include<algorithm>
using namespace std;
/*
��Ŀ���⣺
����һ��������20λ���ֵ�������n���ж� m = 2*n �Ƿ�����n������������ɡ�

����˼·:
��string�������������n1��ʹ�ø߾����㷨������������ֵ�����n2
Ȼ���n1,n2������������n1==n2,������������ģ����Yes���������No 
*/ 

string doub(string num){
	if(num[0] == '0') return "0";
	string s;
	int carry=0;
	for(int i=num.size()-1; i>=0; --i){
		carry += (num[i] - '0') * 2;
		s += carry % 10 + '0';
		carry /= 10;
	}
	while(carry){
		s += carry % 10 +'0' ;
		carry /= 10;
	}
	reverse(s.begin(),s.end());
	return s;
}

int main(){
	string n1;
	cin>>n1;
	string n2 = doub(n1);
	string tmp = n2;
	
	sort(n1.begin(),n1.end());
	sort(n2.begin(),n2.end());	
	cout<<(n1==n2?"Yes":"No")<<endl;
	cout<<tmp<<endl;
	
	return 0;
}
