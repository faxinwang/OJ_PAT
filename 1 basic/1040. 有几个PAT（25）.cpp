#include<iostream>
#include<cstring>
#include<cstdio>
#define MOD 1000000007
using namespace std;

int main(){
	int cp=0,ct=0,sum=0;
	string s;
	cin>>s;
	for(int i=0,len=s.size(); i<len; ++i){
		if(s[i] == 'T') ++ct;
	}
	for(int i=0,len=s.size(); i<len; ++i){
		if(s[i] == 'P') ++cp;
		if(s[i] == 'T') --ct;
		if(s[i] == 'A') sum = ((cp * ct) % MOD + sum) % MOD;
	}
	cout<<sum<<endl;
		
	return 0;
}
