#include<iostream>
#include<string>
using namespace std;

int main(){
	int n;
	char ch;
	cin>>n>>ch;
	string line(n,ch);
	int m=((n*0.5-n/2)<0.5?n/2:n/2+1);
	for(int i=0;i<m;++i)
		cout<<line<<endl;
	
	return 0;
}
