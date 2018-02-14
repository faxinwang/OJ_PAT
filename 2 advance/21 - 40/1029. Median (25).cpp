/*
1029. Median (25)
ʱ������
1000 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
CHEN, Yue
Given an increasing sequence S of N integers, the median is the number at the middle 
position. For example, the median of S1={11, 12, 13, 14} is 12, and the median of 
S2={9, 10, 15, 16, 17} is 15. The median of two sequences is defined to be the median 
of the nondecreasing sequence which contains all the elements of both sequences. For 
example, the median of S1 and S2 is 13.

Given two increasing sequences of integers, you are asked to find their median.

Input
Each input file contains one test case. Each case occupies 2 lines, each gives the 
information of a sequence. For each sequence, the first positive integer N (<=1000000) 
is the size of that sequence. Then N integers follow, separated by a space. It is 
guaranteed that all the integers are in the range of long int.

Output
For each test case you should output the median of the two given sequences in a line.

Sample Input
4 11 12 13 14
5 9 10 15 16 17

Sample Output
13

��Ŀ����:
����������������a��b�����������кϲ������λ��.

����˼·: 
���Ͻ�����a��b�н�С��һ����������c��(���ش洢)���������c�е���Ŀ�ﵽ��(m+n)/2
������������־�����λ��.
(�����ж��ֵķ�������д��һ�£�û����ȷд����)��
*/ 
#include<iostream>
#define maxn 1000005
typedef long long LL; 

LL a[maxn],b[maxn];

int main(){
  int m,n;
  scanf("%d",&m);
  for(int i=0; i<m;++i) scanf("%lld",a+i);
  scanf("%d",&n);
  for(int j=0; j<n;++j) scanf("%lld",b+j);
  
  //���һ�����е�����Ԫ����ȫС����һ�����У������ֱ��ȷ����λ����λ�� 
  int mid=(m+n-1)>>1;
  if(a[m-1] < b[0]){
  	if(mid < m){
  		printf("%lld",a[mid]); return 0;
	}else{
		printf("%lld",b[mid-m]); return 0;
	}
  }
  
  if(b[n-1] < a[0]){
  	if(mid < n){
		printf("%lld",b[mid]); return 0;
	}else{
		printf("%lld",a[mid-n]); return 0;
	} 
  }
  
  //�ϲ����� 
  int i,j,sum=m+n;
  for(i=0,j=0; i<m && j<n ;){
	if(a[i] < b[j]){
		++i; 
		if((i+j)*2 >= sum){
			printf("%lld",a[i-1]); return 0;
		}
	}else{
		++j;
		if((i+j)*2 >= sum){
			printf("%lld",b[j-1]); return 0;
		}
	}
  }
  
  if(i<m) printf("%lld",a[mid-n + i-1]);
  if(j<n) printf("%lld",b[mid-m + j-1]);
  
  return 0;
}
