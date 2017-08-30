#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


int main(){
	char ch[200]={0};
	string a,b;
	cin>>a>>b;
	for(int i=0,len=b.size(); i<len;++i){
		ch[b[i]] = 1;
	}
	
	
	
	for(int i=0,len=a.size(); i<len;++i){
		if(ch[a[i]]==0){
			if('a' <= a[i] && a[i]<='z'){
				cout<<char(a[i]-32);
				ch[a[i]] = 1;
				ch[a[i]-32] = 1;
			}else if('A' <=a[i] && a[i]<='Z'){
				cout<<a[i];
				ch[a[i]] = 1;
				ch[a[i]+32] = 1;
			}else{
				cout<<a[i];
				ch[a[i]] = 1;
			}
		}
	}
	cout<<endl;
	
	return 0;
}
