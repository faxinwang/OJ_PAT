#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int strToNum(string& s){
	int n=0;
	for(int i=1;i<s.size();++i){
		n = n * 10 + s[i] - '0';
	}
	return s[0]=='-'? -n:n;
}

int main(){
	string str,left,right;
	int exp;
	cin>>str;
	//找到'E'的位置,并取出E左边和右边的字符串 
	for(int i=0,len=str.size();i<len;++i) {
		if(str[i]=='E'){
			 left = str.substr(0,i);
			 right= str.substr(i+1);
			 break;
		}
	}
	exp = strToNum(right);
	
	if(exp<0){
		if(left[0]=='-') cout<<"-";
		cout<<"0.";
		cout<<string(-exp-1,'0'); 	//输出-exp-1个零
		cout<<str[1]; 				//输出第一个数字 
		cout<<left.substr(3);		//输出小数点后面的数字 
	}else{
		if(left[0]=='-')  cout<<"-";//输出符号位 
		cout<<left[1];				//输出第一位数字 
		if(exp>=left.size()-3){		
			cout<<left.substr(3);
			cout<<string(exp-left.size()+3,'0');//补0 
		}else{
			cout<<left.substr(3,exp);//输出小数点前的部分 
			cout<<".";
			cout<<left.substr(3+exp);//输出小数点后的部分 
		} 
	}
	
	return 0;
}


