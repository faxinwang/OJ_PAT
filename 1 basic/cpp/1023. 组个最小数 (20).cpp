#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(){
	int a[10];
	string str="";
	for(int i=0;i<10;++i)
		scanf("%d",a+i);
		
	//找到第一个非零数 
	for(int i=1;i<10;++i){
		if(a[i]){
			str += i + '0';
			--a[i];
			break;
		}
	}
	for(int i=0;i<10;++i){
		while(a[i]--)
			str += i + '0';
	}
	
	cout<<str<<endl;
	
	return 0;
}
