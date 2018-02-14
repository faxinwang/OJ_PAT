/*
1023. Have Fun with Numbers (20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers 
from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens 
to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a 
different permutation. Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, 
double a given number with k digits, you are to tell if the resulting number consists 
of only a permutation of the digits in the original number.

Input Specification:
Each input file contains one test case. Each case contains one positive integer 
with no more than 20 digits.

Output Specification:
For each test case, first print in a line "Yes" if doubling the input number gives a 
number that consists of only a permutation of the digits in the original number, or 
"No" if not. Then in the next line, print the doubled number.

Sample Input:
1234567899

Sample Output:
Yes
2469135798

题目大意：
给出一个不超过20位数字的正整数n，判断 m = 2*n 是否是由n的所有数字组成。

解题思路:
用string保存输入的数字n1，使用高精度算法计算出输入数字的两倍n2
然后对n1,n2排序，如果排序后n1==n2,则是满足题意的，输出Yes，否则输出No 
*/
#include<iostream>
#include<algorithm>
using namespace std;

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
