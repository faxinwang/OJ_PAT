#include<iostream>
#include<string>
#include<map>
#include<cstring>
#include<cstdlib>
using namespace std;

/*
地球人的0被火星人称为tret。
地球人数字1到12的火星文分别为：
jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
火星人将进位以后的12个高位数字分别称为：
tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
*/
int main(){
	map<string,int> m1,m2;
	m1["tret"]  = 0;
	m1["jan"] = 1;	m1["feb"] = 2;
	m1["mar"] = 3;	m1["apr"] = 4;
	m1["may"] = 5;	m1["jun"] = 6;
	m1["jly"] = 7;	m1["aug"] = 8;
	m1["sep"] = 9;	m1["oct"] = 10;
	m1["nov"] = 11;	m1["dec"] = 12;
	
	m2["tam"] = 1;	m2["hel"] = 2;
	m2["maa"] = 3;	m2["huh"] = 4;
	m2["tou"] = 5;	m2["kes"] = 6;
	m2["hei"] = 7;	m2["elo"] = 8;
	m2["syy"] = 9;	m2["lok"] = 10;
	m2["mer"] = 11;	m2["jou"] = 12;
	
	string itos1[]={"tret","jan","feb","mar","apr","may","jun",
					"jly","aug","sep","oct","nov","dec"};
	string itos2[]={"tret","tam","hel","maa","huh","tou","kes",
					"hei","elo","syy","lok","mer","jou"};
	int T;
	string s;
	cin>>T;
	getchar();
	while(T--){
		getline(cin,s);
		if(isalpha(s[0])){ //火星文 
			int pos;
			for(pos=0; s[pos]!=' ' && pos<s.size(); ++pos);
			if(pos!=s.size()){
				cout<<m2[s.substr(0,pos)] * 13 + m1[s.substr(pos+1)]<<endl;
			}else{
				if(m1.find(s) != m1.end()) cout<< m1[s] <<endl;
				else cout<< m2[s] * 13 <<endl;
			}
		}else{	//数字 
			int n = atoi(s.c_str());
			if(n==0){
				cout<<"tret"<<endl;
				continue;
			}
			bool flag = false;
			if(n/13){
				cout<<itos2[n/13];
				flag = true;
			}
			if(n%13){
				if(flag) cout<<" ";
				cout<<itos1[n%13];
			}
			cout<<endl;
		}
	}
	
	return 0;
} 
