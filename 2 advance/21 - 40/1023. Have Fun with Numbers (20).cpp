#include<iostream>
#include<algorithm>
using namespace std;
/*
题目大意：
给出一个不超过20位数字的正整数n，判断 m = 2*n 是否是由n的所有数字组成。

解题思路:
用string保存输入的数字n1，使用高精度算法计算出输入数字的两倍n2
然后对n1,n2排序，如果排序后n1==n2,则是满足题意的，输出Yes，否则输出No 
*/ 

string doub(string num){
	if(num[0] == '0') return "0";
	string s;
	int carry=0;
	for(int i=num.size()-1; i>=0; --i){
		carry += (num[i] - '0') * 2;
		s += carry % 10 + '0';
		carry /= 10;
	}
	while(carry){
		s += carry % 10 +'0' ;
		carry /= 10;
	}
	reverse(s.begin(),s.end());
	return s;
}

int main(){
	string n1;
	cin>>n1;
	string n2 = doub(n1);
	string tmp = n2;
	
	sort(n1.begin(),n1.end());
	sort(n2.begin(),n2.end());	
	cout<<(n1==n2?"Yes":"No")<<endl;
	cout<<tmp<<endl;
	
	return 0;
}
