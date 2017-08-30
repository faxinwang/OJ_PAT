#include<iostream>
#include<string>
using namespace std;


int main(){
	string pwd,str;
	int n;
	cin>>pwd>>n;
	getchar();
	for(int i=1; ; ++i){
		getline(cin,str);//题目只说第一行没有空白字符，没说后面的密码不会包含空格
		if(str=="#") return 0;
		if(pwd == str){
			cout<<"Welcome in"<<endl;
			return 0;
		}else{
			cout<<"Wrong password: "<<str<<endl;
			if(i>=n){
				cout<<"Account locked"<<endl;
				return 0;
			}
		}
	}
	
	return 0;
}
