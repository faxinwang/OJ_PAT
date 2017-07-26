#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/*
��Ŀ���⣺
����һ������: n = n + n�������� 
����N(N<=10^10) ,K(K<=100),�����N�������ٴ������������ܵõ�һ����������
���K�͵õ��Ļ������֡�������������ﵽK��ʱ��û�еõ���������
�����K�β���֮��õ������ֺ�K 

����˼·:
input s
1. let tn = reversed(s)
2. if s == tn, then ouput the results and return.
3  let n = s + tn and go to step 1.

*/ 

string reversed(string s){
	reverse(s.begin(),s.end());
	return s;
}

//�߾��ȼӷ� ����a+b���ַ�����ʾ 
string add(string a,string b){
	int carry = 0;
	string res;
	for(int i=a.size()-1, j=b.size()-1; i>=0 || j>=0 ; --i,--j){
		if(i>=0) carry += a[i] - '0';
		if(j>=0) carry += b[i] - '0';
		res += carry%10 + '0' ;
		carry /= 10;
	}
	while(carry){
		res += carry % 10 + '0' ;
		carry /= 10;
	}
	reverse(res.begin(),res.end());
	return res;
}

int main(){
	int k;
	string n;
	cin>>n>>k;
	
	for(int i=0;i<k;++i){
		string tn = reversed(n);
		if(n == tn){
			cout<<n<<endl<<i<<endl;
			return 0; 
		}else{
			n = add(n,reversed(n));
		}
	}
	cout<<n<<endl<<k<<endl;
	
	return 0;
}
