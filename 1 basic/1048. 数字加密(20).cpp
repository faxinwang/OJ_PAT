#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
char map[]={'0','1','2','3','4','5','6','7','8','9','J','Q','K'};

int main(){
	string A,B,s;
	cin>>A>>B;
	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());
	if(A.size() > B.size()) B += string(A.size() - B.size(),'0');
	int len = A.size(); //A的长度不会超过B 
	for(int i=0; i<len; ++i){
		if( (i+1) % 2){
			char ch = (A[i] - '0' + B[i] - '0') % 13;
			s += map[ch];
		}else{
			char ch = (10 + (B[i] - '0') - (A[i] - '0') ) % 10;
			s += map[ch];
		}
	}
	if(A.size()<B.size()) s += B.substr(len);
	reverse(s.begin(),s.end());
	cout<<s<<endl;
	
	return 0;
}
