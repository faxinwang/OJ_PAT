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
	//�ҵ�'E'��λ��,��ȡ��E��ߺ��ұߵ��ַ��� 
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
		cout<<string(-exp-1,'0'); 	//���-exp-1����
		cout<<str[1]; 				//�����һ������ 
		cout<<left.substr(3);		//���С������������ 
	}else{
		if(left[0]=='-')  cout<<"-";//�������λ 
		cout<<left[1];				//�����һλ���� 
		if(exp>=left.size()-3){		
			cout<<left.substr(3);
			cout<<string(exp-left.size()+3,'0');//��0 
		}else{
			cout<<left.substr(3,exp);//���С����ǰ�Ĳ��� 
			cout<<".";
			cout<<left.substr(3+exp);//���С�����Ĳ��� 
		} 
	}
	
	return 0;
}


