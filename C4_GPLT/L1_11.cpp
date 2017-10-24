#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;

void substract(string &a,string &b){
	string res="";
	for(int i=0;i<a.size();++i){
		if(find(b.begin(),b.end(),a[i]) == b.end())
			res+=a[i];
	}
	cout<<res<<endl;
	//return res;
}

int main(){
	string a,b;
	getline(cin,a);
	getline(cin,b);
	substract(a,b);
	
	return 0;
}
