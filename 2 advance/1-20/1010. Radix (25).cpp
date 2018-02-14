/*
1010. Radix (25)
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
Given a pair of positive integers, for example, 6 and 110, can this equation 
6 = 110 be true? The answer is "yes", if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N2, your task is to find the radix 
of one number while that of the other is given.

Input Specification:
Each input file contains one test case. Each case occupies a line which 
contains 4 positive integers:
N1 N2 tag radix
Here N1 and N2 each has no more than 10 digits. A digit is less than its radix 
and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9,
 and a-z represent the decimal numbers 10-35. The last number "radix" is the 
 radix of N1 if "tag" is 1, or of N2 if "tag" is 2.

Output Specification:
For each test case, print in one line the radix of the other number so that the 
equation N1 = N2 is true. If the equation is impossible, print "Impossible". If 
the solution is not unique, output the smallest possible radix.

Sample Input 1:
6 110 1 10

Sample Output 1:
2

Sample Input 2:
1 ab 1 2

Sample Output 2:
Impossible


*/ 
#include<iostream>
#include<cstring>
using namespace std;
typedef long long Int;
//It's interesting that using long long runs faster than long and int

Int toDecimal(string num,Int rad){
	Int s=0;//the result
	Int r=1;
	for(int i=num.size()-1;i>=0;--i){
		if(num[i]>='0' && num[i]<='9')
			s+=(num[i]-'0')*r;
		else
			s+=(num[i]-'a'+10)*r;
		r*=rad;
	}
	if(s<0)
		return -1;
	return s;
}

//to find the max number in the num
Int maxNum(string &a){
	char max=0;
	for(int i=0;i<a.size();++i)
		if(max<a[i]) max=a[i];
	if(max>='0' && max<='9')
		return max-'0';
	return (max-'a'+10);
}


Int max(Int a,Int b){
	return a>b?a:b;
}
//compare a and b
int compare(string b,Int rad,Int aa){
	Int bb=0;
	for(int i=0;i<b.size();++i){
		if(b[i]>='0' && b[i]<='9')
			bb=bb*rad+(b[i]-'0');
		else
			bb=bb*rad+(b[i]-'a'+10);
		if(bb>aa)//to avoid long long overflow
			return 1;
		else if(bb==aa)
			return 0;
	}
	return bb-aa;
}

Int findRadix(string &a,string &b,Int rad){
	if(a==b) return rad;
	
	//网上说的这两个条件都不需要 
//	if(a=="0" && b=="0") return 2;
//	if(a=="1" && b=="1") return 2;

	Int aa=toDecimal(a,rad),bb=0;
	//二分查找的下限为待计算的数中最大的数字+1(当然这个数字不能小于2)
	/*
	那么它的上限是多少呢，上限当然不能超过另外一个数据的
	十进制大小，因为N2不为0情况下，最小个位数都是1，如果它的进制
	再超过N1的十进制数了的话，它在十进制下的数也就比N1还要大，
	不符合要求。
	*/
	Int minRB=maxNum(b)+1;
	Int midRB;
	Int maxRB=max(aa+1,minRB);
	//使用二分查找。 
	while(minRB<=maxRB){
		midRB=minRB+(maxRB-minRB)/2;
		//compare to avoid overflow
		int rst=compare(b,midRB,aa);
		if(rst>0)
			maxRB=midRB-1;
		else if(rst<0)
			minRB=midRB+1;
		else{
			/*最后判断一下两个数转换为10进制后是否相等，
			如果相等就返回计算得到的midRB；
			否则说明不存在符合条件的进制数，返回0. 
				比如 1 10 1 10
			计算得到的结果是2，然而在这样的进制下两个数并不相等。 
			 */ 
			if(toDecimal(a,rad) == toDecimal(b,midRB)) return midRB;
			else return 0;
		}
			
	}
	return 0;
}

int main(){
	int tag;
	Int result,radix;
	string a,b;
	cin>>a>>b>>tag>>radix;
	if(tag==1){
		result=findRadix(a,b,radix);
	}else{
		result=findRadix(b,a,radix);
	}
		
	if(result==0){
		cout<<"Impossible"<<endl;
	}else{
		cout<<result<<endl;
	}
	return 0;
}
