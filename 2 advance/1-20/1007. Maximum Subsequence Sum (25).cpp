/*
1007. Maximum Subsequence Sum (25)
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
Given a sequence of K integers { N1, N2, ..., NK }. A continuous subsequence 
is defined to be { Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. The Maximum 
Subsequence is the continuous subsequence which has the largest sum of its 
elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum 
subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the 
last numbers of the maximum subsequence.

Input Specification:
Each input file contains one test case. Each case occupies two lines. 
The first line contains a positive integer K (<= 10000). The second line 
contains K numbers, separated by a space.

Output Specification:
For each test case, output in one line the largest sum, together with the 
first and the last numbers of the maximum subsequence. The numbers must be 
separated by one space, but there must be no extra space at the end of a 
line. In case that the maximum subsequence is not unique, output the one 
with the smallest indices i and j (as shown by the sample case). If all 
the K numbers are negative, then its maximum sum is defined to be 0, and 
you are supposed to output the first and the last numbers of the whole 
sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21

Sample Output:
10 1 4

题目大意：
求给定序列的最大子段和，以及该最大子段的首尾的数字，如果存在多解情况，输出下标最小的。 

解题思路：
最容易想到的是三重循环暴力枚举，时间复杂度O(n^3) 
使用前缀和可以降为二重循环，时间复杂度O(n^) 
这里使用了一重循环，思路是一路累计，每走一步就比较当前的累计和与记录的最大和， 
个变量的初始值如代码所示 
1.当累计和大于当前记录的最大和时，就更新记录的最大和，同时更新最大和子段的结束下标为
  当前位置，更新最大和子段的开始位置(初始值为0)为之前记录的位置。
2.当累计和变为小于0时(说明当前位置上的数字一定为负数),就将累计和设为0，并将开始位置
  设为当前位置的下一位置。 
*/ 
#include<iostream>
using namespace std;


int maxSum(int *a,int n,int &first,int &last){
	//if the sequence is -1 0 -2,then the output should be 0 0 0,
	//so the maxsum should be initialized to -1
	int maxsum=-1,thissum=0,begin=0;
	first=last=a[0];
	for(int i=0;i<n;++i){
		thissum+=a[i];
		if(maxsum<thissum){
			maxsum=thissum;
			first=a[begin];
			last=a[i];
		}else if(thissum<0){
			thissum=0;
			begin=i+1;
		}
	}
	//If all the K numbers are negative, then its maximum sum is 
	//defined to be 0, and you are supposed to output the first and the 
	//last numbers of the whole sequence.
	if(maxsum==-1){
		maxsum=0;
		first=a[0];
		last=a[n-1];
	}
	return maxsum;
}

int main(){
	int K,a[10001];
	int maxsum,first,last;
	cin>>K;
	for(int i=0;i<K;++i){
		scanf("%d",a+i);
	}
	maxsum=maxSum(a,K,first,last);
	cout<<maxsum<<' '<<first<<' '<<last<<endl;
		
	return 0;
}
