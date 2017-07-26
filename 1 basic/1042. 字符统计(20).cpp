#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int count[200];

int main(){
	string str;
	getline(cin,str);
	for(int i=0,len=str.size(); i<len; ++i){
		if(isalpha(str[i]))
			++count[tolower(str[i])];
	}
	int max=0;
	for(int i=2;i<=200; ++i){
		if(count[max] < count[i]) max = i;
	}
	cout<<char(max)<<" "<<count[max]<<endl;
	
	return 0; 
} 
