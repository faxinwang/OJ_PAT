#include<iostream>
#include<string>
#include<map>
using namespace std;

int count[6];

int main(){
	map<char,int> map;
	map['P'] = 0;
	map['A'] = 1;
	map['T'] = 2;
	map['e'] = 3;
	map['s'] = 4;
	map['t'] = 5;
	string s;
	cin>>s;
	for(int i=0,len=s.size(); i<len;++i) 
		if(map.find(s[i]) != map.end()) ++count[map[s[i]]];
		
	while(count[0] || count[1] ||count[2] ||count[3] ||count[4] ||count[5]){
		if(count[0]){
			--count[0];
			cout<<"P";
		}
		if(count[1]){
			--count[1];
			cout<<"A";
		}
		if(count[2]){
			--count[2]; 
			cout<<"T";
		}
		if(count[3]){
			--count[3];
			cout<<"e";
		}
		if(count[4]){
			--count[4];
			cout<<"s";
		}
		if(count[5]){
			--count[5];
			cout<<"t";
		}
		
	}
	
	return 0;
} 
