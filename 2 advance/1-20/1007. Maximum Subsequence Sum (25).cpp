/*
1007. Maximum Subsequence Sum (25)
ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
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

��Ŀ���⣺
��������е�����Ӷκͣ��Լ�������Ӷε���β�����֣�������ڶ�����������±���С�ġ� 

����˼·��
�������뵽��������ѭ������ö�٣�ʱ�临�Ӷ�O(n^3) 
ʹ��ǰ׺�Ϳ��Խ�Ϊ����ѭ����ʱ�临�Ӷ�O(n^) 
����ʹ����һ��ѭ����˼·��һ·�ۼƣ�ÿ��һ���ͱȽϵ�ǰ���ۼƺ����¼�����ͣ� 
�������ĳ�ʼֵ�������ʾ 
1.���ۼƺʹ��ڵ�ǰ��¼������ʱ���͸��¼�¼�����ͣ�ͬʱ���������ӶεĽ����±�Ϊ
  ��ǰλ�ã����������ӶεĿ�ʼλ��(��ʼֵΪ0)Ϊ֮ǰ��¼��λ�á�
2.���ۼƺͱ�ΪС��0ʱ(˵����ǰλ���ϵ�����һ��Ϊ����),�ͽ��ۼƺ���Ϊ0��������ʼλ��
  ��Ϊ��ǰλ�õ���һλ�á� 
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
