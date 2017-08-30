#include<cstdio> 
#include<iostream>
#include<string>
using namespace std;


int main(){
	int total=1,count=1,N;
	char ch;
	cin>>N>>ch;
	
	//找到需要使用的符号数量 
	while(total<=N){
		count+=2;
		total+=count*2; 
	}
	total -= count*2;
	count -= 2;
	
//	cout<<"Test:count="<<count<<endl;
	
	
	//打印上三角形 
	int space=-1;
	for(int i=count; i>=1; i-=2){
		cout<<string(++space,' ')<<string(i,ch)<<endl; 
	}
	//打印下三角形 
	for(int i=3; i<=count; i+=2) {
		cout<<string(--space,' ')<<string(i,ch)<<endl;
	}
	cout<<N-total<<endl;
	
	return 0;
}
