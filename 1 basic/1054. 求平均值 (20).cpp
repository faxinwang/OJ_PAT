#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
using namespace std;

bool valid(char ch){
	if(ch == '-') return true;
	if(ch == '.') return true;
	if('0'<=ch && ch<='9') return true;
	return false;
}

bool check(string& s){
	int dot=0;
	for(int i=0; i<s.size(); ++i){
		if(valid(s[i])){
			if(i>0 && s[i]=='-') return false;//'-'在数字中间 
			if(s[i]=='.') ++dot;
//			if(s[i]=='.' && i==0) return false;
//			if(s[i]=='.' && s[i-1]=='-') return false;
			if(dot>1) return false; //小数点不只一个 
		}else return false;
	}
	if(dot){
		//小数位数多余2位 
		if(s.substr(s.find('.')).size()>3) return false;
	}
	//取值不在[-1000,1000] 
	double t = atof(s.c_str());
	return -1000 <= t && t <= 1000;
}

int main(){
	int N,count=0;
	double sum=0;
	string num;
	
	cin>>N;
	while(N--){
		cin>>num;
		if(check(num)){
			++count;
			sum += atof(num.c_str());
		}else{
			cout<<"ERROR: "<<num<<" is not a legal number"<<endl;
		}
	}
	if(count==0){
		cout<<"The average of 0 numbers is Undefined"<<endl;
	}
	else if(count==1){
		cout<<"The average of 1 number is "
			<<fixed<<setprecision(2)
			<<sum<<endl;
	}else{
		cout<<"The average of "<<count<<" numbers is "
			<<fixed<<setprecision(2)
			<<sum/count<<endl; 
	}
	
	return 0;
} 
