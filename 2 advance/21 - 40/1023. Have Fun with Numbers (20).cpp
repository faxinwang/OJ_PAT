/*
1023. Have Fun with Numbers (20)
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

��Ŀ���⣺
����һ��������20λ���ֵ�������n���ж� m = 2*n �Ƿ�����n������������ɡ�

����˼·:
��string�������������n1��ʹ�ø߾����㷨������������ֵ�����n2
Ȼ���n1,n2������������n1==n2,������������ģ����Yes���������No 
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
