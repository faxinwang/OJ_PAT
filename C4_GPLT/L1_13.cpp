#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

string factorial(int n){
	string big="1";
	int carry=0;
	for(int i=2;i<=n;++i){
		for(int j=0;j<big.size();++j){
			carry += (big[j]-'0') * i;
			big[j] = carry % 10 + '0';
			carry /= 10;
		}
		while(carry){
			big += carry % 10 + '0';
			carry /= 10;
		}
	}
//	reverse(big.begin(),big.end());
	return big;//����Ǹ�λ���ұ��Ǹ�λ���������ڼӷ����� 
}
string add(const string& a,const string& b){
	int carry=0;
	string res="";
	for(int i=0;i<a.size()||i<b.size();++i){
		if(i<a.size()) carry += a[i]-'0';
		if(i<b.size()) carry += b[i]-'0';
		res += carry % 10 + '0';
		carry /= 10;
	}
	//�����λ 
	while(carry){
		res += carry % 10 + '0';
		carry /= 10;
	}
	return res;
}
string S(int n){
	string sum="";
	for(int i=1;i<=n;++i){
		sum = add(sum,factorial(i));
	}
	//����λ������� 
	reverse(sum.begin(),sum.end());
	return sum;
}

int main(){
	int n;
	scanf("%d",&n);
	cout<<S(n)<<endl;
	
	return 0;
}
