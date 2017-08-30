#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(){
	int a[10]={0};
	string str;
	cin>>str;
	for(int i=0,len=str.size(); i<len; ++i){
		++a[str[i]-'0'];
	}
	for(int i=0;i<10;++i)
		if(a[i]) printf("%d:%d\n",i,a[i]);
	
	return 0;
}
