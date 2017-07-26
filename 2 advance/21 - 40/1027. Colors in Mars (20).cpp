#include<iostream>
#include<algorithm>
using namespace std;

/*
题目大意:
输入10进制的r,g,b值，输出 13进制的r,g,b颜色表示.
输出格式：#rrggbb 如果某一个颜色分量只有一位数字，要在前面补上0,例如 #010203
解题思路:
题目很简单，写一个函数将10进制整数转换为13进制数字(用字符串表示).
*/
const string nums="0123456789ABC"; //注意用大写字母. 

string convert(int n){
	if(n==0) return "00";
	string s;
	while(n){
		s += nums[n%13];
		n /= 13;
	}
	if(s.size()==1) s = "0"+s;
	else reverse(s.begin(),s.end());
	return s;
}

int main(){
	int r,g,b;
	scanf("%d%d%d",&r,&g,&b);
	cout<<"#"<<convert(r)<<convert(g)<<convert(b)<<endl;
	
	return 0;
}
