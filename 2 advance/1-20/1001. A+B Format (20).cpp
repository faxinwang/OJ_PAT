#include<iostream>
#include<string>
using namespace std;

int main(){
	int a,b,c,k=0;
	char ch;
	string s;
	cin>>a>>b;
	c=a+b;
//	cout<<c<<endl;
	if(c<0)	c=-c;
	while(c){
		ch=c%10;
		c/=10;
		ch+='0';
//		cout<<ch;
		s=ch+s;
		if(++k==3){
			k=0;
			s=','+s;
		}
	}
	if(s[0]==',')
		s=s.substr(1,s.size());
	if(a+b < 0)
		s='-'+s;
	else if(a+b==0)
		s="0";
		
	cout<<s<<endl;
	return 0;
}
