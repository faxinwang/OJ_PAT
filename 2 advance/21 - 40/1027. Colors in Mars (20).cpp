#include<iostream>
#include<algorithm>
using namespace std;

/*
��Ŀ����:
����10���Ƶ�r,g,bֵ����� 13���Ƶ�r,g,b��ɫ��ʾ.
�����ʽ��#rrggbb ���ĳһ����ɫ����ֻ��һλ���֣�Ҫ��ǰ�油��0,���� #010203
����˼·:
��Ŀ�ܼ򵥣�дһ��������10��������ת��Ϊ13��������(���ַ�����ʾ).
*/
const string nums="0123456789ABC"; //ע���ô�д��ĸ. 

string convert(int n){
	if(n==0) return "00";
	string s;
	while(n){
		s += nums[n%13];
		n /= 13;
	}
	if(s.size()==1) s = "0"+s;
	else reverse(s.begin(),s.end());
	return s;
}

int main(){
	int r,g,b;
	scanf("%d%d%d",&r,&g,&b);
	cout<<"#"<<convert(r)<<convert(g)<<convert(b)<<endl;
	
	return 0;
}
