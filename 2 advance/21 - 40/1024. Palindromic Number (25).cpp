/*
1024. Palindromic Number (25)
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
A number that will be the same when it is written forwards or backwards is known as a 
Palindromic Number. For example, 1234321 is a palindromic number. All single digit 
numbers are palindromic numbers.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. 
First, the non-palindromic number is reversed and the result is added to the original 
number. If the result is not a palindromic number, this is repeated until it gives a 
palindromic number. For example, if we start from 67, we can obtain a palindromic number 
in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.

Given any positive integer N, you are supposed to find its paired palindromic number 
and the number of steps taken to find it.

Input Specification:
Each input file contains one test case. Each case consists of two positive numbers 
N and K, where N (<= 1010) is the initial numer and K (<= 100) is the maximum number 
of steps. The numbers are separated by a space.

Output Specification:
For each test case, output two numbers, one in each line. The first number is the 
paired palindromic number of N, and the second number is the number of steps taken 
to find the palindromic number. If the palindromic number is not found after K steps, 
just output the number obtained at the Kth step and K instead.

Sample Input 1:
67 3

Sample Output 1:
484
2

Sample Input 2:
69 3

Sample Output 2:
1353
3

题目大意：
定义一个操作: n = n + n逆序数字 
输入N(N<=10^10) ,K(K<=100),计算出N经过多少次上述操作后能得到一个回文数。
输出K和得到的回文数字。如果操作次数达到K次时还没有得到回文数，
则输出K次操作之后得到的数字和K 

解题思路:
input s
1. let tn = reversed(s)
2. if s == tn, then ouput the results and return.
3  let n = s + tn and go to step 1, repeat it for k times.

*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string reversed(string s){
	reverse(s.begin(),s.end());
	return s;
}

//高精度加法 返回a+b的字符串表示 
string add(string a,string b){
	int carry = 0;
	string res;
	for(int i=a.size()-1, j=b.size()-1; i>=0 || j>=0 ; --i,--j){
		if(i>=0) carry += a[i] - '0';
		if(j>=0) carry += b[i] - '0';
		res += carry%10 + '0' ;
		carry /= 10;
	}
	while(carry){
		res += carry % 10 + '0' ;
		carry /= 10;
	}
	reverse(res.begin(),res.end());
	return res;
}

int main(){
	int k;
	string n;
	cin>>n>>k;
	
	for(int i=0;i<k;++i){
		string tn = reversed(n);
		if(n == tn){
			cout<<n<<endl<<i<<endl;
			return 0; 
		}else{
			n = add(n,reversed(n));
		}
	}
	cout<<n<<endl<<k<<endl;
	
	return 0;
}
