#include<iostream>
#include<string>
using namespace std;

int min(int a,int b){
	return a<b?a:b;
} 
char days[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

bool isdigit(char ch){
	return '0'<=ch && ch<='9';
}
bool isalpha(char ch){
	return ('A'<= ch && ch<= 'Z' )|| ('a'<= ch && ch<='z');
}

int main(){
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int mark;
	//output the weekday
	for(int i = 0,len = min(a.size(),b.size()); i < len; ++i){
		if(a[i] == b[i] && 'A'<=a[i] && a[i]<='G'){
			cout<<days[a[i]-'A']<<" ";
			mark = i;
			break;
		}
	}
	//output hh
	for(int i=mark+1,len = min(a.size(),b.size()); i < len; ++i){
		if(a[i] == b[i]){
			if(isdigit(a[i])){
				int x = a[i] - '0';
				cout<<x/10<<x%10<<":";
				break;
			}else if('A'<= a[i] && a[i]<='N'){
				int x = a[i] - 'A' + 10;
				cout<<x/10<<x%10<<":";
				break;
			}
		}
	}
	//output mm
	for(int i=0,len = min(c.size(),d.size()); i<=len; ++i){
		if(c[i] == d[i] && isalpha(c[i])){
			cout<<i/10<<i%10<<endl;
			break;
		}
	}
	
	return 0; 
} 

/*
0A0B0C
1A1B1C
ABCDE
Abcde
MON 11:00


0G0N0C
1G1N1C
12345678912345678912123A
12345678912345678912123A
SUN 23:23

0A00A000a
1A11A111a 
01234567890123456789012345678901234567890123456789012345678a
01234567890123456789012345678901234567890123456789012345678a
MON 10:59

3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
THU 14:04

*/
