/*
1005. Spell It Right (20)
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
Given a non-negative integer N, your task is to compute the sum of all the digits of N, 
and output every digit of the sum in English.

Input Specification:
Each input file contains one test case. Each case occupies one line which contains 
an N (<= 10^100).

Output Specification:
For each test case, output in one line the digits of the sum in English words. There 
must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345

Sample Output:
one five

��Ŀ���⣺
��һ��λ���ﵽ10^100�η������ĸ���λ�ϵ�����֮�ͣ�Ȼ����Ӣ������͵�ÿһλ���� 
*/ 
#include<iostream>
#include<string>
using namespace std;

//calculate the sum of every digit of the num
int sum(string& str){
	int s=0;
	for(int i=0;i<str.size();++i){
		s+=str[i]-'0';
	}
	return s;
}

//transform the sum into string
string transform(int n){
	string num="";
	while(n){
		switch(n%10){
		case 0:num =" zero" + num;		break;
		case 1:num =" one" + num;		break;
		case 2:num =" two" + num;		break;
		case 3:num =" three" + num;		break;
		case 4:num =" four" + num;		break;
		case 5:num =" five" + num;		break;
		case 6:num =" six" + num;		break;
		case 7:num =" seven" + num;		break;
		case 8:num =" eight" + num;		break;
		case 9:num =" nine" + num;		break;
		}
		n/=10;
	}
	//if the sum == 0,then "zero" should be returned
	if(num.size()){
		return num.substr(1,num.size());
	}else{
		return "zero";
	}
	
}



int main(){
	string num;
	cin>>num;
	cout<<transform(sum(num))<<endl;
	
	return 0;
}
