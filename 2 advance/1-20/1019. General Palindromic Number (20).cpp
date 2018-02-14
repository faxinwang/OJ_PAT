/*
1019. General Palindromic Number (20)
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
A number that will be the same when it is written forwards or backwards is known 
as a Palindromic Number. For example, 1234321 is a palindromic number. All single 
digit numbers are palindromic numbers.Although palindromic numbers are most often 
considered in the decimal system, the concept of palindromicity can be applied to 
the natural numbers in any numeral system. Consider a number N > 0 in base b >= 2, 
where it is written in standard notation with k+1 digits ai as the sum of (aibi) for 
i from 0 to k. Here, as usual, 0 <= ai < b for all i and ak is non-zero. Then N is 
palindromic if and only if ai = ak-i for all i. Zero is written 0 in any base and 
is also palindromic by definition.

Given any non-negative decimal integer N and a base b, you are supposed to tell if N 
is a palindromic number in base b.

Input Specification:
Each input file contains one test case. Each case consists of two non-negative numbers 
N and b, where 0 <= N <= 109 is the decimal number and 2 <= b <= 109 is the base. The 
numbers are separated by a space.

Output Specification:
For each test case, first print in one line "Yes" if N is a palindromic number in 
base b, or "No" if not. Then in the next line, print N as the number in base b in the 
form "ak ak-1 ... a0". Notice that there must be no extra space at the end of output.

Sample Input 1:
27 2

Sample Output 1:
Yes
1 1 0 1 1

Sample Input 2:
121 5

Sample Output 2:
No
4 4 1

题目大意：
给定正整数N,问该数在基数为b的形式下是否为回文数，只有一位数的数字被视为回文数。
 
*/ 
#include<iostream>  
using namespace std;
const int maxn = 1e8+1;

int a[maxn];

void print(int k){
	printf("%d",a[k-1]);
	for(int i=k-2;i>0; --i){
		printf(" %d",a[i]);
	}
}

int main(){
	int N,b,k=1;
	cin>>N>>b;
	
	while(N){
		a[k++] = N % b;
		N /= b;
	}
	bool flag = 0;
	for(int i=1,len=k/2; i<=len; ++i){
		if(a[i] != a[k-i]){
			flag = 1;
			break;
		}
	}
	if(flag==0){
		cout<<"Yes"<<endl;
		print(k) ;
	}else{
		cout<<"No"<<endl; 
		print(k) ;
	}
	
	return 0;
}
