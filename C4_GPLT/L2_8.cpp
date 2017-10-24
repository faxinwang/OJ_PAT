#include<iostream>
#include<string>
using namespace std;

int symmetric_len(string& str){
	int max_len=1;
	//先把长度当做奇数处理 
	for(int i=1;i<str.size()-1;++i){
		int cur_len = 1 ; 
		for(int j=1;i-j>=0 && i+j<str.size();++j,cur_len+=2)
			if(str[i-j] != str[i+j]) break;
		if(max_len < cur_len) max_len = cur_len;
	}
	//再把长度当做偶数处理 
	for(int i=1;i<str.size()-1;++i)
		if(str[i]==str[i+1]){
			int cur_len = 2;
			for(int j=1;i-j>=0 && i+j+1<str.size();++j,cur_len+=2)
				if(str[i-j]!=str[i+j+1]) break;
			if(max_len < cur_len) max_len = cur_len; 
		}

	return max_len;
}

int main(){
	string  str;
	getline(cin,str);
	cout<<symmetric_len(str)<<endl;
	
	return 0;
}
