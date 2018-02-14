/*
1015. Reversible Primes (20)
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
A reversible prime in any number system is a prime whose "reverse" in that number 
system is also a prime. For example in the decimal system 73 is a reversible prime 
because its reverse 37 is also a prime.
Now given any two positive integers N (< 105) and D (1 < D <= 10), you are supposed 
to tell if N is a reversible prime with radix D.

Input Specification:
The input file consists of several test cases. Each case occupies a line which contains 
two integers N and D. The input is finished by a negative N.

Output Specification:
For each test case, print in one line "Yes" if N is a reversible prime with radix D, 
or "No" if not.

Sample Input:
73 10
23 2
23 10
-2

Sample Output:
Yes
Yes
No

��Ŀ���⣺
���ĳ������ת(��37��73)�������Ҳ����������Ƹ������ǿɷ�ת�ġ�
������������ڸ����Ľ���ϵͳ�µķ�ת�����Ƿ���������

����˼·��
1.�������
2.����ת���� 
3.���ַ�ת��
���Ǽ����� 
*/ 
#include<iostream>
#include<cstdio>
#define Max 100005
using namespace std;

char pri[Max];
void init_pri(){
	pri[0] = pri[1] = 1;
	for(int i=2;i*i<=Max;++i)
		if(pri[i]==0)
			for(int j=i*i; j<=Max;j+=i)
				pri[j] = 1;
}

int reverse(int N,int d){
	int rev = 0;
	while(N){
		rev = rev*d + N % d;
		N /= d;
	}
	return rev;
}

int main(){
	int N,D; //N <= 10^5, 1<D<=10
	init_pri();
//	printPri();
	
	while(cin>>N){
		if(N<0) break;
		scanf("%d",&D);
		if(pri[N]==1){
			cout<<"No"<<endl;
			continue;
		}
		int rev = reverse(N,D);
		if(pri[rev] == 0){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	
	return 0;
}
