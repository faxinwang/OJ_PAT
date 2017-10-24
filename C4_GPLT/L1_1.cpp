#include<iostream>
#include<cstdio>
using namespace std;


int main(){
	int b[30];
	b[0 ] =0;
	for(int i=1;i<=24;++i){
		int an=i + i*(i-1);
	//	if(an>1000) break;
		b[i] = an * 2 - 1;
		cout<<b[i]<<(i%10?" ":"\n");
	}
	int n;
	char ch;
	cin>>n>>ch;
	int line=1;
	while(b[line] < n) ++line;
	--line;
	for(int i=line;i>=1;--i){
		for(int k=1;k<=line-i;++k)
			putchar(' ');
		for(int j=1;j<=2*i-1;++j)
			putchar(ch);
		puts("");
	}
	for(int i=2;i<=line;++i){
		for(int k=1;k<=line-i;++k)
			putchar(' ');
		for(int j=1;j<=2*i-1;++j)
			putchar(ch);
		puts("");
	}
	printf("%d\n",n-b[line]);
}

