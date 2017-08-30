#include<iostream>
#include<string>
using namespace std;

int main(){
	int N;
	char ch;
	cin>>N>>ch;
	cout<<string(N,ch)<<endl;
	for(int i=0,len=(N+1)/2-2; i<len; ++i) cout<<ch<<string(N-2,' ')<<ch<<endl;
	cout<<string(N,ch)<<endl;
	
	return 0;
} 
