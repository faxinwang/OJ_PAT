#include<cstdio> 
#include<iostream>
#include<string>
using namespace std;


int main(){
	int total=1,count=1,N;
	char ch;
	cin>>N>>ch;
	
	//�ҵ���Ҫʹ�õķ������� 
	while(total<=N){
		count+=2;
		total+=count*2; 
	}
	total -= count*2;
	count -= 2;
	
//	cout<<"Test:count="<<count<<endl;
	
	
	//��ӡ�������� 
	int space=-1;
	for(int i=count; i>=1; i-=2){
		cout<<string(++space,' ')<<string(i,ch)<<endl; 
	}
	//��ӡ�������� 
	for(int i=3; i<=count; i+=2) {
		cout<<string(--space,' ')<<string(i,ch)<<endl;
	}
	cout<<N-total<<endl;
	
	return 0;
}
