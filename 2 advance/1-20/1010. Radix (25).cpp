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
	
	//����˵������������������Ҫ 
//	if(a=="0" && b=="0") return 2;
//	if(a=="1" && b=="1") return 2;

	Int aa=toDecimal(a,rad),bb=0;
	//���ֲ��ҵ�����λ�������������������+1(��Ȼ������ֲ���С��2)
	/*
	��ô���������Ƕ����أ����޵�Ȼ���ܳ�������һ�����ݵ�
	ʮ���ƴ�С����ΪN2��Ϊ0����£���С��λ������1��������Ľ���
	�ٳ���N1��ʮ�������˵Ļ�������ʮ�����µ���Ҳ�ͱ�N1��Ҫ��
	������Ҫ��
	*/
	Int minRB=maxNum(b)+1;
	Int midRB;
	Int maxRB=max(aa+1,minRB);
	//ʹ�ö��ֲ��ҡ� 
	while(minRB<=maxRB){
		midRB=minRB+(maxRB-minRB)/2;
		//compare to avoid overflow
		int rst=compare(b,midRB,aa);
		if(rst>0)
			maxRB=midRB-1;
		else if(rst<0)
			minRB=midRB+1;
		else{
			/*����ж�һ��������ת��Ϊ10���ƺ��Ƿ���ȣ�
			�����Ⱦͷ��ؼ���õ���midRB��
			����˵�������ڷ��������Ľ�����������0. 
				���� 1 10 1 10
			����õ��Ľ����2��Ȼ���������Ľ�����������������ȡ� 
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
