/*
1001. A+B Format (20)
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
Calculate a + b and output the sum in standard format -- that is, the digits 
must be separated into groups of three by commas (unless there are less than four digits).

Input
Each input file contains one test case. Each case contains a pair of integers a 
and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output
For each test case, you should output the sum of a and b in one line. The sum 
must be written in the standard format.

Sample Input
-1000000 9

Sample Output
-999,991
*/ 
#include<iostream>
#include<string>
using namespace std;

int main(){
	int a,b,c,k=0;
	char ch;
	string s;
	cin>>a>>b;
	c=a+b;
//	cout<<c<<endl;
	if(c<0)	c=-c;
	while(c){
		ch=c%10;
		c/=10;
		ch+='0';
//		cout<<ch;
		s=ch+s;
		if(++k==3){
			k=0;
			s=','+s;
		}
	}
	if(s[0]==',')
		s=s.substr(1,s.size());
	if(a+b < 0)
		s='-'+s;
	else if(a+b==0)
		s="0";
		
	cout<<s<<endl;
	return 0;
}
