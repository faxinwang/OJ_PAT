/*
L2-008. 最长对称子串
时间限制
100 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
对给定的字符串，本题要求你输出最长对称子串的长度。例如，给定"Is PAT&TAP symmetric?"，
最长对称子串为"s PAT&TAP s"，于是你应该输出11。

输入格式：
输入在一行中给出长度不超过1000的非空字符串。

输出格式：
在一行中输出最长对称子串的长度。

输入样例：
Is PAT&TAP symmetric?

输出样例：
11

解题思路：
1.在字符串中，从1到n-2的位置上枚举以该位置为对称中心所得到的对称子串的长度.
2.在每个位置上分别考虑对称子串长度为偶合和奇数的情况。
3.在这些枚举值中返回最大的。 
*/ 
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
