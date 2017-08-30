#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(){
	int c0=0,c1=0,sum=0;
	char ch;
	while((ch=getchar()) && ch!='\n'){
		if(isalpha(ch)){
			sum += tolower(ch) - 'a' + 1;
		}
	}
	while(sum){
		if(sum%2) ++c1;
		else ++c0;
		sum >>= 1;
	}
	cout<<c0<<" "<<c1<<endl;
	
	return 0;
}
